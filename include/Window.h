#pragma once

#include <Container.h>
#include <Desktop.h>
#include <memory>
#include <string>

class Window : public Container {
    public:
        Window():
            m_title {""},
            m_resizable { false } {
            this->m_desktop = std::make_unique<Desktop>();
            this->set_size(Window::DEFAULT_WIDTH, Window::DEFAULT_HEIGHT);
        };

        ~Window() {};

        static std::unique_ptr<Window> construct();
        static const unsigned int DEFAULT_WIDTH;
        static const unsigned int DEFAULT_HEIGHT;
        static const unsigned int DEFAULT_X;
        static const unsigned int DEFAULT_Y;

        void set_title(const char*);
        void set_title(std::string&);

        void set_resizable(bool value) { m_resizable = value; };
        bool resizable() { return m_resizable; }
        Desktop* desktop() { return m_desktop.get(); }

        void update(float) override;
        void draw() override;

    protected:

    private:
        std::string m_title;
        bool m_resizable;
        std::unique_ptr<Desktop> m_desktop;
};


