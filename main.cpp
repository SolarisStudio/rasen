#include <iostream>

#include <Application.h>
#include <Window.h>
#include <MenuBar.h>
#include <Menu.h>
#include <Button.h>
#include <CheckBox.h>
#include <Slider.h>
#include <Panel.h>
#include <ComboBox.h>
#include <Label.h>
#include <MessageDialog.h>
#include <InputDialog.h>
#include <PopupDialog.h>

#include <Border.h>

int main(int argc, char** argv) {
    auto window = Window::construct();
    window->set_size(900, 600);
    window->set_title("Hello, from c++");
    // window->set_resizable(true);

    auto menu_bar = MenuBar::construct(window);
    
    auto menu = Menu::construct(menu_bar);

    auto file_btn = Button::construct(menu_bar);
    file_btn->set_text("File");

    auto file_menu = Menu::construct(window);//:NOTE: Created it in the window because MenuBar will force it to draw horizontally
    auto save_btn = Button::construct(file_menu);		 
    save_btn->set_text("Save");

    file_btn->on_click([&file_menu](Event<Button>& event) {
      auto btn = event.trigger_widget();
      Vector2 drop_pos = {
	static_cast<float>(btn->x()),
	static_cast<float>(btn->y() + btn->height())
      };
      file_menu->toggle(drop_pos);
    });

    /*
    file_btn->set_text("Edit");
    file_btn->on_click([](auto event) {
        PopupDialog::show("Menu Action", "You clicked the Edit button on the MenuBar!");
    });

    auto edit_btn = Button::construct(menu_bar);
    edit_btn->set_text("Edit");
    edit_btn->on_click([](auto event) {
        PopupDialog::show("Menu Action", "You clicked the Edit button on the MenuBar!");
    });

    auto help_btn = Button::construct(menu_bar);
    help_btn->set_text("Help");
    help_btn->on_click([](auto event) {
        PopupDialog::show("Menu Action", "You clicked the Help button on the MenuBar!");
    });
    */

    auto desktop = window->desktop();
    desktop->on_draw([](Rectangle desktop_rect) {
        auto x = desktop_rect.width / 2;
        auto y = desktop_rect.height / 2;
        DrawText("Hello! I am drawn on the desktop", x, y, 12, RED);
    });

    auto panel = Panel::construct(window);
    panel->set_border(Border::OUTSET_BEVEL);
    panel->set_layout(Layout::VERTICAL);


    auto btn0 = Button::construct(panel);
    btn0->set_text("Click ME");

    auto slider = Slider::construct(panel);
    slider->set_value(50);
    slider->set_width(120);

    auto panel2 = Panel::construct(panel);
    panel2->set_border(Border::INSET_BEVEL);
    panel2->set_layout(Layout::VERTICAL);

    auto btn = Button::construct(panel2);
    btn->set_text("Click ME");

    auto check_box = CheckBox::construct(panel2);
    check_box->set_text("Ayo");

    int count = 0;
    auto combo_box = ComboBox::construct(panel2);
    combo_box->set_options({"A", "B", "C"});

    btn->on_click([&count, &combo_box](auto event) {
        auto value = TextFormat("count: %d", count++);
        PopupDialog::show("Ayo", "Hellow");
        combo_box->add_option((char*)value);
    });

    combo_box->on_select([&check_box](auto event) {
        auto widget = event.trigger_widget();
        check_box->set_text(widget->selected_option().c_str());
        std::cout << widget->selected_option() << " :" <<
          widget->selected_option_index() <<  std::endl;
    });

    auto label = Label::construct(panel2);
    label->set_text("Hello, world");

    btn0->on_click([&label](auto event) {
        auto result = InputDialog::show("Wanna hear a Joke", "Yes or no");
        if (result != NULL)
            label->set_text(result);
    });

    return Application::run(argc, argv);
}
