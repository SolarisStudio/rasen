#include <iostream>

#include <Application.h>
#include <Window.h>
#include <Button.h>
#include <CheckBox.h>

int main(int argc, char** argv) {
    auto window = Window::construct();
    window->set_size(900, 600);
    window->set_title("Hello, from c++");

    auto btn = Button::construct();
    btn->set_text("Hello");
    btn->on_click([](auto event) {
        std::cout << "Hello" << std::endl;
    });
    window->add(static_cast<Widget*>(btn.get()));

    auto btn2 = CheckBox::construct();

    window->add(static_cast<Widget*>(btn2.get()));

    return Application::run(argc, argv);
}
