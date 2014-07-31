#include <pebble.h>
#include "theme.h"

GFont* GetHeadingFont() {
  return fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
}

int GetHeadingFontSize() {
  return 28;
}

GFont* GetBodyFont() {
  return fonts_get_system_font(FONT_KEY_GOTHIC_18);
}

int GetBodyFontSize() {
  return 18;
}
