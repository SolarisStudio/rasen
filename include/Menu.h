#pragma once
#include <Event.h>
#include <string>
#include <memory>
#include <UIConstants.h>

class Menu : public Container {
  public: 
    Menu();
    ~Menu(){};

    void update(float) override;
    void draw() override;

    WIDGET_CONSTRUCT(Menu);
    WIDGET_CONSTRUCT_PARENT(Menu);
    WIDGET_ALLOWS_TEXT;

    std::string m_text;
    bool is_open(){ return m_is_open;};
    void open(){m_is_open = true;}
    void close(){ m_is_open = false;}
    void toggle(){ m_is_open = !m_is_open;}

  protected:

  private: 
    unsigned int  m_max_height = 30;
    bool m_is_open = false;
    bool is_hovered = false;
    unsigned int m_min_width = 120;

    Rectangle m_dropdown_rect;
};
