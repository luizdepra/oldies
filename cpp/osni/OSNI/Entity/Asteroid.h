#ifndef __OSNI_ASTEROID_H__
#define __OSNI_ASTEROID_H__

#include "Entity.h"

#include "../Util/VectorUtil.h"

BEGIN_NAMESPACE

static const float ASTEROID_ROTATION_INCREMENT = 0.5f;

class Asteroid :
    public Entity
{
public:
    Asteroid(const CL_Vec2f &pos, float angle, int size = 1);
    ~Asteroid();

    void update(float delta);
    void draw();

private:
    int _size;
};

END_NAMESPACE

#endif
