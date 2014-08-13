#ifndef SELECTRACE
#define SELECTRACE

#include <pebble.h>
#include "racedefinition.h"

typedef void (*selectRaceCallback)(RaceDefinition race);
Window* CreateSelectRaceScreen(selectRaceCallback callback);

#endif