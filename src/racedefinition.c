#include <pebble.h>
#include "racedefinition.h"

struct RaceDefinitionStruct
{
  int NumberOfSegments;
  RaceSegment Segments[5];
};

RaceDefinition* RaceDefinitionCreateTriathlon(float swimDistanceInKilometers, float bikeDistanceInKilometers, float runDistanceInKilometers)
{
  RaceDefinition *race = malloc(sizeof(RaceDefinition));
  race->NumberOfSegments = 5;

  race->Segments[0].Type = RaceSegmentType_Swim;
  race->Segments[0].DistanceInKilometers = swimDistanceInKilometers;

  race->Segments[1].Type = RaceSegmentType_Transition;
  race->Segments[1].DistanceInKilometers = 0;

  race->Segments[2].Type = RaceSegmentType_Bike;
  race->Segments[2].DistanceInKilometers = bikeDistanceInKilometers;

  race->Segments[3].Type = RaceSegmentType_Transition;
  race->Segments[3].DistanceInKilometers = 0;

  race->Segments[4].Type = RaceSegmentType_Run;
  race->Segments[4].DistanceInKilometers = runDistanceInKilometers;

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
