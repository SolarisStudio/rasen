
#include <Widget.h>
#include <string>

class Label : public Widget {
    public:
        Label():
           m_text("Hello") {}
        ~Label() {}

        WIDGET_CONSTRUCT(Label);
        WIDGET_CONSTRUCT_PARENT(Label);

        void update(float);
        void draw();

    protected:

    private:
        std::string m_text;
};
