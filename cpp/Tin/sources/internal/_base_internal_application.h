/* 
 * File:   BaseInternalApplication.h
 * Author: RawArkanis
 *
 * Created on June 28, 2014, 1:23 PM
 */

#ifndef _BASE_APPLICATION_H
#define    _BASE_APPLICATION_H

#include <memory>
#include <vector>
#include <string>
#include <SDL.h>

#include <common.h>

#include "_window.h"

namespace tin
{
    namespace itr
    {
        class base_internal_application
        {
        public:
            explicit base_internal_application(const application_flags flags);
            virtual ~base_internal_application();

            std::vector<std::string> get_arguments() const;

            virtual int run();

        protected:
            std::unique_ptr<window> _window;
        };
    }
}

#endif    /* BASE_INTERNAL_APPLICATION_H */
