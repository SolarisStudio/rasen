#include "CheckBox.h"

void CheckBox::update(float dt) {
    Vector2 textSize = MeasureTextEx(GetFontDefault(), m_label.c_str(), UIConstants::FONT_SIZE, this->spacing());
    auto width = textSize.x + (UIConstants::PADDING_X * 2) + UIConstants::CHECKBOX_RADIUS * 2;
    auto height = textSize.y + (UIConstants::PADDING_Y * 2);
    this->set_size(width, height);

    auto rect = this->bounding_rect();
    Vector2 text_location = {
        rect.x + UIConstants::PADDING_X + UIConstants::CHECKBOX_RADIUS * 2,
        rect.y + UIConstants::PADDING_Y
    };


    auto spacing = this->spacing();
    auto check_box_center = Vector2{
        text_location.x - UIConstants::CHECKBOX_RADIUS * 2 + spacing,
        text_location.y + spacing * 2
    };

    auto rect2 = Rectangle{
                    text_location.x, rect.y,
                    this->width() - UIConstants::CHECKBOX_RADIUS * 2 , this->height()
                };
    int diff_x = rect2.x - rect.x;
    rect2.width -= diff_x ;


    auto mouse_pos = GetMousePosition();
    m_hovered = CheckCollisionPointCircle(mouse_pos, check_box_center, UIConstants::CHECKBOX_RADIUS) ||
                CheckCollisionPointRec(mouse_pos, rect2);
};

void CheckBox::draw() {
    auto rect = this->bounding_rect();
    Vector2 text_location = {
        rect.x + UIConstants::PADDING_X + UIConstants::CHECKBOX_RADIUS * 2,
        rect.y + UIConstants::PADDING_Y
    };


    auto spacing = this->spacing();
    auto check_box_center = Vector2{
        text_location.x - UIConstants::CHECKBOX_RADIUS * 2 + spacing,
        text_location.y + spacing * 2
    };

    DrawUtils::DrawCircleInset(check_box_center, UIConstants::CHECKBOX_RADIUS, 3.0f, LIGHTGRAY);


    static int event_count = 1;
    auto mouse_pos = GetMousePosition();
    if (m_hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

        auto check = this->on_check();
        if (event_count > 0) {
            this->m_checked = !this->m_checked;
            Event<CheckBox> e(mouse_pos, this, this->m_checked);
            if (check != nullptr ) {
                check(e);
                event_count--;
            }

            event_count--;
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        event_count = 1;
    }

    if (m_checked) {
        DrawUtils::DrawCircleOutset(check_box_center, UIConstants::CHECKBOX_RADIUS / 2, 5.0f, BLACK);
    }

    auto font_size = UIConstants::FONT_SIZE;
    DrawTextEx(GetFontDefault(), m_label.c_str(), text_location, font_size, spacing, BLACK);


};


void CheckBox::set_text(const char* text) {
    this->m_label = std::string(text);
}

void CheckBox::set_text(std::string& text) {
    this->m_label = text;
}

std::string CheckBox::text() {
    return this->m_label;
}
