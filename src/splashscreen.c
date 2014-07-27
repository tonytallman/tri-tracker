#include <pebble.h>
#include "textprovider.h"
#include "splashscreen.h"

callback _splashScreenDoneHandler;
TextLayer *_instructionsTextLayer;
BitmapLayer *_splashScreenBitmapLayer;
GBitmap *_splashScreenImage;
 
void SplashScreenLoad(Window *window) {
  Layer *windowLayer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(windowLayer);
  
  _splashScreenBitmapLayer = bitmap_layer_create(bounds);
  _splashScreenImage = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_SPLASHSCREEN);
  bitmap_layer_set_bitmap(_splashScreenBitmapLayer, _splashScreenImage);
  layer_add_child(windowLayer, bitmap_layer_get_layer(_splashScreenBitmapLayer));
  
  GRect instructionsLayerBounds = bounds;
  instructionsLayerBounds.origin.y = bounds.origin.y + bounds.size.h - 48;
  instructionsLayerBounds.size.h = 48;
  _instructionsTextLayer = text_layer_create(instructionsLayerBounds);
  char *instructions = GetText(TEXT_SPLASHSCREENINSTRUCTIONS);
  text_layer_set_text(_instructionsTextLayer, instructions);
  text_layer_set_text_alignment(_instructionsTextLayer, GTextAlignmentCenter);
  layer_add_child(windowLayer, text_layer_get_layer(_instructionsTextLayer));
}
 
void SplashScreenUnload(Window *window) {
  text_layer_destroy(_instructionsTextLayer);
  gbitmap_destroy(_splashScreenImage);
  bitmap_layer_destroy(_splashScreenBitmapLayer);
}

void SplashScreenButtonHandler(ClickRecognizerRef recognizer, void *context) {
  // Dismiss splash screen when any button is pressed.
  _splashScreenDoneHandler();
}

void SplashScreenClickConfigProvider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, SplashScreenButtonHandler);
  window_single_click_subscribe(BUTTON_ID_UP, SplashScreenButtonHandler);
  window_single_click_subscribe(BUTTON_ID_DOWN, SplashScreenButtonHandler);
}
 
Window* CreateSplashScreen(callback doneHandler) {
  _splashScreenDoneHandler = doneHandler;
  
  Window *splashScreenWindow = window_create();
  window_set_window_handlers(splashScreenWindow, (WindowHandlers) {
    .load = SplashScreenLoad,
    .unload = SplashScreenUnload,
  });

  window_set_click_config_provider(splashScreenWindow, SplashScreenClickConfigProvider);

  return splashScreenWindow;
}

void DestroySplashScreen(Window *splashScreenWindow) {
  window_destroy(splashScreenWindow);
}
