#include "MenuItem.h"
#include "UIConstants.h"
#include "DrawUtils.h"

void MenuItem::update(float dt) {
  if (m_text.empty()) {
    m_text = " ";
  }

  Vector2 textSize = MeasureTextEx(GetFontDefault(), m_text.c_str(), UIConstants::FONT_SIZE, this->spacing());

  auto target_width = textSize.x + (UIConstants::PADDING_X * 2);
  auto height = textSize.y + (UIConstants::PADDING_Y * 2);

  if (target_width < m_min_width) {
    target_width = m_min_width;
  }

  if (this->width() > target_width) {
    target_width = this->width();
  }

  this->set_size(target_width, height);
}

void MenuItem::draw() {
  auto rect = this->bounding_rect();
  auto mouse_pos = GetMousePosition();

  bool hovered = CheckCollisionPointRec(mouse_pos, rect);

  if (hovered) {
    DrawRectangleRec(rect, UIConstants::HIGHLIGHT_COLOR);
  }

  Vector2 text_location = {
    rect.x + UIConstants::PADDING_X,
    rect.y + UIConstants::PADDING_Y
  };

  Color text_color = hovered ? WHITE : BLACK;
  DrawTextEx(GetFontDefault(), m_text.c_str(), text_location,
	  UIConstants::FONT_SIZE, this->spacing(), text_color);

  if (hovered && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
    auto click = this->on_click();
    if (click != nullptr) {
      Event<MenuItem> e(mouse_pos, this);
      click(e);
    }

    if (parent() != nullptr) {
      Menu* parentMenu = dynamic_cast<Menu*>(parent());
      if (parentMenu) {
	parentMenu->close();
      }
    }
  }
}
