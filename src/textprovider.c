#include <pebble.h>
#include "textprovider.h"

char *GetText(TextID textID)
{
  switch (textID) {
    case TEXT_TITLE:
      return "tri-tracker";

    case TEXT_SPLASHSCREENINSTRUCTIONS:
      return "press any button to continue";
    
    default:
      return "";
  }
}
