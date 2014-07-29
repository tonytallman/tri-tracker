#ifndef TEXTPROVIDER
#define TEXTPROVIDER

typedef enum {
  TEXT_Title,
  TEXT_SPLASHSCREENINSTRUCTIONS,
  TEXT_StartRaceMenuItemTitle,
  TEXT_StartRaceMenuItemSubtitle,
  TEXT_SettingsMenuItemTitle,
  TEXT_SettingsMenuItemSubtitle,
  TEXT_HistoryMenuItemTitle,
  TEXT_HistoryMenuItemSubtitle,
} TextID;

char *GetText(TextID textID);

#endif