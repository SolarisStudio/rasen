#pragma once
#include <Widget.h>
#include <string>

class Label : public Widget {
    public:
        Label():
           m_text(" ") {}
        ~Label() {}

        WIDGET_CONSTRUCT(Label);
        WIDGET_CONSTRUCT_PARENT(Label);
        WIDGET_ALLOWS_TEXT;

        void update(float) override;
        void draw() override;

    protected:

    private:
        std::string m_text;
};
