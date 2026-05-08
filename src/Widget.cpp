#include "Widget.h"

Rectangle Widget::bounding_rect() {
    return m_rect;
}

Vector2 Widget::get_size() {
    return Vector2{m_rect.width, m_rect.height};
}

unsigned int Widget::spacing() {
    return m_spacing;
}

unsigned int Widget::margin() {
    return m_margin;
}

unsigned int Widget::width() {
    return (unsigned int)m_rect.width;
}

unsigned int Widget::height() {
    return (unsigned int)m_rect.height;
}

Vector2 Widget::location() {
    return Vector2{m_rect.x, m_rect.y};
}

Widget* Widget::parent() {
    return m_parent;
}

void Widget::set_parent(Widget* widget) {
    m_parent = widget;
}

void Widget::set_bounding_rect(Rectangle& rect) {
    m_rect = rect;
}

void Widget::set_location(Vector2& location) {
    m_rect.x = location.x;
    m_rect.y = location.y;
}

void Widget::set_location(unsigned int x, unsigned int y) {
    m_rect.x = x;
    m_rect.y = y;
}

void Widget::set_size(Vector2& _size) {
    m_rect.width = _size.x;
    m_rect.height = _size.y;
}

void Widget::set_size(unsigned int width, unsigned int height) {
    m_rect.width = width;
    m_rect.height = height;
}

void Widget::set_width(unsigned int width) {
    m_rect.width = width;
}

void Widget::set_height(unsigned int height) {
    m_rect.height = height;
}

void Widget::set_spacing(unsigned int spacing) {
    m_spacing = spacing;
}

void Widget::set_margin(unsigned int margin) {
    m_margin = margin;
}




