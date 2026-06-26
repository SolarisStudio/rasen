#include "Menu.h"
#include "UIConstants.h"
#include "DrawUtils.h"

Menu::Menu(){
  this->set_spacing(2);
}

void Menu::update(float dt){
  if(m_text.empty()) m_text = "";
  Vector2 textSize = MeasureTextEx(GetFontDefault(), m_text.c_str(), UIConstants::FONT_SIZE, this->spacing());
  unsigned int label_width  = textSize.x + (UIConstants::PADDING_X * 2);
  unsigned int label_height = textSize.y + (UIConstants::PADDING_Y * 2);
  this->set_size(label_width, label_height);

  auto mouse_pos = GetMousePosition();
  is_hovered = CheckCollisionPointRec(mouse_pos, this->bounding_rect());

  if(is_hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    toggle();
  }

  if(m_is_open && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
    if(!is_hovered && !CheckCollisionPointRec(mouse_pos, m_dropdown_rect)){
      close();
    }
  }

  if(!m_is_open) return;

  unsigned int current_x = this->x();
  unsigned int current_y = this->y() + this->height();


  unsigned int max_child_width = m_min_width;
  for(Widget *child: children()){
    child->set_location(current_x, current_y);
    child->update(dt);
    if(child->width() > max_child_width){
      max_child_width = child->width();
    }
    current_y += child->height();
  }

  for(Widget *child: children()){
    child->set_width(max_child_width);
  }

  unsigned int final_height = current_y - (this->y() + this->height());
  m_dropdown_rect = { (float)this->x(), (float)(this->y() + this->height()),
    (float)max_child_width, (float)final_height };

}

void Menu::draw() {
  auto rect = this->bounding_rect();

  if (is_hovered || m_is_open) {
    DrawRectangleRec(rect, UIConstants::HIGHLIGHT_COLOR);
    DrawTextEx(GetFontDefault(), m_text.c_str(), {rect.x + UIConstants::PADDING_X,
	  rect.y + UIConstants::PADDING_Y}, UIConstants::FONT_SIZE, this->spacing(), WHITE);
  } else {
    DrawTextEx(GetFontDefault(), m_text.c_str(), {rect.x + UIConstants::PADDING_X,
	rect.y + UIConstants::PADDING_Y}, UIConstants::FONT_SIZE, this->spacing(), BLACK);
  }

  if(!m_is_open) return;

  DrawUtils::DrawRectangleOutset(m_dropdown_rect, 2, LIGHTGRAY);
  for (Widget *child : children()) {
    child->draw();
  }
}
