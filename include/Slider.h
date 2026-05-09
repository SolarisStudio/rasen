#pragma once

#include <Event.h>
#include <memory>


class Slider : public EventWidget<Slider> {
public:
    Slider():
        m_min_value(0),
        m_max_value(100),
        m_value(50) {}
    ~Slider() {}

    static std::unique_ptr<Slider> construct();

    void update(float dt) override;
    void draw() override;

    void set_value(float);

    void set_min_value(float);

    void set_max_value(float);

    float value();

    float max_value();

    float min_value();

private:
    float m_min_value;
    float m_max_value;
    float m_value;
    bool m_is_dragging = false;
    float get_knob_x(const Rectangle& track_rect);

    Vector2 m_drag_slider_location;
};
