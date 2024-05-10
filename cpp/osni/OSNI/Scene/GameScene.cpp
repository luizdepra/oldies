#include "GameScene.h"

BEGIN_NAMESPACE

bool isLaserOutOfBounds(Laser *laser)
{
    return (laser->getPosition().x < -50 || laser->getPosition().x > SCREEN_WIDTH + 50 ||
            laser->getPosition().y < -50 || laser->getPosition().y > SCREEN_HEIGHT + 50);
}

bool isAsteroidOutOfBounds(Asteroid *asteroid)
{
    return (asteroid->getPosition().x < -100 || asteroid->getPosition().x > SCREEN_WIDTH + 100 ||
            asteroid->getPosition().y < -100 || asteroid->getPosition().y > SCREEN_HEIGHT + 100);
}

bool isLaserMarkedToDeletion(Laser *laser)
{
    return laser->isMarkedToDeletion();
}

bool isMissileMarkedToDeletion(Missile *missile)
{
    return missile->isMarkedToDeletion();
}

bool isFlareMarkedToDeletion(Flare *flare)
{
    return flare->isMarkedToDeletion();
}

bool isExplosionMarkedToDeletion(Explosion *explosion)
{
    return explosion->isMarkedToDeletion();
}

bool isAsteroidMarkedToDeletion(Asteroid *asteroid)
{
    return asteroid->isMarkedToDeletion();
}

GameScene::GameScene()
    : Scene("GameScene"), _background(CL_Sprite(_kernel->getGraphicContext(), "background", &_kernel->getResourceManager()))
{
    CL_Callback_2<void, const CL_Vec2f &, float> ship01Fire;
    ship01Fire.set(this, &GameScene::ship01FireCallback);

    CL_Callback_2<void, const CL_Vec2f &, float> ship02Fire;
    ship02Fire.set(this, &GameScene::ship02FireCallback);

    CL_Callback_2<void, const Ship &, float> ship01Special;
    ship01Special.set(this, &GameScene::missileCallback);

    CL_Callback_2<void, const Ship &, float> ship02Special;
    ship02Special.set(this, &GameScene::flareCallback);

    _ship01 = new Ship(CL_Vec2f(50.0f, 50.0f), "ship01", ship01Fire, ship01Special);
    _ship02 = new Ship(CL_Vec2f(SCREEN_WIDTH - 50.0f, SCREEN_HEIGHT - 50.0f), "ship02", ship02Fire, ship02Special);

    _health01Bar = new Bar(CL_Vec2f(10, SCREEN_HEIGHT - 30));
    _health02Bar = new Bar(CL_Vec2f(SCREEN_WIDTH - 20, 10));
    _energy01Bar = new Bar(CL_Vec2f(10, SCREEN_HEIGHT - 20));
    _energy02Bar = new Bar(CL_Vec2f(SCREEN_WIDTH - 30, 10));
    
    _asteroidTimer = rand() % 9900 + 100.0f;
}

GameScene::~GameScene()
{
    _ship01Laser.clear();
    _ship02Laser.clear();

    _missileList.clear();
    _flareList.clear();

    _explosionList.clear();
    
    if (_ship01)
        delete _ship01;

    if (_ship02)
        delete _ship02;
}

void GameScene::ship01FireCallback(const CL_Vec2f &pos, float angle)
{
    CL_Vec2f newPos = pos + CL_Vec2f(_ship01->getWidth() / 2.0f, _ship01->getHeight() / 2.0f); // Vetor para o meio da nave
    newPos += CL_Vec2f(-4.0f, -1.0f); // Arruma a posição de acordo com o tamanho do tiro
    newPos += CL_Vec2f(_ship01->getWidth() / 2.0f, 0.0f).rotate(CL_Vec2f(), CL_Angle::from_radians(angle)); // Move para a frente da nave e rotaciona
    
    _ship01Laser.push_back(new Laser(newPos, angle));
}

void GameScene::ship02FireCallback(const CL_Vec2f &pos, float angle)
{
    CL_Vec2f newPos = pos + CL_Vec2f(_ship02->getWidth() / 2.0f, _ship02->getHeight() / 2.0f); // Vetor para o meio da nave
    newPos += CL_Vec2f(-4.0f, -1.0f); // Arruma a posição de acordo com o tamanho do tiro
    newPos += CL_Vec2f(_ship02->getWidth() / 2.0f, 0.0f).rotate(CL_Vec2f(), CL_Angle::from_radians(angle)); // Move para a frente da nave e rotaciona

    _ship02Laser.push_back(new Laser(newPos, angle));
}

void GameScene::missileCallback(const Ship &ship, float angle)
{
    CL_Vec2f newPos = ship.getPosition() + CL_Vec2f(_ship01->getWidth() / 2.0f, _ship01->getHeight() / 2.0f);
    newPos += CL_Vec2f(-3.0f, -2.0f);
    newPos += CL_Vec2f(_ship01->getWidth() / 2.0f, 0.0f).rotate(CL_Vec2f(), CL_Angle::from_radians(angle));

    Missile *missile = new Missile(newPos, angle, _ship02);

    _missileList.push_back(missile);
}

void GameScene::flareCallback(const Ship &ship, float angle)
{
    CL_Vec2f newPos = ship.getPosition() + CL_Vec2f(_ship01->getWidth() / 2.0f, _ship01->getHeight() / 2.0f);
    newPos += CL_Vec2f(2.0f, 2.0f);
    newPos += CL_Vec2f(-_ship01->getWidth() / 2.0f, 0.0f).rotate(CL_Vec2f(), CL_Angle::from_radians(angle));

    Flare *flare = new Flare(newPos, angle, _ship02);

    _flareList.push_back(flare);
}

void GameScene::spawnExplosion(Entity *projectile, bool isMissileExplosion)
{
    CL_Vec2f newPos = projectile->getPosition() + CL_Vec2f(projectile->getWidth(), projectile->getHeight() / 2);

    Explosion *explosion = new Explosion(newPos, isMissileExplosion);

    _explosionList.push_back(explosion);
}

void GameScene::spawnAsteroid()
{
    _asteroidTimer = rand() % 9900 + 100.0f;

    CL_Vec2f pos;
    float angle;

    switch (rand() % 4)
    {
    case 0:
        pos = CL_Vec2f(rand() % SCREEN_WIDTH, -32.0f);
        angle = 1.57f;
        break;
    case 1:
        pos = CL_Vec2f(rand() % SCREEN_WIDTH, SCREEN_HEIGHT + 32.0f);
        angle = 4.71f;
        break;
    case 2:
        pos = CL_Vec2f(-32.0f, rand() % SCREEN_HEIGHT);
        angle = 0.0f;
        break;
    default:
        pos = CL_Vec2f(SCREEN_WIDTH + 32.0f, rand() % SCREEN_HEIGHT);
        angle = 3.14f;
        break;
    }

    _asteroidList.push_back(new Asteroid(pos, angle, rand() % 3 + 1));
}

void GameScene::removeLostLasers()
{
    _ship01Laser.remove_if(isLaserOutOfBounds);

    _ship02Laser.remove_if(isLaserOutOfBounds);
}

void GameScene::removeLostAsteroids()
{
    _asteroidList.remove_if(isAsteroidOutOfBounds);
}

void GameScene::checkCollisions()
{
    for(std::list<Laser *>::iterator iterator = _ship01Laser.begin(); 
        iterator != _ship01Laser.end(); iterator++)
    {
        if (_ship02->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
        {
            spawnExplosion((*iterator));

            (*iterator)->markToDeletion();

            _ship02->takeDamage();
        }

        for(std::list<Asteroid *>::iterator asteroid = _asteroidList.begin(); 
            asteroid != _asteroidList.end(); asteroid++)
        {
            if ((*asteroid)->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
            {
                spawnExplosion((*asteroid));

                (*asteroid)->markToDeletion();
            }
        }
    }

    for(std::list<Laser *>::iterator iterator = _ship02Laser.begin(); 
        iterator != _ship02Laser.end(); iterator++)
    {
        if (_ship01->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
        {
            spawnExplosion((*iterator));

            (*iterator)->markToDeletion();

            _ship01->takeDamage(2);
        }

        for(std::list<Asteroid *>::iterator asteroid = _asteroidList.begin(); 
            asteroid != _asteroidList.end(); asteroid++)
        {
            if ((*asteroid)->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
            {
                spawnExplosion((*asteroid));

                (*asteroid)->markToDeletion();
            }
        }
    }

    for(std::list<Missile *>::iterator iterator = _missileList.begin(); 
        iterator != _missileList.end(); iterator++)
    {
        if (_ship02->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
        {
            spawnExplosion((*iterator), true);

            (*iterator)->markToDeletion();
        }
    }

    for(std::list<Explosion *>::iterator iterator = _explosionList.begin(); 
        iterator != _explosionList.end(); iterator++)
    {
        if ((*iterator)->isMissileExplosion())
        {
            if (_ship01->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
            {
                _ship01->takeDamage(3);
            }

            if (_ship02->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
            {
                _ship02->takeDamage(3);
            }

            for(std::list<Asteroid *>::iterator asteroid = _asteroidList.begin(); 
                asteroid != _asteroidList.end(); asteroid++)
            {
                if ((*asteroid)->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
                {
                    spawnExplosion((*asteroid));

                    (*asteroid)->markToDeletion();
                }
            }

        }
    }

    for(std::list<Asteroid *>::iterator iterator = _asteroidList.begin(); 
        iterator != _asteroidList.end(); iterator++)
    {
        if (_ship01->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
        {
            spawnExplosion((*iterator));

            _ship01->takeDamage(1);

            (*iterator)->markToDeletion();
        }
        else if (_ship02->getCollisionOutline().collide((*iterator)->getCollisionOutline()))
        {
            spawnExplosion((*iterator));

            _ship02->takeDamage(1);

            (*iterator)->markToDeletion();
        }
    }
}

void GameScene::correctMissilesTargets()
{
    for(std::list<Missile *>::iterator iterator = _missileList.begin(); 
        iterator != _missileList.end(); iterator++)
    {
        if ((*iterator)->getTarget() && (*iterator)->getTarget()->isMarkedToDeletion())
            (*iterator)->setTarget(NULL);
    }
}

void GameScene::update(float delta)
{
    _ship01->update(delta);
    _ship02->update(delta);

    for(std::list<Laser *>::iterator iterator = _ship01Laser.begin(); 
        iterator != _ship01Laser.end(); iterator++)
    {
        (*iterator)->update(delta);
    }

    for(std::list<Laser *>::iterator iterator = _ship02Laser.begin(); 
        iterator != _ship02Laser.end(); iterator++)
    {
        (*iterator)->update(delta);
    }

    for(std::list<Missile *>::iterator iterator = _missileList.begin(); 
        iterator != _missileList.end(); iterator++)
    {
        if (!(*iterator)->changedTarget() && _flareList.size() > 0)
            (*iterator)->setTarget(_flareList.back());

        (*iterator)->update(delta);

        if ((*iterator)->isMarkedToDeletion())
            spawnExplosion((*iterator), true);
    }

    for(std::list<Flare *>::iterator iterator = _flareList.begin(); 
        iterator != _flareList.end(); iterator++)
    {
        (*iterator)->update(delta);
    }

    for(std::list<Explosion *>::iterator iterator = _explosionList.begin(); 
        iterator != _explosionList.end(); iterator++)
    {
        (*iterator)->update(delta);
    }

    for(std::list<Asteroid *>::iterator iterator = _asteroidList.begin(); 
        iterator != _asteroidList.end(); iterator++)
    {
        (*iterator)->update(delta);
    }

    _asteroidTimer -= delta;
    if (_asteroidTimer <= 0.0f)
        spawnAsteroid();

    checkCollisions();
    correctMissilesTargets();

    _health01Bar->setValue(ship01->getHealth());
    _energy01Bar->setValue(ship01->getEnergy());
    
    _health02Bar->setValue(ship02->getHealth());
    _energy02Bar->setValue(ship02->getEnergy());
    
    removeLostLasers();
    removeLostAsteroids();

    _ship01Laser.remove_if(isLaserMarkedToDeletion);
    _ship02Laser.remove_if(isLaserMarkedToDeletion);
    _missileList.remove_if(isMissileMarkedToDeletion);
    _flareList.remove_if(isFlareMarkedToDeletion);
    _explosionList.remove_if(isExplosionMarkedToDeletion);
    _asteroidList.remove_if(isAsteroidMarkedToDeletion);
}

void GameScene::draw()
{
    _background.draw(_kernel->getGraphicContext(), 0, 0);

    _ship01->draw();
    _ship02->draw();

    for(std::list<Laser *>::iterator iterator = _ship01Laser.begin(); 
        iterator != _ship01Laser.end(); iterator++)
        (*iterator)->draw();

    for(std::list<Laser *>::iterator iterator = _ship02Laser.begin();
        iterator != _ship02Laser.end(); iterator++)
        (*iterator)->draw();

    for(std::list<Missile *>::iterator iterator = _missileList.begin(); 
        iterator != _missileList.end(); iterator++)
        (*iterator)->draw();

    for(std::list<Flare *>::iterator iterator = _flareList.begin(); 
        iterator != _flareList.end(); iterator++)
        (*iterator)->draw();

    for(std::list<Explosion *>::iterator iterator = _explosionList.begin(); 
        iterator != _explosionList.end(); iterator++)
        (*iterator)->draw();

    for(std::list<Asteroid *>::iterator iterator = _asteroidList.begin(); 
        iterator != _asteroidList.end(); iterator++)
        (*iterator)->draw();
        
    _health01Bar->draw();
    _health02Bar->draw();
    _energy01Bar->draw();
    _energy02Bar->draw();
}

END_NAMESPACE
