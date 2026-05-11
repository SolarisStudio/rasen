#include <InputDialog.h>
#include "tinyfiledialogs.h"


char* InputDialog::show(std::string& title, std::string& message, InputDialogType type) {
    return InputDialog::draw(title, message, type);
}

char* InputDialog::show(char* title, char* message, InputDialogType type) {
    auto m_title = std::string(title);
    auto m_message = std::string(message);
    return InputDialog::draw(m_title, m_message, type);
}


char * InputDialog::draw(std::string& title, std::string& message, InputDialogType type) {
    return tinyfd_inputBox(title.c_str(), message.c_str(), type == InputDialogType::PASSWORD ? NULL : "");
}