#include <pebble.h>
#include "textprovider.h"

char *GetText(TextID textID)
{
  switch (textID) {
    case TEXT_Title:
      return "tri-tracker";

    case TEXT_StartRaceMenuItemTitle:
      return "start race";

    case TEXT_StartRaceMenuItemSubtitle:
      return NULL;

    case TEXT_SettingsMenuItemTitle:
      return "settings";

    case TEXT_SettingsMenuItemSubtitle:
      return NULL;

    case TEXT_HistoryMenuItemTitle:
      return "history";

    case TEXT_HistoryMenuItemSubtitle:
      return "0 races saved";

    case TEXT_AboutMenuItemTitle:
      return "about";

    case TEXT_AboutMenuItemSubtitle:
      return NULL;
    
    case TEXT_ComingSoon:
      return "coming soon!";

    default:
      return "";
  }
}
