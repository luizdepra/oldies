#ifndef __OSNI_LASER_H__
#define __OSNI_LASER_H__

#include "Entity.h"

#include "../Util/VectorUtil.h"

BEGIN_NAMESPACE

const float LASER_MAX_VELOCITY = 200.0f;

class Laser :
    public Entity
{
public:
    Laser(const CL_Vec2f &pos, float angle);
    ~Laser();

    void update(float delta);
    void draw();
};

END_NAMESPACE

#endif

