#ifndef __CLC_COMMON_H__
#define __CLC_COMMON_H__

#ifdef USE_NAMESPACE
    #define BEGIN_NAMESPACE namespace Incoming {
    #define END_NAMESPACE }
#else
    #define BEGIN_NAMESPACE
    #define END_NAMESPACE
#endif

#include <ClanLib/core.h>
#include <ClanLib/application.h>
#include <ClanLib/display.h>

BEGIN_NAMESPACE

static const CL_String GAME_NAME = "OSNI";

static const int SCREEN_WIDTH = 960;
static const int SCREEN_HEIGHT = 540;

static const bool DEBUG = true;

END_NAMESPACE

#endif