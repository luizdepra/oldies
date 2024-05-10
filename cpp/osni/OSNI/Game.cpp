#include "Game.h"

#include "Scene/GameScene.h"
#include "Scene/MenuScene.h"

#include <ctime>

BEGIN_NAMESPACE

Game::Game(const std::vector<CL_String> &args)
{
    _kernel = Kernel::getInstance();

    srand(clock());
}

Game::~Game()
{
    _kernel = 0;
}

int Game::run()
{
    unsigned int currentTime, lastTime;
    int sleepTime;
    float deltaTime;

    CL_Slot slot_quit = _kernel->getDisplayWindow().sig_window_close().connect(this, &Game::close);

    // Initialize first Scene
    SceneManager &sceneManager = _kernel->getSceneMenager();

    MenuScene *menuScene = new MenuScene();
    sceneManager.addScene(menuScene);

    GameScene *gameScene = new GameScene();
    sceneManager.addScene(gameScene);

    sceneManager.changeCurrentScene("MenuScene");

    lastTime = CL_System::get_time();

    while(_kernel->isRunning())
    {
        currentTime = CL_System::get_time();
        deltaTime = (float)(currentTime - lastTime);
        lastTime = currentTime;
    
        update(deltaTime);
        draw();
        
        CL_KeepAlive::process();
        
        currentTime = CL_System::get_time();
        sleepTime = FRAMES_PER_SECOND - (currentTime - lastTime);
        //if (sleepTime > 0)
            //CL_System::sleep(sleepTime);
    }

    return 0;
}

void Game::close()
{
    _kernel->shutdown();
}

void Game::update(float delta)
{
    _kernel->getSceneMenager().update(delta);
}

void Game::draw()
{
    _kernel->getGraphicContext().clear(CL_Colorf(0.0f, 0.0f, 0.0f));

    _kernel->getSceneMenager().draw();

    _kernel->getDisplayWindow().flip();
}

END_NAMESPACE