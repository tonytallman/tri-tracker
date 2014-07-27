#include <pebble.h>
#include "director.h"

void init(void) {
  DirectorStart();
}

void deinit(void) {
  DirectorEnd();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
