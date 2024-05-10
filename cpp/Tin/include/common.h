/* 
 * File:   Common.h
 * Author: RawArkanis
 *
 * Created on June 28, 2014, 1:25 PM
 */

#ifndef TIN_COMMON_H
#define	TIN_COMMON_H

namespace tin
{
    
    enum application_flags
    {
        TIN_GRAPHIC = 0x0001,
        TIN_AUDIO = 0x0002,
        TIN_INPUT = 0x0004,
        TIN_PHYSIC = 0x0008,
        TIN_NETWORK = 0x0010,
        TIN_EVERYTHING = 0x001f
    };
    
    inline application_flags operator|(application_flags flag_1,
        application_flags flag_2)
    {
        return static_cast<application_flags>(
                static_cast<int>(flag_1) |
                static_cast<int>(flag_2));
    }
    
}

#endif	/* TIN_COMMON_H */

