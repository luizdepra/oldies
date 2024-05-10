#ifndef __OSNI_SHIP_H__
#define __OSNI_SHIP_H__

#include "Entity.h"

#include "../Util/VectorUtil.h"

BEGIN_NAMESPACE

static const int SHIP01_HEALTH = 10;
static const int SHIP01_ENERGY = 12;
static const float SHIP01_MASS = 0.01f;

static const int SHIP02_HEALTH = 12;
static const int SHIP02_ENERGY = 10;
static const float SHIP02_MASS = 0.03f;

static const float SHIP_ROTATION_INCREMENT = 0.1f;
static const float SHIP_PROPULSION_INTENSITY = 1.0f;
static const float SHIP_MAX_SPEED = 150.0f;

class Ship :
    public Entity
{
public:
    Ship(const CL_Vec2f &pos, const CL_String &name, CL_Callback_2<void,
         const CL_Vec2f &, float> fireCallback, CL_Callback_2<void, const Ship &, float> specialCallback);
    ~Ship();

    void update(float delta);
    void draw();

    void takeDamage(int value = 1);
    
    int getHealth();
    int getEnergy();

private:
    int _health;
    int _energy;
    int _maxHealth;
    int _maxEnergy;

    float _mass;

    float _rotationSleep;
    float _fireSleep;
    float _specialSleep;

    float _energyTimer;
    
    bool _isPropulsionActive;

    CL_Callback_2<void, const CL_Vec2f &, float> _fireCallback;
    CL_Callback_2<void, const Ship &, float> _specialCallback;

    void activePropulsion();
    
    void fire();
    void fireSpecial();

    void rotateAnticlockwise();
    void rotateClockwise();

    void updateShip01();
    void updateShip02();
};

END_NAMESPACE

#endif
