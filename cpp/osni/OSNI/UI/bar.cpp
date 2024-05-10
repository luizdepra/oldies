#include "Bar.h"

BEGIN_NAMESPACE

Bar::Bar(const CL_Vec2f &pos, float maxValue, const CL_String &background, const CL_String &bar)
: _kernel(Kernel::getInstance()), _position(pos), _background(), _bar(), _value(0), _maxValue(maxValue)
  _background(CL_Sprite(_kernel->getGraphicContext(), background, &_kernel->getResourceManager())),
  _bar(CL_Sprite(_kernel->getGraphicContext(), bar, &_kernel->getResourceManager()))
{}

Bar::~Bar()
{}

void Bar::setValue(float value)
{
    _value = value;
}

float Bar::getValue()
{
    return _value;
}

void Bar::draw()
{
    _background.draw(_kernel->getGraphicContext(), _position.x, _position.y);
    
    if (_value > 0)
    {
        CL_Rectf source(CL_Pointx(0.0f, 0.0f), CL_Sizef(_bar.get_width() * (_value / _maxValue), _bar.get_height()));
        CL_Rectf dest(CL_Pointx(_position), CL_Sizef(_bar.get_width(), _bar.get_height()));
        
        _bar.draw(_kernel->getGraphicContext(), source, dest);
    }
}

END_SPACE
