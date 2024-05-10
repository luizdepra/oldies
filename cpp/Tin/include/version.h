/* 
 * File:   Version.h
 * Author: RawArkanis
 *
 * Created on June 28, 2014, 1:25 PM
 */

#ifndef TIN_VERSION_H
#define	TIN_VERSION_H

#include <string>
#include <boost/format.hpp>

#define TIN_MAJOR_VERSION 0
#define TIN_MINOR_VERSION 0
#define TIN_PATCH_VERSION 0

namespace tin
{
    
    inline std::string version()
    {
        return boost::str(boost::format("%1%.%2%.%3%") % TIN_MAJOR_VERSION
                                                       % TIN_MINOR_VERSION
                                                       % TIN_PATCH_VERSION);
    }
    
}

#endif	/* TIN_VERSION_H */