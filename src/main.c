#include <pebble.h>
#include "main.h"
#include "splashscreen.h"

bool _isInSplashScreen;

void init(void) {
  ShowSplashScreen();
  _isInSplashScreen = true;
}

void deinit(void) {
  CloseSplashScreen();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
