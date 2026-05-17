#include "MenuBar.h"

MenuBar::MenuBar() {
  this->set_margin(4);
  this->set_spacing(10);
}

void MenuBar::update(float dt) {
  unsigned int screen_width = GetScreenWidth();

  this->set_location(0, 0);
  this->set_size(screen_width, m_bar_height);

  unsigned int current_x = this->margin();
  unsigned int center_y_offset = this->margin();

  for (Widget *child : children()) {
    if (child->height() < m_bar_height) {
      center_y_offset = (m_bar_height - child->height()) / 2;
    }

    child->set_location(current_x, center_y_offset);

    child->update(dt);
    current_x += child->width() + this->spacing();
  }
}

void MenuBar::draw() {
  DrawRectangleRec(this->bounding_rect(), LIGHTGRAY);
  DrawLine(0, m_bar_height, GetScreenWidth(), m_bar_height, LIGHTGRAY);
  for (Widget *child : children()) {
    child->draw();
  }
}
