#ifndef __OSNI_MISSILE_H__
#define __OSNI_MISSILE_H__

#include "Entity.h"

#include "../Util/SteeringBehaviors.h"

BEGIN_NAMESPACE

static const float MISSILE_MASS = 0.01f;
static const float MISSILE_MAX_SPEED = 150.0f;
static const float MISSILE_MAX_FORCE = 50.0f;
static const float MISSILE_LIFE_TIME = 5000.0f;

class Missile :
    public Entity
{
public:
    Missile(const CL_Vec2f &pos, float angle, Entity *target);
    ~Missile();

    void setTarget(Entity *target);
    Entity *getTarget();
    bool changedTarget();

    void update(float delta);
    void draw();

private:
    bool _changedTarget;

    float _mass;
    float _lifetime;

    Entity *_target;
};

END_NAMESPACE

#endif
