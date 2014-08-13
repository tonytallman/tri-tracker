#include <pebble.h>
#include "selectrace.h"
#include "textprovider.h"
#include "racedefinition.h"

MenuLayer *_selectRaceScreenMenuLayer;
typedef enum
{
  SelectRaceScreenMenuItemSprintTriathlon = 0,
  SelectRaceScreenMenuItemOlympicTriathlon,
  SelectRaceScreenMenuItemHalfIronmanTriathlon,
  SelectRaceScreenMenuItemIronmanTriathlon,
  SelectRaceScreenMenuItemCount
} SelectRaceScreenMenuItem;
selectRaceCallback _selectHandler;

static uint16_t SelectRaceScreenGetNumberOfSections(MenuLayer *menu_layer, void *data) {
  return 1;
}

static uint16_t SelectRaceScreenGetNumberOfRows(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return SelectRaceScreenMenuItemCount;
}

static int16_t SelectRaceScreenGetHeaderHeight(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  return MENU_CELL_BASIC_HEADER_HEIGHT;
}

static void SelectRaceScreenDrawHeader(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
  menu_cell_basic_header_draw(ctx, cell_layer, GetText(TEXT_SelectRaceDistance));
}

static void SelectRaceScreenDrawRow(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  char *title = NULL;
  char *subtitle = NULL;

  switch (cell_index->row) {
    case SelectRaceScreenMenuItemSprintTriathlon:
      title = GetText(TEXT_SprintTriathlon);
      break;

    case SelectRaceScreenMenuItemOlympicTriathlon:
      title = GetText(TEXT_OlympicTriathlon);
      break;

    case SelectRaceScreenMenuItemHalfIronmanTriathlon:
      title = GetText(TEXT_HalfIronmanTriathlon);
      break;
    
    case SelectRaceScreenMenuItemIronmanTriathlon:
      title = GetText(TEXT_IronmanTriathlon);
      break;
  }
  
  menu_cell_basic_draw(ctx, cell_layer, title, subtitle, NULL);
}

void SelectRaceScreenMenuItemSelectedHandler(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {
  switch (cell_index->row) {
    case SelectRaceScreenMenuItemSprintTriathlon:
      _selectHandler(GetSprintTriathlonDefinition());
      break;

    case SelectRaceScreenMenuItemOlympicTriathlon:
      _selectHandler(GetOlympicTriathlonDefinition());
      break;

    case SelectRaceScreenMenuItemHalfIronmanTriathlon:
      _selectHandler(GetHalfIronmanTriathlonDefinition());
      break;
    
    case SelectRaceScreenMenuItemIronmanTriathlon:
      _selectHandler(GetIronmanTriathlonDefinition());
      break;
  }
}

void SelectRaceScreenLoad(Window *window) {
  Layer *rootLayer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(rootLayer);

  _selectRaceScreenMenuLayer = menu_layer_create(bounds);

  // Set all the callbacks for the menu layer
  menu_layer_set_callbacks(_selectRaceScreenMenuLayer, NULL, (MenuLayerCallbacks){
    .get_num_sections = SelectRaceScreenGetNumberOfSections,
    .get_num_rows = SelectRaceScreenGetNumberOfRows,
    .get_header_height = SelectRaceScreenGetHeaderHeight,
    .draw_header = SelectRaceScreenDrawHeader,
    .draw_row = SelectRaceScreenDrawRow,
    .select_click = SelectRaceScreenMenuItemSelectedHandler,
  });

  menu_layer_set_click_config_onto_window(_selectRaceScreenMenuLayer, window);
  layer_add_child(rootLayer, menu_layer_get_layer(_selectRaceScreenMenuLayer));
}

void SelectRaceScreenUnload(Window *window) {
  menu_layer_destroy(_selectRaceScreenMenuLayer);
  window_destroy(window);
}

Window* CreateSelectRaceScreen(selectRaceCallback callback) {
  _selectHandler = callback;

  Window *window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = SelectRaceScreenLoad,
    .unload = SelectRaceScreenUnload,
  });

  return window;
}

