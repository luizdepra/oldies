/* 
 * File:   BaseInternalApplication.cpp
 * Author: RawArkanis
 * 
 * Created on June 28, 2014, 1:23 PM
 */

#include "_base_internal_application.h"

using namespace std;

namespace tin
{
    namespace itr
    {
        base_internal_application::base_internal_application(const application_flags flags)
        {
            SDL_Init(SDL_INIT_EVERYTHING);

            _window.reset(new window("Test"));
        }

        base_internal_application::~base_internal_application()
        {
            SDL_Quit();
        }

        int base_internal_application::run()
        {
            return 0;
        }
    }
}
