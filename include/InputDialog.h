#pragma once

#include <string>

enum class InputDialogType {
    TEXT, PASSWORD
};

class InputDialog {
public:

    static char* show(std::string& title, std::string& message, InputDialogType type = InputDialogType::TEXT);
    static char* show(const char* title, const char* message, InputDialogType type = InputDialogType::TEXT);

private:
    InputDialog() = delete;
    ~InputDialog() = delete;

    static char* draw(std::string& title, std::string& message, InputDialogType type);
    static std::string m_title;
    static std::string m_message;

};
