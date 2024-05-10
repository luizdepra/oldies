#include "Laser.h"

BEGIN_NAMESPACE

Laser::Laser(const CL_Vec2f &pos, float angle)
: Entity(pos, "laser")
{
    _sprite.set_angle(CL_Angle::from_radians(angle));
    _collision.set_angle(CL_Angle::from_radians(angle));
}

Laser::~Laser()
{
}

void Laser::update(float delta)
{
    float secs = delta / 1000.0f;

    _position += newVectorBySizeAndAngle(LASER_MAX_VELOCITY, _sprite.get_angle().to_radians()) * secs;
}

void Laser::draw()
{
    _sprite.draw(_kernel->getGraphicContext(), _position.x, _position.y);

    if (DEBUG)
        _collision.draw(_position.x, _position.y, CL_Colorf::limegreen, _kernel->getGraphicContext());
}

END_NAMESPACE
