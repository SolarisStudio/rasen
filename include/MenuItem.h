#pragma once
#include <Event.h>
#include <string>
#include <memory>
#include <Menu.h>

class MenuItem : public EventWidget<MenuItem> {
  public:
    MenuItem(): m_text{""} {};
    ~MenuItem() {};

    void update(float dt) override;
    void draw() override;

    WIDGET_CONSTRUCT(MenuItem);
    WIDGET_CONSTRUCT_PARENT(MenuItem);
    WIDGET_ALLOWS_TEXT;

  protected:

  private:
    std::string m_text;
    bool m_is_checked = false;
    unsigned int m_min_width = 120;
};
