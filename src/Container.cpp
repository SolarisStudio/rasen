#include "Container.h"
#include <iostream>

void Container::update(float dt) {
    auto draw_x = this->spacing(); // container_location.x;
    auto draw_y = draw_x; // container_location.y;
    for (auto& child: m_children) {
        child->set_location(draw_x, draw_y);
        child->update(dt);
        draw_y += child->height() + this->spacing() + this->margin();
    }
}

void Container::draw() {
    auto container_location = this->location();
    auto container_size = this->get_size();
    auto draw_x = container_location.x;
    auto draw_y = container_location.y;
    DrawRectangle(draw_x, draw_y, container_size.x, container_size.y, m_color);
    for (auto& child: m_children) {
        child->draw();
    }
}

std::vector<Widget*> Container::children() {
    return m_children;
};

void Container::add(Widget* child) {
    child->set_parent(this);
    m_children.push_back(child);
};

Color Container::background_color() {
    return m_color;
}

void Container::set_background_color(Color& color) {
    m_color = color;
}

const Color Container::DEFAULT_BACKGROUND_COLOR = Color{0xab, 0xab, 0xab, 0xFF};
