#include <Desktop.h>

void Desktop::update(float dt) {
    Container::update(dt);
    auto w = GetScreenWidth();
    auto h = GetScreenHeight();
    this->set_location(0,0);
    this->set_size(w, h);
    Color color = Desktop::DEFAULT_BACKGROUND_COLOR;
    this->set_background_color(color);
}

void Desktop::draw() {
    auto rect = this->bounding_rect();
    auto color = this->background_color();
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, color);
    if (m_draw != nullptr)
        m_draw(rect);
    Container::draw();
}


const Color Desktop::DEFAULT_BACKGROUND_COLOR = Color{0xab, 0xab, 0xab, 0xFF};