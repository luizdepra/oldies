#ifndef __OSNI_EXPLOSION_H__
#define __OSNI_EXPLOSION_H__

#include "Entity.h"

BEGIN_NAMESPACE

static const float VANISH_TIME = 500.0f;

class Explosion :
    public Entity
{
public:
    Explosion(const CL_Vec2f &pos, bool isMissileExplosion = false);
    ~Explosion();

    bool isMissileExplosion();

    void update(float delta);
    void draw();

private:
    bool _isMissileExplosion;

    float _vanishTimer;
};

END_NAMESPACE

#endif
