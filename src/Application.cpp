#include "Application.h"


std::vector<Window*> Application::m_windows;

void Application::append(Window* window) {
    Application::m_windows.push_back(window);
}

int Application::run(int argc, char** argv) {
    enum class ExitCode {
        SUCCESS = 0,
        FAILURE
    };

    for (Window* window: m_windows) {
        window->update(0);
        window->draw();
    }

    return static_cast<int>(ExitCode::SUCCESS);
}
