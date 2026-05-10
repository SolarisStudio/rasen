#pragma once

#include <Event.h>
#include <string>
#include <memory>


class Button : public EventWidget<Button> {
    public:
        Button(): m_text{""} {};
        ~Button() {};

        void update(float);
        void draw();


        WIDGET_CONSTRUCT(Button);
        WIDGET_CONSTRUCT_PARENT(Button);
        WIDGET_ALLOWS_TEXT;


    protected:

    private:
        std::string m_text;
        bool m_hovered = false;
};


