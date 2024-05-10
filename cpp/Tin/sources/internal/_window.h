#ifndef _WINDOW_H
#define _WINDOW_H

#include <string>
#include <memory>
#include <SDL.h>

namespace tin
{
    namespace itr
    {
        class window
        {
        public:
            window();
            window(std::string title);
            ~window();

        private:
            std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;
        };
    }
}

#endif // !_WINDOW_H
