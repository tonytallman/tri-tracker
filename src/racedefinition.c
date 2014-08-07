#include <pebble.h>
#include "racedefinition.h"

struct RaceDefinitionStruct
{
  int NumberOfSegments;
  RaceSegment Segments[];
};
