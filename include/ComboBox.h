#pragma once

#include <Event.h>

#include <string>
#include <vector>

class ComboBox : public EventWidget<ComboBox> {
    public:
        ComboBox():
            m_options{" "},
            m_selected_index{0} {};

        ~ComboBox() {} ;

        WIDGET_CONSTRUCT(ComboBox);
        WIDGET_CONSTRUCT_PARENT(ComboBox);

        void update(float dt) override;
        void draw() override;

        void set_options(std::vector<std::string>&);
        void add_option(std::string&);
        void add_option(char*);

        std::vector<std::string> options();

        void set_selected_option(int index) { m_selected_index = index % m_options.size(); }
        int selected_option_index() { return m_selected_index; }
        std::string selected_option() {
            if (m_options.size() == 0) {
                return "";
            }
            return m_options[m_selected_index % m_options.size()];
        }

        std::string option_at(int index) {
            auto prev = m_selected_index;
            m_selected_index = index;
            auto value = selected_option();
            m_selected_index = prev;
            return value;
        }


    protected:

    private:
        std::vector<std::string> m_options;
        int m_selected_index = -1;
        bool m_show_options = false;
        bool m_options_initialized = false;
};
