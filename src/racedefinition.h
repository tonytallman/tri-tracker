#ifndef RACEDEFINITION
#define RACEDEFINITION

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

typedef struct
{
  int NumberOfSegments;
  RaceSegment Segments[5];
} RaceDefinition;

RaceDefinition RaceDefinitionCreateTriathlon(const Distance swimDistance, const Distance bikeDistance, const Distance runDistance);
int RaceDefinitionGetNumberOfSegments(RaceDefinition race);
RaceSegment RaceDefinitionGetRaceSegment(RaceDefinition race, int segmentNumber);

RaceDefinition GetSprintTriathlonDefinition();
RaceDefinition GetOlympicTriathlonDefinition();
RaceDefinition GetHalfIronmanTriathlonDefinition();
RaceDefinition GetIronmanTriathlonDefinition();

#endif