#include <pebble.h>
#include "splashscreen.h"
#include "mainscreen.h"

Window *_splashScreenWindow;
Window *_mainScreenWindow;
AppTimer *_splashScreenTimer;
bool _splashScreenHasBeenDismissed;

void ShowMainScreen() {
  _mainScreenWindow = CreateMainScreen();
  window_stack_push(_mainScreenWindow, true);
}

void DismissSplashScreen() {
  if (!_splashScreenHasBeenDismissed) {
    _splashScreenHasBeenDismissed = true;
    app_timer_cancel(_splashScreenTimer);
    ShowMainScreen();
    window_stack_remove(_splashScreenWindow, false);
    DisposeSplashScreen(_splashScreenWindow);
  }
}

void SplashScreenTimerCallback(void *data) {
  DismissSplashScreen();
}

void ShowSplashScreen() {
  _splashScreenWindow = CreateSplashScreen(DismissSplashScreen);
  window_stack_push(_splashScreenWindow, false);
  _splashScreenTimer = app_timer_register(3000, SplashScreenTimerCallback, NULL);
}

void DirectorStart() {
  ShowSplashScreen();
}

void DirectorEnd() {
  window_stack_remove(_splashScreenWindow, false);
//  DisposeSplashScreen(_splashScreenWindow);
  window_stack_remove(_mainScreenWindow, false);
  DisposeMainScreen(_mainScreenWindow);
}
