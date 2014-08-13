#include <pebble.h>
#include "racedefinition.h"
#include "splashscreen.h"
#include "mainscreen.h"
#include "selectrace.h"
#include "comingsoon.h"

Window *_splashScreenWindow;
Window *_mainScreenWindow;
Window *_selectRaceScreenWindow;
Window *_comingSoonScreenWindow;

bool _splashScreenHasBeenDismissed;
void ShowSplashScreen();

void ShowComingSoonScreen() {
  _comingSoonScreenWindow = CreateComingSoonScreen();
  window_stack_push(_comingSoonScreenWindow, true);
}

void RaceSelected(RaceDefinition race) {
  ShowComingSoonScreen();
}

void ShowSelectRaceScreen() {
  _selectRaceScreenWindow = CreateSelectRaceScreen(RaceSelected);
  window_stack_push(_selectRaceScreenWindow, true);
}

void ShowMainScreen() {
  _mainScreenWindow = CreateMainScreen(ShowSelectRaceScreen, ShowComingSoonScreen, ShowComingSoonScreen, ShowComingSoonScreen);
  window_stack_push(_mainScreenWindow, true);
  window_stack_remove(_splashScreenWindow, false);
}

void ShowSplashScreen() {
  _splashScreenWindow = CreateSplashScreen(ShowMainScreen);
  window_stack_push(_splashScreenWindow, false);
}

void DirectorStart() {
  ShowSplashScreen();
}

void DirectorEnd() {
}
