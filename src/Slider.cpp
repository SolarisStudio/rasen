#include <Slider.h>
#include <iostream>

std::unique_ptr<Slider> Slider::construct() {
    auto slider = std::make_unique<Slider>();
    return slider;
};

void Slider::update(float dt) {
    auto parent = static_cast<Container*>(this->parent());
    auto spacing = this->spacing();


    auto width_diff = parent->width() - this->x();
    this->set_size(width_diff - spacing * 2, 25);

    auto rect = this->bounding_rect();
    auto track_rect = Rectangle {rect.x + spacing, rect.y + (rect.height / 2), rect.width - spacing * 2, 5};


    auto mouse_pos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(mouse_pos, rect)) {
            m_is_dragging = true;
        }
    }

    Event<Slider> e(mouse_pos, this);

    if (m_is_dragging) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            if (m_is_dragging) {
                auto drop = this->on_drop();
                if (drop != nullptr) {
                    drop(e);
                }
            }
            m_is_dragging = false;
        } else {
            float relative_x = mouse_pos.x - track_rect.x;
            float percentage = relative_x / track_rect.width;

            percentage = (percentage < 0) ? 0 : (percentage > 1 ? 1 : percentage);

            m_value = m_min_value + percentage * (m_max_value - m_min_value);

            auto drag = this->on_drag();
            if (drag != nullptr) {
                drag(e);
            }
        }
    }
}

float Slider::get_knob_x(const Rectangle& track_rect) {
    float range = m_max_value - m_min_value;
    float relative_value = m_value - m_min_value;
    return track_rect.x + (relative_value / range) * track_rect.width;
}


void Slider::draw() {
    auto spacing = this->spacing();
    auto rect = this->bounding_rect();

    auto height_diff = (rect.y + rect.height) - rect.y - spacing;
    auto track_rect = Rectangle {rect.x + spacing, rect.y + height_diff / 2, rect.width - spacing * 2, 5};
    float track_y = track_rect.y;
    DrawUtils::DrawRectangleInset(track_rect, 3, GetColor(0x999999FF));

    auto track_item_rect = Rectangle {
        track_rect.x,
        track_rect.y + spacing,
        4,
        3
    };

    auto track_width_diff = (track_rect.x + track_rect.width) - track_rect.x - spacing;
    int i = 0;
    while (track_item_rect.x < track_rect.x + track_rect.width) {
        auto color = ColorBrightness(LIGHTGRAY, -0.5);
        track_item_rect.height = 3;
        if (i % 6 == 0) {
            track_item_rect.height = 6;
            color = ColorBrightness(LIGHTGRAY, -0.7);
        }

        DrawUtils::DrawRectangleInset(track_item_rect, 1, color);
        track_item_rect.x += track_item_rect.width + spacing;
        i++;
    }

    float knob_x = get_knob_x(track_rect);


    float triangle_size = 7.0f;
    track_y += triangle_size / 2;
    Vector2 v1 = { knob_x - triangle_size, track_y - triangle_size }; // Top Left
    Vector2 v2 = { knob_x + triangle_size, track_y - triangle_size }; // Top Right
    Vector2 v3 = { knob_x, track_y + 2 };                            // Bottom Tip (near track)

    DrawUtils::DrawTriangleFilledOutset(v1, v2, v3, 2.0f, BLACK);
};

void Slider::set_value(float value) {
    if (value < this->m_min_value) {
        value = this->m_min_value;
    } else if (value > this->m_max_value) {
        value = this->m_min_value;
    }

    this->m_value = value;
}


void Slider::set_min_value(float value) {
    this->m_min_value = value;
}


void Slider::set_max_value(float value) {
    this->m_max_value = value;
}


float Slider::value() {
    return this->m_value;
}


float Slider::max_value() {
    return this->m_max_value;
}


float Slider::min_value() {
    return this->m_min_value;
}

