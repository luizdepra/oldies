#include "Scene.h"

#include "../Kernel.h"

BEGIN_NAMESPACE

Scene::Scene()
    : _name("Scene"), _kernel(Kernel::getInstance())
{
}

Scene::Scene(const CL_String &name)
    : _name(name), _kernel(Kernel::getInstance())
{
}

Scene::~Scene()
{
}

CL_String Scene::getName() const
{
    return _name;
}

END_NAMESPACE
