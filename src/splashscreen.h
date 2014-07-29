#ifndef SPLASHSCREEN
#define SPLASHSCREEN
#include "common.h"
  
Window* CreateSplashScreen(callback doneHandler);
void DisposeSplashScreen(Window *splashScreenWindow);

#endif