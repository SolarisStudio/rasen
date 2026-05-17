#pragma once

#include <Event.h>
#include <string>
#include <memory>

class MenuBar : public Container {
   public:
       MenuBar();
       ~MenuBar() {};

       void update(float) override;
       void draw() override;


       WIDGET_CONSTRUCT(MenuBar);
       WIDGET_CONSTRUCT_PARENT(MenuBar);
       std::string m_text;
       bool on_click = false;

   protected:

   private:
       unsigned int m_bar_height = 30;// I read that MenuBar is usually a fixed height
};

