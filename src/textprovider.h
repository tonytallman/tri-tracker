#ifndef TEXTPROVIDER
#define TEXTPROVIDER

typedef enum {
  TEXT_TITLE,
  TEXT_SPLASHSCREENINSTRUCTIONS
} TextID;

char *GetText(TextID textID);

#endif