#pragma once

#include <DrawUtils.h>
#include <UIConstants.h>
#include <functional>

class Widget {
    public:
        Widget():
            m_rect{0,0,0,0},
            m_spacing{3},
            m_margin{1}

            {};

        ~Widget() {};

        // Getters
        Rectangle bounding_rect();
        Vector2   location();
        Vector2   get_size();

        unsigned int spacing();
        unsigned int margin();
        unsigned int width();
        unsigned int height();
        Widget* parent();

        // Setters
        void set_bounding_rect(Rectangle&);
        void set_location(Vector2&);
        void set_location(unsigned int, unsigned int);

        void set_size(Vector2&);
        void set_size(unsigned int, unsigned int);

        void set_width(unsigned int);
        void set_height(unsigned int);

        void set_spacing(unsigned int);
        void set_margin(unsigned int);

        void set_parent(Widget*);

        virtual void update(float) = 0;
        virtual void draw() = 0;



    protected:

    private:
        Rectangle m_rect;
        unsigned int m_spacing = 3;
        unsigned int m_margin = 1;
        Widget* m_parent;
};


