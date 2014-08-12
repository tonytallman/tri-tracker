#pragma once
#include "distance.h"

typedef enum
{
  RaceSegmentType_Transition = 0,
  RaceSegmentType_Swim,
  RaceSegmentType_Bike,
  RaceSegmentType_Run
} RaceSegmentType;

typedef struct
{
  RaceSegmentType Type;
  Distance Distance;
} RaceSegment;

struct RaceDefinitionStruct;
typedef struct RaceDefinitionStruct RaceDefinition;

RaceDefinition* RaceDefinitionCreateTriathlon(Distance swimDistance, Distance bikeDistance, Distance runDistance);
void RaceDefinitionDestroy(RaceDefinition *race);
int RaceDefinitionGetNumberOfSegments(RaceDefinition *race);
RaceSegment* RaceDefinitionGetRaceSegment(RaceDefinition *race, int segmentNumber);
