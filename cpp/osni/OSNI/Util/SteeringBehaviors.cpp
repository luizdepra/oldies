#include "SteeringBehaviors.h"

BEGIN_NAMESPACE

CL_Vec2f SteeringBehaviors::seek(const Entity &entity, const CL_Vec2f &target)
{
    CL_Vec2f desired = target - entity.getPosition();
    resizeVector(desired, entity.getMaxSpeed());

    return desired - entity.getVelocity();
}

CL_Vec2f SteeringBehaviors::flee(const Entity &entity, const CL_Vec2f &target, float panicDistance)
{
    if (vectorDistance(entity.getPosition(), target) > panicDistance)
		return CL_Vec2f();

	CL_Vec2f desired = entity.getPosition() - target;
    resizeVector(desired, entity.getMaxSpeed());

    return desired - entity.getVelocity();
}

CL_Vec2f SteeringBehaviors::pursuit(const Entity &entity, const Entity &target)
{
    CL_Vec2f toTarget = target.getPosition() - entity.getPosition();
	float relativeDir = entity.getDirection().dot(target.getDirection());

	if (toTarget.dot(entity.getDirection()) > 0 && relativeDir < -0.95f) // Aprox 18 graus 
	{
		return seek(entity, target.getPosition());
	}

	double lookAheadTime = toTarget.length() / (entity.getMaxSpeed() + target.getVelocity().length());

	return seek(entity, target.getPosition() + target.getVelocity() * lookAheadTime);
}

CL_Vec2f SteeringBehaviors::evade(const Entity &entity, const Entity &target, float panicDistance)
{
    CL_Vec2f toTarget = target.getPosition() - entity.getPosition();
	float relativeDir = entity.getDirection().dot(target.getDirection());

	if (toTarget.dot(entity.getDirection()) > 0 && relativeDir < -0.95f) // Aprox 18 graus 
	{
		return flee(entity, target.getPosition(), panicDistance);
	}

	double lookAheadTime = toTarget.length() / (entity.getMaxSpeed() + target.getVelocity().length());

	return flee(entity, target.getPosition() + target.getVelocity() * lookAheadTime, panicDistance);
}

END_NAMESPACE
