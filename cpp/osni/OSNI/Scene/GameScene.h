#ifndef __OSNI_GAME_SCENE_H__
#define __OSNI_GAME_SCENE_H__

#include "Scene.h"

#include <list>

#include "../Entity/Ship.h"
#include "../Entity/Laser.h"
#include "../Entity/Missile.h"
#include "../Entity/Flare.h"
#include "../Entity/Explosion.h"
#include "../Entity/Asteroid.h"

#include "../UI/Bar.h"

BEGIN_NAMESPACE

bool isLaserOutOfBounds(Laser *laser);
bool isAsteroidOutOfBounds(Asteroid *asteroid);

bool isLaserMarkedToDeletion(Laser *laser);
bool isMissileMarkedToDeletion(Missile *missile);
bool isFlareMarkedToDeletion(Flare *flare);
bool isExplosionMarkedToDeletion(Explosion *explosion);
bool isAsteroidMarkedToDeletion(Asteroid *asteroid);

class GameScene :
    public Scene
{
public:
    GameScene();
    ~GameScene();

    void update(float delta);
    void draw();

    void ship01FireCallback(const CL_Vec2f &pos, float angle);
    void ship02FireCallback(const CL_Vec2f &pos, float angle);

    void missileCallback(const Ship &ship, float angle);
    void flareCallback(const Ship &ship, float angle);

private:
    CL_Sprite _background;

    float _asteroidTimer;

    Ship *_ship01;
    Ship *_ship02;
    
    Bar *_health01Bar;
    Bar *_health02Bar;
    Bar *_energy01Bar;
    Bar *_energy02Bar;

    std::list<Laser *> _ship01Laser;
    std::list<Laser *> _ship02Laser;

    std::list<Missile *> _missileList;
    std::list<Flare *> _flareList;

    std::list<Asteroid *> _asteroidList;

    std::list<Explosion *> _explosionList;
    
    void spawnAsteroid();
    void spawnExplosion(Entity *projectile, bool isMissileExplosion = false);

    void removeLostLasers();
    void removeLostAsteroids();
    void checkCollisions();
    void correctMissilesTargets();
};

END_NAMESPACE

#endif
