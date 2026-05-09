#include <memory>
#include "Application.h"
#include "Window.h"

#include <iostream>

std::unique_ptr<Window> Window::construct() {
    auto window = std::make_unique<Window>();
    auto raw = window.get();
    Application::append(raw);
    return window;
}

void Window::update([[maybe_unused]] float dt) {

    for (Widget* child: children()) {
        child->update(dt);
    }
}

void Window::draw() {

    auto flag = (int)FLAG_MSAA_4X_HINT;
    if (m_resizable) {
        flag |= (int)FLAG_WINDOW_RESIZABLE;
    }

    SetConfigFlags(flag);

    auto window_size = this->get_size();
    InitWindow(window_size.x, window_size.y, m_title.c_str());
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        auto dt = GetFrameTime();
        auto w = GetScreenWidth();
        auto h = GetScreenHeight();
        this->set_size(w, h);
        Container::update(dt);
        BeginDrawing();
            Container::draw();
            for (Widget* child: children()) {
                child->draw();
            }
        EndDrawing();
    }
}

void Window::set_title(const char * title) {
    m_title = std::string(title);
}

void Window::set_title(std::string& title) {
    m_title = title;
}


const unsigned int Window::DEFAULT_WIDTH = 600;
const unsigned int Window::DEFAULT_HEIGHT = 400;;
const unsigned int Window::DEFAULT_X = 150;
const unsigned int Window::DEFAULT_Y = 150;
