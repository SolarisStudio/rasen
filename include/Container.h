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

        void set_background_color(Color&);

        void update(float dt) override;
        void draw() override;

        static const Color DEFAULT_BACKGROUND_COLOR;


        template<typename T>
        void add(std::unique_ptr<T>& child) {
            if (!child) return;

            T* child_widget = child.get();

            child->set_parent(this);

            m_children.push_back(static_cast<Widget*>(child_widget));
        }
    protected:

    private:
        std::vector<Widget*> m_children;
        Color m_color;
};


