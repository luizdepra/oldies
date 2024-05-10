#include "_window.h"

using namespace std;

namespace tin{
    namespace itr {
        window::window()
            : _window(nullptr, SDL_DestroyWindow)
        {
        }

        window::window(string title)
            : _window(SDL_CreateWindow(title.c_str(), 0, 0, 800, 600, SDL_WINDOW_SHOWN), SDL_DestroyWindow)
        {
        }

        window::~window()
        {
        }
    }
}
