#pragma once

#include <Container.h>

#include <memory>
#include <string>

class Window : public Container {
    public:
        Window():
            m_title {""},
            m_resizable { false } {
            this->set_size(Window::DEFAULT_WIDTH, Window::DEFAULT_HEIGHT);
        };
        virtual ~Window() {};

        static std::unique_ptr<Window> construct();
        static const unsigned int DEFAULT_WIDTH;
        static const unsigned int DEFAULT_HEIGHT;
        static const unsigned int DEFAULT_X;
        static const unsigned int DEFAULT_Y;

        void set_title(const char*);
        void set_title(std::string&);

        void set_resizable(bool value) { m_resizable = value; };
        bool resizable() { return m_resizable; }

        void update(float) override;
        void draw() override;

    protected:

    private:
        std::string m_title;
        bool m_resizable;
};


