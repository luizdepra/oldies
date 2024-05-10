#ifndef __CLC_SCENE_H__
#define __CLC_SCENE_H__

#include "../Common.h"

BEGIN_NAMESPACE

class Kernel;

class Scene
{
public:
    Scene();
    Scene(const CL_String &name);
    virtual ~Scene();

    CL_String getName() const;

    virtual void update(float delta) = 0;
    virtual void draw() = 0;

protected:
    CL_String _name;

    Kernel *_kernel;

};

END_NAMESPACE

#endif
