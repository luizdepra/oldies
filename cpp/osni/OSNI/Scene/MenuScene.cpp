#include "MenuScene.h"

#include "../Kernel.h"

BEGIN_NAMESPACE

MenuScene::MenuScene()
: Scene("MenuScene"), _background(CL_Sprite(_kernel->getGraphicContext(), "menu_background", &_kernel->getResourceManager()))
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::update(float delta)
{
    CL_InputDevice keyboard = _kernel->getInputContext().get_keyboard();

    if (keyboard.get_keycode(CL_KEY_ENTER))
        _kernel->getSceneMenager().changeCurrentScene("GameScene");
}

void MenuScene::draw()
{
    _background.draw(_kernel->getGraphicContext(), 0, 0);
}

END_NAMESPACE
