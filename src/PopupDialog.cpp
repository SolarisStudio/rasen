#include <PopupDialog.h>
#include "tinyfiledialogs.h"

void PopupDialog::show(std::string& title, std::string& message, DialogIcon icon) {
    PopupDialog::draw(title, message, icon);
}

void PopupDialog::show(char* title, char* message, DialogIcon icon) {
    auto m_title = std::string(title);
    auto m_message = std::string(message);
    PopupDialog::draw(m_title, m_message, icon);
}


void PopupDialog::draw(std::string& title, std::string& message, DialogIcon icon) {
    tinyfd_notifyPopup(title.c_str(), message.c_str(), dialog_icon_str(icon));
}