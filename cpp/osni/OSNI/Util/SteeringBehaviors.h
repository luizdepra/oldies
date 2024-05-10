#ifndef __CLC_STEERING_BEHAVIORS_H__
#define __CLC_STEERING_BEHAVIORS_H__

#include "../Common.h"
#include "VectorUtil.h"
#include "../Entity/Entity.h"

BEGIN_NAMESPACE

class SteeringBehaviors
{
public:
    static CL_Vec2f seek(const Entity &entity, const CL_Vec2f &target);
    static CL_Vec2f flee(const Entity &entity, const CL_Vec2f &target, float panicDistance = 300);
    static CL_Vec2f pursuit(const Entity &entity, const Entity &target);
    static CL_Vec2f evade(const Entity &entity, const Entity &target, float panicDistance = 300);
};

END_NAMESPACE

#endif
