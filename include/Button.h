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

        void set_text(const char*);
        void set_text(std::string&);
        std::string text();

        static std::unique_ptr<Button> construct();
        WIDGET_CONSTRUCT(Button);


    protected:

    private:
        std::string m_text;
        bool m_hovered = false;
};


