#pragma once

#include <UIConstants.h>
#include <Event.h>

#include <string>

class CheckBox : public EventWidget<CheckBox> {
public:
    CheckBox():
        m_checked(false),
        m_label{""}
        {}

    ~CheckBox() {}

    WIDGET_CONSTRUCT(CheckBox);
    WIDGET_CONSTRUCT_PARENT(CheckBox);

    void set_text(const char*);
    void set_text(std::string&);

    std::string text();

    void update(float dt) override;
    void draw() override;

private:
    std::string m_label;
    bool m_checked;
    bool m_hovered = false;
};


