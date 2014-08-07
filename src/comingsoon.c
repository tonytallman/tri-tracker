#include <pebble.h>
#include "comingsoon.h"
#include "textprovider.h"
#include "theme.h"

TextLayer *_comingSoonTitleTextLayer;

void ComingSoonScreenLoad(Window *window) {
  Layer *windowLayer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(windowLayer);
  
  GRect titleLayerBounds = bounds;
  _comingSoonTitleTextLayer = text_layer_create(titleLayerBounds);
  char *title = GetText(TEXT_ComingSoon);
  text_layer_set_text(_comingSoonTitleTextLayer, title);
  text_layer_set_text_alignment(_comingSoonTitleTextLayer, GTextAlignmentCenter);
  text_layer_set_font(_comingSoonTitleTextLayer, GetHeadingFont());
  layer_add_child(windowLayer, text_layer_get_layer(_comingSoonTitleTextLayer));
}
 
void ComingSoonScreenUnload(Window *window) {
  text_layer_destroy(_comingSoonTitleTextLayer);
  window_destroy(window);
}
 
Window* CreateComingSoonScreen() {
  Window *window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = ComingSoonScreenLoad,
    .unload = ComingSoonScreenUnload,
  });

  return window;
}
