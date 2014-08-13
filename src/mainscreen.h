#ifndef MAINSCREEN
#define MAINSCREEN

#include <pebble.h>
#include "common.h"

Window* CreateMainScreen(callback startRaceHandler, callback settingsHandler, callback historyHandler, callback aboutHandler);

#endif