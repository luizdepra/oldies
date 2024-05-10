#include "Explosion.h"

BEGIN_NAMESPACE

Explosion::Explosion(const CL_Vec2f &pos, bool isMissileExplosion)
: Entity(pos, "explosion"), _isMissileExplosion(isMissileExplosion), _vanishTimer(VANISH_TIME)
{
    _collision = CL_CollidableSprite::create_collision_outlines(_kernel->getGraphicContext(),
                                                                _name, &_kernel->getResourceManager())[3];

    if (!_isMissileExplosion)
    {
        _sprite.set_scale(0.5f, 0.5f);

        //_collision.set_scale(0.5f, 0.5f);
    }

    CL_Vec2f newPos = pos - CL_Vec2f(getWidth() / 2, getHeight() / 2);
    _position = newPos;
}

Explosion::~Explosion()
{
}

bool Explosion::isMissileExplosion()
{
    return _isMissileExplosion;
}

void Explosion::update(float delta)
{
    if (_sprite.is_finished())
        _isMarkedToDeletion = true;

    _sprite.update(static_cast<int>(delta));
}

void Explosion::draw()
{
    _sprite.draw(_kernel->getGraphicContext(), _position.x, _position.y);

    if (DEBUG)
        getCollisionOutline().draw(0, 0, CL_Colorf::aliceblue, _kernel->getGraphicContext());
}

END_NAMESPACE
