#include <pebble.h>
#include "splashscreen.h"

Window *_splashScreenWindow;
bool _isInSplashScreen;
AppTimer *_splashScreenTimer;

void DismissSplashScreen() {
  if (_isInSplashScreen) {
    _isInSplashScreen = false;
    window_stack_pop(false);
    DestroySplashScreen(_splashScreenWindow);
    app_timer_cancel(_splashScreenTimer);
  }
}

void SplashScreenTimerCallback(void *data) {
  DismissSplashScreen();
}

void StartSplashScreenTimer() {
  _splashScreenTimer = app_timer_register(3000, SplashScreenTimerCallback, NULL);
}

void DirectorStart() {
  _splashScreenWindow = CreateSplashScreen(DismissSplashScreen);
  window_stack_push(_splashScreenWindow, false);
  _isInSplashScreen = true;
  StartSplashScreenTimer();
}

void DirectorEnd() {
  if (_isInSplashScreen) {
    _isInSplashScreen = false;
    DestroySplashScreen(_splashScreenWindow);
  }
}
