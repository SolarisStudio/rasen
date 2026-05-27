#include "Menu.h"

Menu::Menu(){
  this->set_margin(4);
  this->set_spacing(2);
}

void Menu::update(float dt){
  if(!m_is_open) return;

  unsigned int current_x = this->x() + this->margin();
  unsigned int current_y = this->y() + this->margin();

  for(Widget* child : children()){
    child->set_location(current_x, current_y);
    child->update(dt);
    current_y += child->height() + this->spacing();
  }

  unsigned int final_height = (current_y - this->y()) + this->margin();
  this->set_size(m_min_width, final_height);
}

void Menu::draw() {
  if(!m_is_open) return;

  DrawUtils::DrawRectangleOutset(this->bounding_rect(), 2, LIGHTGRAY);
  for (Widget *child : children()) {
    child->draw();
  }
}
