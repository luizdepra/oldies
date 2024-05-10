#ifndef __OSNI_BAR_H__
#define __OSNI_BAR_H__

#include "../Kernel.h"

BEGIN_NAMESPACE

class Bar
{
    Bar(const CL_Vec2f &pos, float maxValue, const CL_String &background, const CL_String &bar);
    ~Bar();
    
    void setValue(float value);
    float getValue();
    
    void draw();
    
protected:
    Kernel *_kernel;

    CL_Vec2f _position;

    CL_Sprite _background;
    CL_Sprite _bar;
    
    float _value;
    float _maxValue;
};

END_SPACE

#endif
