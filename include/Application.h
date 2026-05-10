#pragma once

#include <Window.h>
#include <vector>

class Application  {
    public:
        Application() = delete;
         ~Application() = delete;

        static void append(Window*);
        static int run(int, char**);
    protected:

    private:
        static std::vector<Window*> m_windows;
};


