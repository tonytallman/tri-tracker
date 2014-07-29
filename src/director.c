#include <pebble.h>
#include "splashscreen.h"
#include "mainscreen.h"

Window *_splashScreenWindow;
Window *_mainScreenWindow;
bool _splashScreenHasBeenDismissed;

void ShowMainScreen() {
  _mainScreenWindow = CreateMainScreen();
  window_stack_push(_mainScreenWindow, true);
  window_stack_remove(_splashScreenWindow, false);
}

void ShowSplashScreen() {
  _splashScreenWindow = CreateSplashScreen(ShowMainScreen);
  window_stack_push(_splashScreenWindow, false);
}

void DirectorStart() {
  ShowSplashScreen();
}

void DirectorEnd() {
}
