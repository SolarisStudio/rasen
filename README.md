# LibUI
> A tiny retained mode gui library built on top of raylib. 

## Build
### Requirements
#### Windows
- MSYS2 or WSL
- GCC
- raylib

#### Linux
- GCC
- raylib


#### Note
**Please** have a `RAYLIB_HOME` environment variable that points to the directory where raylib is installed.

Eg:
```sh
# Under MSYS2, WSL and LINUX

RAYLIB_HOME=$HOME/.local/

# Natively on Windows using mingw compilers etc
%RAYLIB_HOME%=C:/path/to/raylib/

```

Our build script will then infere the `include` and `lib` directories.


### Compile
To compile the sources and build the `.so` or `.dll` and `.a` simply run nob.c
```sh
# Linux
$ gcc nob.c -o nob && ./nob
# Windows
$ gcc nob.c -o nob.exe
$ nob.exe
```

If all goes well the library should be inside the `build/` directory.

## Examples
The only example that exists currently is the `main.cpp` file that is provied with the repo.
More examples are planned. For now here is a code snippet.

```cpp
#include <Application.h>
#include <Window.h>
#include <Button.h>
#include <Panel.h>
#include <Label.h>

#include <Border.h>

int main(int argc, char** argv) {
    auto window = Window::construct();
    window->set_size(600, 400);
    window->set_title("Counter program");

    auto panel = Panel::construct(window);
    panel->set_border(Border::OUTSET_BEVEL);
    panel->set_layout(Layout::VERTICAL);

    int count = 0;
    auto btn_plus = Button::construct(panel);
    btn0->set_text("+");

    auto btn_minux = Button::construct(panel1);
    btn->set_text("-");

    auto label = Label::construct(panel2);
    label->set_text(TextFormat("%d", count));

    plus_btn->on_click([&label, &count](auto event) {
      count++;    
      label->set_text(TextFormat("%d", count));
    });

    minux_btn->on_click([&label, &count](auto event) {
      count--;    
      label->set_text(TextFormat("%d", count));
    });
    return Application::run(argc, argv);
}
```

To compile the example under Windows you will have to link with the following system libraries.
`-lwinmm`, `-lgdi32`, `-lopengl32`, `-lole32`, `-lcomdlg32`.


## Infomation
LibUI is a very small gui library, it aims to get out of your way and let you write a gui. When I started
I had the following targets:
- Provide an application ready gui library
- Provide a different UI library for raylib
- Manually rewrite libgui from SerenityOS or atleast mimick it a lot.

## Widget List
- [X] Button            - [<Button.h>](./include/Button.h)
- [X] Checkbox          - [<Checkbox.h>](./include/Checkbox.h)
- [X] ComboBox          - [<ComboBox.h>](./include/ComboBox.h)
- [X] Desktop           - [<Desktop.h>](./include/Desktop.h)
- [X] InputDialog       - [<InputDialog.h>](./include/InputDialog.h)
- [ ] InputBox          - [<InputBox.h>](./include/InputBox.h)
- [ ] ImageView         - [<ImageView.h>](./include/ImageView.h)
- [X] Label             - [<Label.h>](./include/Label.h)
- [ ] ListView          - [<ListView.h>](./include/ListView.h)
- [ ] Menu              - [<Menu.h>](./include/Menu.h)
- [ ] MenuBar           - [<MenuBar.h>](./include/MenuBar.h)
- [ ] MenuItem          - [<MenuItem.h>](./include/MenuItem.h)
- [X] MessageDialog     - [<MessageDialog.h>](./include/MessageDialog.h)
- [X] Panel             - [<Panel.h>](./include/Panel.h)
- [X] PopupDialog       - [<PopupDialog.h>](./include/PopupDialog.h)
- [ ] PopupMenu         - [<PopupMenu.h>](./include/PopupMenu.h)
- [ ] ScrollableWidget  - [<ScrollableWidget.h>](./include/ScrollableWidget.h)
- [ ] ScrollBar         - [<ScrollBar.h>](./include/ScrollBar.h)
- [ ] SplitPane         - [<SplitPane.h>](./include/SplitPane.h)
- [ ] StatusBar         - [<StatusBar.h>](./include/StatusBar.h)
- [ ] Tab               - [<Tab.h>](./include/Tab.h)
- [ ] TextArea          - [<TextArea.h>](./include/TextArea.h)
- [ ] ToolBar           - [<ToolBar.h>](./include/ToolBar.h)
- [X] Slider            - [<Slider.h>](./include/Slider.h)
- [X] Widget            - [<Widget.h>](./include/Widget.h)
- [X] Window            - [<Window.h>](./include/Window.h)
