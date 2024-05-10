#ifndef __OSNI_FLARE_H__
#define __OSNI_FLARE_H__

#include "Entity.h"

#include "../Util/SteeringBehaviors.h"

BEGIN_NAMESPACE

static const float FLARE_MASS = 0.01f;
static const float FLARE_MAX_SPEED = 150.0f;
static const float FLARE_MAX_FORCE = 50.0f;
static const float FLARE_LIFE_TIME = 3000.0f;

class Flare :
    public Entity
{
public:
    Flare(const CL_Vec2f &pos, float angle, Entity *target);
    ~Flare();

    void setTarget(Entity *target);
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
