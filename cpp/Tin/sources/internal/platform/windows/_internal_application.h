/* 
 * File:   application.h
 * Author: RawArkanis
 *
 * Created on July 1, 2014, 6:44 PM
 */

#ifndef _INTERNAL_APPLICATION_H
#define    _INTERNAL_APPLICATION_H

#include "../../_base_internal_application.h"

namespace tin
{
    namespace itr
    {
        class internal_application : public base_internal_application
        {
        public:
            explicit internal_application();
            virtual ~internal_application();

            int run();
        };
    }
}

#endif    /* _INTERNAL_APPLICATION_H */
