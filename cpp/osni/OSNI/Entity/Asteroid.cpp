#include "Asteroid.h"

BEGIN_NAMESPACE

Asteroid::Asteroid(const CL_Vec2f &pos, float angle, int size)
: Entity(pos, "asteroid"), _size(size)
{
    _sprite.set_scale(size * 0.5f, size * 0.5f);
    _sprite.set_angle(CL_Angle::from_radians(angle));

    _direction = newVectorBySizeAndAngle(1.0f, angle);

    _maxSpeed = rand() % 100 + 50.0f;

    _collision = CL_CollidableSprite::create_collision_outline(_kernel->getGraphicContext(),
                                                               "asteroid", &_kernel->getResourceManager());
    _collision.set_angle(CL_Angle::from_radians(angle));
    _collision.set_scale(size * 0.5f, size * 0.5f);
}

Asteroid::~Asteroid()
{
}

void Asteroid::update(float delta)
{
    float secs = delta / 1000.0f;

    _position += (_direction * _maxSpeed) * secs;
    _sprite.rotate(CL_Angle::from_radians(ASTEROID_ROTATION_INCREMENT * secs));
}

void Asteroid::draw()
{
    _sprite.draw(_kernel->getGraphicContext(), _position.x, _position.y);

    if (DEBUG)
        getCollisionOutline().draw(0, 0, CL_Colorf::crimson, _kernel->getGraphicContext());
}

END_NAMESPACE
