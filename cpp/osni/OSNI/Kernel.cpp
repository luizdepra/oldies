#include "Kernel.h"

BEGIN_NAMESPACE

Kernel::Kernel()
: _isRunning(true)
{
    CL_DisplayWindowDescription desc;
    desc.set_title(GAME_NAME);
    desc.set_size(CL_Size(SCREEN_WIDTH, SCREEN_HEIGHT), true);
    desc.set_allow_resize(false);

    _displayWindow = CL_DisplayWindow(desc);

    _inputContext = _displayWindow.get_ic();

    _graphicContext = _displayWindow.get_gc();

    _resourceManager = CL_ResourceManager("Resource/resource.xml");

    _sceneManager = SceneManager();
}

Kernel::~Kernel()
{
}

Kernel *Kernel::getInstance()
{
    static Kernel kernel;
    return &kernel;
}

bool Kernel::isRunning() const
{
    return _isRunning;
}

void Kernel::shutdown()
{
    _isRunning = false;
}

CL_GraphicContext Kernel::getGraphicContext() const
{
    return _graphicContext;
}

CL_DisplayWindow Kernel::getDisplayWindow() const
{
    return _displayWindow;
}

CL_InputContext Kernel::getInputContext() const
{
    return _inputContext;
}

CL_ResourceManager Kernel::getResourceManager() const
{
    return _resourceManager;
}

SceneManager &Kernel::getSceneMenager()
{
    return _sceneManager;
}

END_NAMESPACE