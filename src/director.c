#include <pebble.h>
#include "splashscreen.h"
#include "mainscreen.h"
#include "comingsoon.h"

Window *_splashScreenWindow;
Window *_mainScreenWindow;
Window *_comingSoonScreenWindow;

bool _splashScreenHasBeenDismissed;
void ShowSplashScreen();

void ShowComingSoonScreen() {
  _comingSoonScreenWindow = CreateComingSoonScreen();
  window_stack_push(_comingSoonScreenWindow, true);
}

void ShowMainScreen() {
  _mainScreenWindow = CreateMainScreen(ShowComingSoonScreen, ShowComingSoonScreen, ShowComingSoonScreen, ShowComingSoonScreen);
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
