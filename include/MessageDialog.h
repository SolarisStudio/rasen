
#pragma once

#include <Widget.h>
#include <Dialog.h>

#include <string>


enum class MessageDialogButton {
  OK,
  OKCANCEL,
  YESNO,
  YESNOCANCEL
};

class MessageDialog {
public:
    static bool show(std::string& title, std::string& message, MessageDialogButton btn = MessageDialogButton::OK, DialogIcon icon = DialogIcon::INFO);
    static bool show(char* title, char* message, MessageDialogButton btn = MessageDialogButton::OK, DialogIcon icon = DialogIcon::INFO);

private:
    MessageDialog() = delete;
    ~MessageDialog() = delete;

    static bool draw(std::string& title, std::string& message, MessageDialogButton btn = MessageDialogButton::OK, DialogIcon icon = DialogIcon::INFO);
};
