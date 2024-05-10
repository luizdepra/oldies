/* 
 * File:   application.cpp
 * Author: RawArkanis
 * 
 * Created on July 1, 2014, 6:44 PM
 */

#include "_internal_application.h"

using namespace std;

namespace tin
{
    namespace itr
    {
        internal_application::internal_application()
            : base_internal_application(TIN_EVERYTHING)
        {
        }

        internal_application::~internal_application()
        {
        }

        int internal_application::run()
        {
            return 0;
        }
    }
}

