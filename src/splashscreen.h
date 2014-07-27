#ifndef SPLASHSCREEN
#define SPLASHSCREEN
#include "common.h"
  
Window* CreateSplashScreen(callback doneHandler);
void DestroySplashScreen(Window *splashScreenWindow);

#endif