#include "Flare.h"

BEGIN_NAMESPACE

Flare::Flare(const CL_Vec2f &pos, float angle, Entity *target)
: Entity(pos, "flare"), _mass(FLARE_MASS), _lifetime(FLARE_LIFE_TIME),
  _target(target), _changedTarget(false)
{
    _maxSpeed = FLARE_MAX_SPEED;

    _direction = newVectorBySizeAndAngle(1.0f, angle);

    _sprite.set_angle(CL_Angle::from_radians(angle));
}

Flare::~Flare()
{
}

void Flare::setTarget(Entity *target)
{
    _target = target;
    _changedTarget = true;
}

bool Flare::changedTarget()
{
    return _changedTarget;
}

void Flare::update(float delta)
{
    float secs = delta / 1000.0f;

    _lifetime -= delta;
    if (_lifetime <= 0.0f)
        _isMarkedToDeletion = true;

    CL_Vec2f forces;
    if (_target)
        forces += truncateVector(SteeringBehaviors::evade(*this, *_target), FLARE_MAX_FORCE);

    CL_Vec2f acceleration = forces / _mass;
    CL_Vec2f accelSecs = acceleration * secs;
    _position += truncateVector((_velocity + accelSecs / 2) * secs, _maxSpeed);
    _velocity = truncateVector(_velocity + accelSecs, _maxSpeed);

    if (_velocity.length() != 0.0f)
        _direction = CL_Vec2f::normalize(_velocity);

    if ((int)_position.x < -_sprite.get_width())
        _position.x = (float)SCREEN_WIDTH;
    if ((int)_position.x > SCREEN_WIDTH + _sprite.get_width())
        _position.x = 0.0f;
    if ((int)_position.y < -_sprite.get_height())
        _position.y = (float)SCREEN_HEIGHT;
    if ((int)_position.y > SCREEN_HEIGHT + _sprite.get_height())
        _position.y = 0.0f;
}

void Flare::draw()
{
    _sprite.draw(_kernel->getGraphicContext(), _position.x, _position.y);
    
    if (DEBUG)
        _collision.draw(_position.x, _position.y, CL_Colorf::limegreen, _kernel->getGraphicContext());
}

END_NAMESPACE