#ifndef _CHECKBOX_H_
#define _CHECKBOX_H_

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

    static std::unique_ptr<CheckBox> construct();
    WIDGET_CONSTRUCT(CheckBox);

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

#endif // _CHECKBOX_H_
