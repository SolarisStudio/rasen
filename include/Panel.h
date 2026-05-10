#pragma once

#include <Container.h>
#include <Layout.h>
#include <Border.h>

class Panel: public Container {
    public:
        Panel() :
            m_layout(Layout::HORIZONTAL),
            m_border(Border::NONE) {}
        ~Panel() {};

        WIDGET_CONSTRUCT(Panel);
        WIDGET_CONSTRUCT_PARENT(Panel);

        void update(float dt) override;
        void draw() override;

        void set_border(Border border) { m_border = border; }
        Border border() { return m_border; }

        void set_layout(Layout layout) { m_layout = layout; }
        Layout layout() { return m_layout; }



    private:
        Layout m_layout;
        Border m_border;
};

