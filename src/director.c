#include <pebble.h>
#include "splashscreen.h"

Window *_splashScreenWindow;
AppTimer *_splashScreenTimer;
bool _splashScreenHasBeenDismissed;

void DismissSplashScreen() {
  if (!_splashScreenHasBeenDismissed) {
    _splashScreenHasBeenDismissed = true;
    app_timer_cancel(_splashScreenTimer);
    window_stack_remove(_splashScreenWindow, false);
    DestroySplashScreen(_splashScreenWindow);
  }
}

void SplashScreenTimerCallback(void *data) {
  DismissSplashScreen();
}

void DirectorStart() {
  _splashScreenWindow = CreateSplashScreen(DismissSplashScreen);
  window_stack_push(_splashScreenWindow, false);
  _splashScreenTimer = app_timer_register(3000, SplashScreenTimerCallback, NULL);
}

void DirectorEnd() {
  DismissSplashScreen();
}
