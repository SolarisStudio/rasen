#include "ComboBox.h"

void ComboBox::update(float dt) {
    if (m_options.size() == 0) {
        m_options.push_back(" ");
        m_selected_index = 0;
    }

    auto max_text = std::string("");
    for (auto option_text: m_options) {
        if (option_text.length() > max_text.length())
            max_text = option_text;
    }

    Vector2 textSize = MeasureTextEx(GetFontDefault(), max_text.c_str(), UIConstants::FONT_SIZE, this->spacing());
    auto width = textSize.x + (UIConstants::PADDING_X * 2);
    auto height = textSize.y + (UIConstants::PADDING_Y * 2);
    this->set_size(width + this->spacing() * 2, height);
    //
}

void ComboBox::draw() {
    auto rect = this->bounding_rect();
    auto mouse_pos = GetMousePosition();
    auto hovered = CheckCollisionPointRec(mouse_pos, rect);

    auto bg_color = ColorBrightness(GRAY, 0.55);
    DrawUtils::DrawRectangleInset(rect, 2, WHITE);
    if (hovered) {
        DrawRectangleLinesEx(rect, 1, UIConstants::HIGHLIGHT_COLOR);
    }

    auto selected_option = m_options[m_selected_index];
    Vector2 text_location = {
        rect.x + this->spacing() * 2,
        rect.y + UIConstants::PADDING_Y
    };


    auto font_size = UIConstants::FONT_SIZE;
    auto spacing = this->spacing();
    auto color = LIGHTGRAY;
    DrawTextEx(GetFontDefault(), selected_option.c_str(), text_location, font_size, spacing, BLACK);

    float triangle_size = 5.0f;
    auto tri_y = rect.y + rect.height / 2;
    auto tri_x = rect.x + rect.width - triangle_size - spacing * 2;
    Vector2 v1 = { tri_x - triangle_size, tri_y - triangle_size }; // Top Left
    Vector2 v2 = { tri_x + triangle_size, tri_y - triangle_size }; // Top Right
    Vector2 v3 = { tri_x, tri_y + 2 };                            // Bottom Tip (near track)


    DrawUtils::DrawTriangleFilledOutset(v1, v2, v3, 2.0f, BLACK);



    if (m_show_options) {
        auto options_count =  m_options.size();
        auto options_rect = Rectangle {
            rect.x,
            rect.y + rect.height + spacing,
            rect.width,
            rect.height * options_count + spacing * options_count - 1
        };

        DrawUtils::DrawRectangleInset(
            Rectangle {
                options_rect.x + spacing,
                options_rect.y + spacing,
                options_rect.width,
                options_rect.height
            },
            0,
            ColorBrightness(GRAY, -0.35)
        );

        DrawUtils::DrawRectangleInset(options_rect, 0, WHITE);

        Vector2 option_text_location = {
            options_rect.x + spacing * 2,
            options_rect.y + UIConstants::PADDING_Y
        };

        auto text_bounding = Rectangle {
            options_rect.x,
            options_rect.y,
            options_rect.width,
            options_rect.height / options_count
        };

        Event<ComboBox> e(mouse_pos, this);
        for (int i = 0; i < options_count; ++i) {
            auto option = m_options[i];

            auto hovered_text = CheckCollisionPointRec(mouse_pos, text_bounding);

            auto text_color = BLACK;
            if (hovered_text) {
                DrawRectangleRec(text_bounding, UIConstants::HIGHLIGHT_COLOR);
                text_color = WHITE;
            }

            DrawTextEx(GetFontDefault(), option.c_str(), option_text_location, font_size, spacing, text_color);
            option_text_location.y += options_rect.height / options_count;
            text_bounding.y += options_rect.height / options_count;

            if (hovered_text && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                m_selected_index = i;
                auto select = this->on_select();
                if (select != nullptr) {
                    select(e);
                }
            }

            if (i < options_count - 1)
                DrawLine(
                   rect.x,
                   option_text_location.y - spacing * 3,
                   rect.x + rect.width,
                   option_text_location.y - spacing * 3,
                   ColorBrightness(GRAY, -0.35)
                );


        }
    }

    if (hovered && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        m_show_options = true;
    if (!hovered && (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        m_show_options = false;

}

void ComboBox::set_options(std::vector<std::string>& options) {
    if (!m_options_initialized) {
        m_options.clear();
        m_options_initialized = true;
    }

    for (auto option: options) {
        m_options.push_back(option);
    }
}

void ComboBox::set_options(std::vector<std::string> options) {
    if (!m_options_initialized) {
        m_options.clear();
        m_options_initialized = true;
    }

    for (auto option: options) {
        m_options.push_back(option);
    }
}

std::vector<std::string> ComboBox::options() { return m_options; }

void ComboBox::add_option(std::string& option) {
    if (!m_options_initialized) {
        m_options.clear();
        m_options_initialized = true;
    }
    m_options.push_back(option);
}

void ComboBox::add_option(char* option) {
    if (!m_options_initialized) {
        m_options.clear();
        m_options_initialized = true;
    }
    m_options.push_back(std::string(option));
}

