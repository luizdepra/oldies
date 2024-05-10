/* 
 * File:   Application.cpp
 * Author: RawArkanis
 * 
 * Created on June 29, 2014, 10:16 AM
 */

#include <application.h>

#include "internal/platform/windows/_internal_application.h"

using namespace std;

namespace tin
{
    application::application()
        : _internal(new itr::internal_application())
    {
    }

    application::~application()
    {
    }
    
    
    int application::run() {
        _internal->run();
        
        return 0;
    }
}
