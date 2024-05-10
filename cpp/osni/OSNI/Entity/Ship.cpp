#include "Ship.h"

BEGIN_NAMESPACE

Ship::Ship(const CL_Vec2f &pos, const CL_String &name,
           CL_Callback_2<void, const CL_Vec2f &, float> fireCallback,
           CL_Callback_2<void, const Ship &, float> specialCallback)
: Entity(pos, name), // Arrumar essa lists, verificar se ta tudo aqui
  _isPropulsionActive(false), _fireCallback(fireCallback),
  _specialCallback(specialCallback), _energyTimer(0.0f)
{
    _maxSpeed = SHIP_MAX_SPEED;

    if (_name == "ship01")
    {
        _sprite.set_angle(CL_Angle::from_radians(0.0f));
        _direction = newVectorBySizeAndAngle(1.0f, 0.0f);
        _health = SHIP01_HEALTH;
        _energy = SHIP01_ENERGY;
        _maxHealth = SHIP01_HEALTH;
        _maxEnergy = SHIP01_ENERGY;
        _mass = SHIP01_MASS;
    }
    else if (_name == "ship02")
    {
        _sprite.set_angle(CL_Angle::from_radians(3.14f));
        _direction = newVectorBySizeAndAngle(1.0f, 3.14f);
        _health = SHIP02_HEALTH;
        _energy = SHIP02_ENERGY;
        _maxHealth = SHIP02_HEALTH;
        _maxEnergy = SHIP02_ENERGY;
        _mass = SHIP02_MASS;
    }
}

Ship::~Ship()
{
}

void Ship::activePropulsion()
{
    _isPropulsionActive = true;
}
    
void Ship::fire()
{
    if (_fireSleep <= 0.0f)
    {
        _fireCallback.invoke(_position, _sprite.get_angle().to_radians());

        _fireSleep = 100.0f;
    }
}

void Ship::fireSpecial()
{
    if (_specialSleep <= 0.0f)
    {
        _specialCallback.invoke(*this, _sprite.get_angle().to_radians());

        _specialSleep = 1000.0f;
    }
}

void Ship::rotateAnticlockwise()
{
    if (_rotationSleep <= 0.0f)
    {
        _sprite.rotate(CL_Angle::from_radians(-SHIP_ROTATION_INCREMENT));

        _rotationSleep = 100.0f;
    }
}

void Ship::rotateClockwise()
{
    if (_rotationSleep <= 0.0f)
    {
        _sprite.rotate(CL_Angle::from_radians(SHIP_ROTATION_INCREMENT));

         _rotationSleep = 100.0f;
    }
}

void Ship::updateShip01()
{
    CL_InputDevice keyboard = _kernel->getInputContext().get_keyboard();

    // Propulsion
    if (keyboard.get_keycode(CL_KEY_W))
    {
        activePropulsion();
    }

    // Fire
    if (keyboard.get_keycode(CL_KEY_S))
    {
        fire();
    }

    // Rotate Left
    if (keyboard.get_keycode(CL_KEY_A))
    {
        rotateAnticlockwise();
    }

    // Rotate Right
    if (keyboard.get_keycode(CL_KEY_D))
    {
        rotateClockwise();
    }

    // Fire Special
    if (keyboard.get_keycode(CL_KEY_Q))
    {
        fireSpecial();
    }
}

void Ship::updateShip02()
{
    CL_InputDevice keyboard = _kernel->getInputContext().get_keyboard();

    // Propulsion
    if (keyboard.get_keycode(CL_KEY_I))
    {
        activePropulsion();
    }

    // Fire
    if (keyboard.get_keycode(CL_KEY_K))
    {
        fire();
    }

    // Rotate Left
    if (keyboard.get_keycode(CL_KEY_J))
    {
        rotateAnticlockwise();
    }

    // Rotate Right
    if (keyboard.get_keycode(CL_KEY_L))
    {
        rotateClockwise();
    }

    // Fire Special
    if (keyboard.get_keycode(CL_KEY_O))
    {
        fireSpecial();
    }
}

void Ship::takeDamage(int value)
{
    _health -= value;
    
    if (_health < 0)
        _health = 0;
}

int Ship::getHealth()
{
    return _health;
}

int Ship::getEnergy()
{
    return _energy;
}

void Ship::update(float delta)
{
    _isPropulsionActive = false;

    if (_energy < _maxEnergy)
    {
        _energyTimer += delta;
        if (_energyTimer >= 0.5f)
        {
            int plus = (int)(_energyTimer / 0.5f);
            _energy += plus;
            
            if (_energy >= _maxEnergy)
            {
                _energy = _maxEnergy;
                _energyTimer = 0.0f;
            }
            else
                _energyTimer -= plus * 0.05f; 
        }
    }
    
    if (_name == "ship01")
        updateShip01();
    else if (_name == "ship02")
        updateShip02();

    if (_fireSleep > 0.0f)
        _fireSleep -= delta;
    if (_specialSleep > 0.0f)
        _specialSleep -= delta;
    if (_rotationSleep > 0.0f)
        _rotationSleep -= delta;

    float secs = delta / 1000.0f;

    // Calculate moviment
    CL_Vec2f forces;
    if (_isPropulsionActive)
    {
        forces += newVectorBySizeAndAngle(SHIP_PROPULSION_INTENSITY, _sprite.get_angle().to_radians());
    }

    CL_Vec2f acceleration = forces / _mass;
    CL_Vec2f accelSecs = acceleration * secs;
    _position += truncateVector((_velocity + accelSecs / 2) * secs, _maxSpeed);
    _velocity = truncateVector(_velocity + accelSecs, _maxSpeed);

    if (_velocity.length() != 0.0f)
        _direction = CL_Vec2f::normalize(_velocity);

    if ((int)_position.x < -_sprite.get_width())
        _position.x = (float)SCREEN_WIDTH;
    if ((int)_position.x > SCREEN_WIDTH + _sprite.get_width())
        _position.x = 0.0f;
    if ((int)_position.y < -_sprite.get_height())
        _position.y = (float)SCREEN_HEIGHT;
    if ((int)_position.y > SCREEN_HEIGHT + _sprite.get_height())
        _position.y = 0.0f;
}

void Ship::draw()
{
    _sprite.draw(_kernel->getGraphicContext(), (int)_position.x, (int)_position.y);

    if (DEBUG)
        getCollisionOutline().draw(0, 0, CL_Colorf::darkorange, _kernel->getGraphicContext());
}

END_NAMESPACE
