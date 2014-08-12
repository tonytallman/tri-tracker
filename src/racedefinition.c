#include <pebble.h>
#include "racedefinition.h"
#include "distance.h"

struct RaceDefinitionStruct
{
  int NumberOfSegments;
  RaceSegment Segments[5];
};

RaceDefinition* RaceDefinitionCreateTriathlon(Distance swimDistance, Distance bikeDistance, Distance runDistance)
{
  RaceDefinition *race = malloc(sizeof(RaceDefinition));
  race->NumberOfSegments = 5;

  race->Segments[0].Type = RaceSegmentType_Swim;
  race->Segments[0].Distance = swimDistance;

  race->Segments[1].Type = RaceSegmentType_Transition;
  race->Segments[1].Distance = DistanceZero;

  race->Segments[2].Type = RaceSegmentType_Bike;
  race->Segments[2].Distance = bikeDistance;

  race->Segments[3].Type = RaceSegmentType_Transition;
  race->Segments[3].Distance = DistanceZero;

  race->Segments[4].Type = RaceSegmentType_Run;
  race->Segments[4].Distance = runDistance;

  return race;
}

void RaceDefinitionDestroy(RaceDefinition *race)
{
  free(race);
}

int RaceDefinitionGetNumberOfSegments(RaceDefinition *race)
{
  return race->NumberOfSegments;
}

RaceSegment* RaceDefinitionGetRaceSegment(RaceDefinition *race, int segmentNumber)
{
  return &(race->Segments[segmentNumber]);
}
