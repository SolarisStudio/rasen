#pragma once

#include <Dialog.h>

#include <string>

class PopupDialog {
public:
    static void show(std::string& title, std::string& message, DialogIcon icon = DialogIcon::INFO);
    static void show(const char* title,const char* message, DialogIcon icon = DialogIcon::INFO);
private:
    PopupDialog() = delete;
    ~PopupDialog() = delete;


    static void draw(std::string& title, std::string& message, DialogIcon icon);
};
