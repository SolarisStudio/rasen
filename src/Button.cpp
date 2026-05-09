#include "Button.h"

void Button::update(float) {

    if (m_text.length() == 0) {
        this->set_text(" ");
    }

    Vector2 textSize = MeasureTextEx(GetFontDefault(), m_text.c_str(), UIConstants::FONT_SIZE, this->spacing());
    auto width = textSize.x + (UIConstants::PADDING_X * 2);
    auto height = textSize.y + (UIConstants::PADDING_Y * 2);
    this->set_size(width, height);
    m_hovered = CheckCollisionPointRec(GetMousePosition(), this->bounding_rect());
}


void Button::draw() {
    auto rect = this->bounding_rect();
    Vector2 text_location = {
        rect.x + UIConstants::PADDING_X,
        rect.y + UIConstants::PADDING_Y
    };
    // DrawRectanglePro(rect, {0,0}, 0, GetColor(0xaaaaaa));
    DrawUtils::DrawRectangleOutset(rect, 2, LIGHTGRAY);
    auto font_size = UIConstants::FONT_SIZE;
    auto spacing = this->spacing();
    auto color = LIGHTGRAY;
    auto thick = 2;


    auto mouse_pos = GetMousePosition();
    Event<Button> e(mouse_pos, this);


    static int click_count = 1;
    if (m_hovered && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        DrawUtils::DrawRectangleInset(rect, thick, color);
        text_location.y += 2;

        auto click = this->on_click();
        if (click != nullptr && click_count > 0) {
            click(e);
            click_count--;
        }
    } else {
        DrawUtils::DrawRectangleOutset(rect, thick, color);
    }

    if (m_hovered && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        click_count = 1;
    }

    auto text_color = BLACK;
    if (m_hovered) {
        DrawRectangleLinesEx(rect, 1, ColorBrightness(color, -0.7f));
        text_color = ColorBrightness(text_color, 0.25f);
        auto hover = this->on_hover();
        if (hover != nullptr) {
            hover(e);
        }
    }

    DrawTextEx(GetFontDefault(), m_text.c_str(), text_location, font_size, spacing, text_color);
}


void Button::set_text(const char* text) {
    m_text = std::string(text);
}

void Button::set_text(std::string& text) {
    m_text = text;
}

std::string Button::text() {
    return m_text;
}
