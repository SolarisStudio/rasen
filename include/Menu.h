#pragma once
#include <Event.h>
#include <string>
#include <memory>

class Menu : public Container {
  public: 
    Menu();
    ~Menu(){};

    void update(float) override;
    void draw() override;

    WIDGET_CONSTRUCT(Menu);
    WIDGET_CONSTRUCT_PARENT(Menu);

    std::string m_text;
    bool is_open(){ return m_is_open;};
    void open(Vector2 pos){
      m_is_open = true;
      this->set_location(pos);
    }
    void close(){ m_is_open = false;}
    void toggle(Vector2 pos){
      if(m_is_open) close(); 
      else open(pos);
    }

  protected:

  private: 
    unsigned int  m_max_height = 30;
    bool m_is_open = false;
    unsigned int m_min_width = 120;
};
