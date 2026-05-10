#include <iostream>

#include <Application.h>
#include <Window.h>
#include <Button.h>
#include <CheckBox.h>
#include <Slider.h>
#include <Panel.h>
#include <ComboBox.h>
#include <Label.h>

#include <Border.h>

int main(int argc, char** argv) {
    auto window = Window::construct();
    window->set_size(900, 600);
    window->set_title("Hello, from c++");
    // window->set_resizable(true);

    auto panel = Panel::construct(window);
    panel->set_border(Border::OUTSET_BEVEL);
    panel->set_layout(Layout::HORIZONTAL);

    auto btn0 = Button::construct(panel);
    btn0->set_text("Click ME");

    auto slider = Slider::construct(panel);
    slider->set_value(50);
    slider->set_width(150);

    auto panel2 = Panel::construct(panel);
    panel2->set_border(Border::INSET_BEVEL);
    panel2->set_layout(Layout::VERTICAL);

    auto btn = Button::construct(panel2);
    btn->set_text("Click ME");

    auto check_box = CheckBox::construct(panel2);
    check_box->set_text("Ayo");

    auto combo_box = ComboBox::construct(panel2);
    combo_box->add_option("Joburg");
    combo_box->add_option("Durban");
    combo_box->add_option("Polokwane");
    combo_box->add_option("Cape Town");

    combo_box->on_select([](auto event) {
        auto widget = event.trigger_widget();
        std::cout << widget->selected_option() << " :" <<
          widget->selected_option_index() <<  std::endl;
    });

    auto label = Label::construct(panel2);

    return Application::run(argc, argv);
}
