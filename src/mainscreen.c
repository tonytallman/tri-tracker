#include <pebble.h>
#include "mainscreen.h"
#include "textprovider.h"

MenuLayer *_mainScreenMenuLayer;
typedef enum
{
  MainScreenMenuItemStartRace = 0,
  MainScreenMenuItemSettings,
  MainScreenMenuItemHistory,
  MainScreenMenuItemAbout,
  MainScreenMenuItemCount
} MainScreenMenuItem;
callback _startRaceHandler;
callback _settingsHandler;
callback _historyHandler;
callback _aboutHandler;

static uint16_t MainScreenGetNumberOfSections(MenuLayer *menu_layer, void *data) {
  return 1;
}

static uint16_t MainScreenGetNumberOfRows(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return MainScreenMenuItemCount;
}

static int16_t MainScreenGetHeaderHeight(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return 0;
}

static void MainScreenDrawHeader(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
}

static void MainScreenDrawRow(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  char *title = NULL;
  char *subtitle = NULL;

  switch (cell_index->row) {
    case MainScreenMenuItemStartRace:
      title = GetText(TEXT_StartRaceMenuItemTitle);
      subtitle = GetText(TEXT_StartRaceMenuItemSubtitle);
      break;

    case MainScreenMenuItemSettings:
      title = GetText(TEXT_SettingsMenuItemTitle);
      subtitle = GetText(TEXT_SettingsMenuItemSubtitle);
      break;

    case MainScreenMenuItemHistory:
      title = GetText(TEXT_HistoryMenuItemTitle);
      subtitle = GetText(TEXT_HistoryMenuItemSubtitle);
      break;
    
    case MainScreenMenuItemAbout:
      title = GetText(TEXT_AboutMenuItemTitle);
      subtitle = GetText(TEXT_AboutMenuItemSubtitle);
      break;
  }
  
  menu_cell_basic_draw(ctx, cell_layer, title, subtitle, NULL);
}

void MainScreenMenuItemSelectedHandler(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
    case MainScreenMenuItemStartRace:
      _startRaceHandler();
      break;

    case MainScreenMenuItemSettings:
      _settingsHandler();
      break;

    case MainScreenMenuItemHistory:
      _historyHandler();
      break;
    
    case MainScreenMenuItemAbout:
      _aboutHandler();
      break;
  }
}

void MainScreenLoad(Window *window) {
  Layer *rootLayer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(rootLayer);

  _mainScreenMenuLayer = menu_layer_create(bounds);

  // Set all the callbacks for the menu layer
  menu_layer_set_callbacks(_mainScreenMenuLayer, NULL, (MenuLayerCallbacks){
    .get_num_sections = MainScreenGetNumberOfSections,
    .get_num_rows = MainScreenGetNumberOfRows,
    .get_header_height = MainScreenGetHeaderHeight,
    .draw_header = MainScreenDrawHeader,
    .draw_row = MainScreenDrawRow,
    .select_click = MainScreenMenuItemSelectedHandler,
  });

  menu_layer_set_click_config_onto_window(_mainScreenMenuLayer, window);
  layer_add_child(rootLayer, menu_layer_get_layer(_mainScreenMenuLayer));
}

void MainScreenUnload(Window *window) {
  menu_layer_destroy(_mainScreenMenuLayer);
  window_destroy(window);
}

Window* CreateMainScreen(callback startRaceHandler, callback settingsHandler, callback historyHandler, callback aboutHandler) {
  _startRaceHandler = startRaceHandler;
  _settingsHandler = settingsHandler;
  _historyHandler = historyHandler;
  _aboutHandler = aboutHandler;

  Window *window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = MainScreenLoad,
    .unload = MainScreenUnload,
  });

  return window;
}
