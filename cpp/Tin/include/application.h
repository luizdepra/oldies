/* 
 * File:   Application.h
 * Author: RawArkanis
 *
 * Created on June 29, 2014, 10:16 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include <string>
#include <vector>
#include <memory>

namespace tin
{
    namespace itr
    {
        class internal_application;
    }

    class application
    {
    public:
        explicit application();
        virtual ~application();
        
        int run();
        
    private:
        std::unique_ptr<itr::internal_application> _internal;
    };

}

#endif	/* APPLICATION_H */

