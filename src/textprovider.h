#ifndef TEXTPROVIDER
#define TEXTPROVIDER

typedef enum {
  TEXT_Title,
  TEXT_StartRaceMenuItemTitle,
  TEXT_StartRaceMenuItemSubtitle,
  TEXT_SettingsMenuItemTitle,
  TEXT_SettingsMenuItemSubtitle,
  TEXT_HistoryMenuItemTitle,
  TEXT_HistoryMenuItemSubtitle,
  TEXT_AboutMenuItemTitle,
  TEXT_AboutMenuItemSubtitle,
} TextID;

char *GetText(TextID textID);

#endif