#pragma once

#include <UIConstants.h>
#include <Event.h>

#include <string>

class CheckBox : public EventWidget<CheckBox> {
public:
    CheckBox():
        m_checked(false),
        m_text{""}
        {}

    ~CheckBox() {}

    WIDGET_CONSTRUCT(CheckBox);
    WIDGET_CONSTRUCT_PARENT(CheckBox);
    WIDGET_ALLOWS_TEXT;

    void update(float dt) override;
    void draw() override;

private:
    std::string m_text;
    bool m_checked;
    bool m_hovered = false;
};


