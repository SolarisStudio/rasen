#pragma once

#include <Widget.h>
#include <vector>
#include <memory>

class Container : public Widget {
    public:
        Container(): m_color(Container::DEFAULT_BACKGROUND_COLOR) {};
        ~Container() {};

        std::vector<Widget*> children();
        Color background_color();

        void add(Widget*);
        void set_background_color(Color&);

        void update(float dt) override;
        void draw() override;

        static const Color DEFAULT_BACKGROUND_COLOR;

    protected:

    private:
        std::vector<Widget*> m_children;
        Color m_color;
};


