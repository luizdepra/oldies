#include "Entity.h"

BEGIN_NAMESPACE

Entity::Entity(const CL_Vec2f &pos, const CL_String &name)
: _name(name), _position(pos), _direction(CL_Vec2f()), _velocity(CL_Vec2f()),
  _maxSpeed(0), _isMarkedToDeletion(false), _kernel(Kernel::getInstance()),
  _sprite(CL_Sprite(_kernel->getGraphicContext(), name, &_kernel->getResourceManager()))
{
    _collision = CL_CollidableSprite::create_collision_outline(_kernel->getGraphicContext(),
                                                                name, &_kernel->getResourceManager());

    _width = _sprite.get_width();
    _height = _sprite.get_height();
}

Entity::~Entity()
{}

int Entity::getWidth() const
{
    return _width;
}

int Entity::getHeight() const
{
    return _height;
}

CL_Vec2f Entity::getPosition() const
{
    return _position;
}

void Entity::setPosition(const CL_Vec2f &point)
{
    _position = point;
}

CL_Vec2f Entity::getDirection() const
{
    return _direction;
}

void Entity::setAngle(float angle)
{
    _sprite.set_angle(CL_Angle::from_radians(angle));
}

float Entity::getAngle() const
{
    return _sprite.get_angle().to_radians();
}

void Entity::rotate(float angle)
{
    _sprite.rotate(CL_Angle::from_radians(angle));
}

CL_Vec2f Entity::getVelocity() const
{
    return _velocity;
}

float Entity::getMaxSpeed() const
{
    return _maxSpeed;
}

CL_CollisionOutline Entity::getCollisionOutline()
{
    float scaleX, scaleY;
    int x, y;
    CL_Origin origin;
    _sprite.get_scale(scaleX, scaleY);
    _sprite.get_rotation_hotspot(origin, x, y);

    CL_CollisionOutline ret = _collision.clone();
    ret.set_rotation_hotspot(origin, x, y);
    ret.set_translation(_position.x, _position.y);
    ret.set_scale(scaleX, scaleY);
    ret.set_angle(_sprite.get_angle());
    return ret;
}

void Entity::markToDeletion()
{
    _isMarkedToDeletion = true;
}

bool Entity::isMarkedToDeletion()
{
    return _isMarkedToDeletion;
}

void Entity::drawRectangle(const CL_Colorf &color)
{
    CL_Rectf rect(_position.x, _position.y, _position.x + _width, _position.y + _height);
    
    CL_Draw::box(_kernel->getGraphicContext(), rect, color);
}

END_NAMESPACE
