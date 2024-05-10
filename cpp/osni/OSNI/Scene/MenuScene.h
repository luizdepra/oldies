#ifndef __OSNI_MENU_SCENE_H__
#define __OSNI_MENU_SCENE_H__

#include "Scene.h"

BEGIN_NAMESPACE

class MenuScene :
    public Scene
{
public:
    MenuScene();
    ~MenuScene();

    void update(float delta);
    void draw();

private:
    CL_Sprite _background;
};

END_NAMESPACE

#endif


