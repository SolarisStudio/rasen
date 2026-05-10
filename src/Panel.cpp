#include "Panel.h"
#include <cmath>
#include <iostream>

void Panel::update(float dt) {
    // Container::update(dt);
    auto spacing = this->spacing();
    auto x = this->x() + spacing * 2;
    auto y = this->y() + spacing;

    auto w = 0;
    auto h = 0;

    auto children = this->children();
    if (m_layout == Layout::HORIZONTAL) {
        for (auto child : children) {
            child->update(dt);
            auto child_spacing = child->spacing();
            child->set_location(x, y + child_spacing - 1);

            auto child_width = child->width();

            x += child_width + spacing - 1;
            //w = x;
            h = std::max(
                    static_cast<int>(h),
                    static_cast<int>(child->height() + child_spacing * 2 + spacing * 2)
                );
            // x += child->width() + child->spacing();
        }

        w = x - this->x() + spacing;
    } else if (m_layout == Layout::VERTICAL) {
        for (auto child : children) {
            child->update(dt);
            auto child_spacing = child->spacing();
            child->set_location(x, y + child_spacing - 1);

            auto child_height = child->height();

            y += child_height + spacing - 1;
            //w = x;
            w = std::max(
                    static_cast<int>(w),
                    static_cast<int>(child->width() + child_spacing * 2 + spacing * 2)
                );
            // x += child->width() + child->spacing();
        }

        h = y - this->y() + spacing * 2;
    }

    this->set_size(w, h);
}

void Panel::draw() {

    auto border_color = ColorBrightness(GRAY, 0.55);
    if (m_border == Border::INSET) {
        DrawUtils::DrawRectangleLinesInset(this->bounding_rect(), 1, border_color);
    } else if (m_border == Border::OUTSET) {
        DrawUtils::DrawRectangleLinesOutset(this->bounding_rect(), 1, border_color);
    } else if (m_border == Border::LINE) {
        DrawUtils::DrawRectangleLinesInset(this->bounding_rect(), 0, border_color);
    } else if (m_border == Border::OUTSET_BEVEL) {
        DrawUtils::DrawRectangleOutset(this->bounding_rect(), 2, border_color);
    }  else if (m_border == Border::INSET_BEVEL) {
        DrawUtils::DrawRectangleInset(this->bounding_rect(), 2, border_color);
    }



    for (auto child : children()) {
        child->draw();
    }
}
