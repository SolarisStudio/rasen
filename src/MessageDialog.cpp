#include <MessageDialog.h>
#include "tinyfiledialogs.h"

bool MessageDialog::show(
      std::string& title,
      std::string& message,
      MessageDialogButton btn,
      DialogIcon icon
    ) {
    return MessageDialog::draw(title, message, btn, icon);
}

bool MessageDialog::show(
      char* title,
      char* message,
      MessageDialogButton btn,
      DialogIcon icon
    ) {
    auto m_title = std::string(title);
    auto m_message = std::string(message);
    return MessageDialog::draw(m_title, m_message, btn, icon);
}


const char* dialog_button_str(MessageDialogButton btn) {
    if (btn == MessageDialogButton::OK)
        return "ok";
    if (btn == MessageDialogButton::OKCANCEL)
        return "okcancel";
    if (btn == MessageDialogButton::YESNO)
        return "yesno";
    if (btn == MessageDialogButton::YESNOCANCEL)
        return "yesnocancel";
    return "ok";
}


bool MessageDialog::draw(
      std::string& title,
      std::string& message,
      MessageDialogButton btn,
      DialogIcon icon
    ) {
    auto result = tinyfd_messageBox(
      title.c_str(),
      message.c_str(),
      dialog_button_str(btn),
      dialog_icon_str(icon),
      0
    );

    return result == 1;
}

