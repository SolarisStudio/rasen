#pragma once

#include <Container.h>

#include <functional>

using DesktopDrawCall = std::function<void(Rectangle)>;

class Desktop : public Container {
public:
    Desktop() {}
    ~Desktop() {}
    void update(float);
    void draw();

    void on_draw(DesktopDrawCall draw_fn) { m_draw = draw_fn; }

    static const Color DEFAULT_BACKGROUND_COLOR;
private:
    DesktopDrawCall m_draw = nullptr;
};
