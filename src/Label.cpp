#include "Label.h"

void Label::update(float dt) {
    if (m_text.length() == 0) {
        m_text = " ";
    }

    auto spacing = this->spacing();
    Vector2 textSize = MeasureTextEx(GetFontDefault(), m_text.c_str(), UIConstants::FONT_SIZE, spacing);
    auto width = textSize.x + (UIConstants::PADDING_X * 2);
    auto height = textSize.y + (UIConstants::PADDING_Y * 2);
    this->set_size(width, height);
}

void Label::draw() {
    auto rect = this->bounding_rect();
    auto spacing = this->spacing();
    // DrawUtils::DrawRectangleLinesOutset(rect, 1, RED);
    Vector2 text_location = {
        rect.x + spacing,
        rect.y + UIConstants::PADDING_Y
    };
    auto font_size = UIConstants::FONT_SIZE;

    auto color = LIGHTGRAY;
    auto thick = 2;
    DrawTextEx(GetFontDefault(), m_text.c_str(), text_location, font_size, spacing, BLACK);
}
