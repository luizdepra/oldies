#ifndef __CLC_ENTITY_H__
#define __CLC_ENTITY_H__

#include "../Kernel.h"

BEGIN_NAMESPACE

class Entity
{
public:
    Entity(const CL_Vec2f &pos, const CL_String &name);
    virtual ~Entity();

    int getWidth() const;
    int getHeight() const;

    CL_Vec2f getPosition() const;
    void setPosition(const CL_Vec2f &point);

    CL_Vec2f getDirection() const;

    void setAngle(float angle);
    float getAngle() const;
    void rotate(float angle);

    CL_Vec2f getVelocity() const;
    float getMaxSpeed() const;

    CL_CollisionOutline getCollisionOutline();

    void markToDeletion();
    bool isMarkedToDeletion();

    virtual void update(float delta) = 0;
    virtual void draw() = 0;

protected:
    CL_String _name;
    CL_Vec2f _position;
    CL_Vec2f _direction;
    CL_Vec2f _velocity;
    float _maxSpeed;
    int _height;
    int _width;

    bool _isMarkedToDeletion;

    Kernel *_kernel;

    CL_Sprite _sprite;
    CL_CollisionOutline _collision;

    void drawRectangle(const CL_Colorf &color);
};

END_NAMESPACE

#endif


