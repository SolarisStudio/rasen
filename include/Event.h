#pragma once


#include <Container.h>
#include <functional>

template <typename TypeWidget>
class Event {
public:
    Event(Vector2& position, TypeWidget* widget, bool checked = false):
        m_position(position),
        m_widget(widget),
        m_checked(checked) {}

    ~Event() {}

    Vector2 mouse_position() { return m_position; };
    TypeWidget* trigger_widget() { return m_widget; };
    bool is_checked() { return m_checked; }

private:
    Vector2 m_position;
    TypeWidget* m_widget;
    bool m_checked;
};

template <typename W>
using ClickEvent = std::function<void(Event<W>&)>;

template <typename W>
using HoverEvent = std::function<void(Event<W>&)>;

template <typename W>
using CheckEvent = std::function<void(Event<W>&)>;

template <typename TypeWidget>
class EventWidget : public Widget {
public:
    void on_click(ClickEvent<TypeWidget> e) { m_on_click = e; }
    ClickEvent<TypeWidget> on_click() { return m_on_click; }

    void on_hover(HoverEvent<TypeWidget> e) { m_on_hover = e; }
    HoverEvent<TypeWidget> on_hover() { return m_on_hover; }

    void on_check(CheckEvent<TypeWidget> e) { m_on_check = e; }
    CheckEvent<TypeWidget> on_check() { return m_on_check; }

private:
    ClickEvent<TypeWidget> m_on_click = nullptr;
    HoverEvent<TypeWidget> m_on_hover = nullptr;
    CheckEvent<TypeWidget> m_on_check = nullptr;
};


