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
  TEXT_SprintTriathlon,
  TEXT_OlympicTriathlon,
  TEXT_HalfIronmanTriathlon,
  TEXT_IronmanTriathlon,
  TEXT_SelectRaceDistance,
  TEXT_ComingSoon
} TextID;

char *GetText(TextID textID);

#endif