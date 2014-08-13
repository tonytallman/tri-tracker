#include <pebble.h>
#include "racedefinition.h"
#include "distance.h"

RaceDefinition RaceDefinitionCreateTriathlon(Distance swimDistance, Distance bikeDistance, Distance runDistance)
{
  RaceDefinition race;
  race.NumberOfSegments = 5;

  const Distance distanceZero = {.Value = 0, .Units = 0};

  race.Segments[0].Type = RaceSegmentType_Swim;
  race.Segments[0].Distance = swimDistance;

  race.Segments[1].Type = RaceSegmentType_Transition;
  race.Segments[1].Distance = distanceZero;

  race.Segments[2].Type = RaceSegmentType_Bike;
  race.Segments[2].Distance = bikeDistance;

  race.Segments[3].Type = RaceSegmentType_Transition;
  race.Segments[3].Distance = distanceZero;

  race.Segments[4].Type = RaceSegmentType_Run;
  race.Segments[4].Distance = runDistance;

  return race;
}

int RaceDefinitionGetNumberOfSegments(RaceDefinition race)
{
  return race.NumberOfSegments;
}

RaceSegment RaceDefinitionGetRaceSegment(RaceDefinition race, int segmentNumber)
{
  return race.Segments[segmentNumber];
}

RaceDefinition GetSprintTriathlonDefinition()
{
  const Distance SprintTriathlonSwim = { .Value = .75, .Units = DistanceUnits_Kilometers };
  const Distance SprintTriathlonBike = { .Value = 20, .Units = DistanceUnits_Kilometers };
  const Distance SprintTriathlonRun = { .Value = 5, .Units = DistanceUnits_Kilometers };
  return RaceDefinitionCreateTriathlon(SprintTriathlonSwim, SprintTriathlonBike, SprintTriathlonRun);
}

RaceDefinition GetOlympicTriathlonDefinition()
{
  const Distance SprintTriathlonSwim = { .Value = 1.5, .Units = DistanceUnits_Kilometers };
  const Distance SprintTriathlonBike = { .Value = 40, .Units = DistanceUnits_Kilometers };
  const Distance SprintTriathlonRun = { .Value = 10, .Units = DistanceUnits_Kilometers };
  return RaceDefinitionCreateTriathlon(SprintTriathlonSwim, SprintTriathlonBike, SprintTriathlonRun);
}

RaceDefinition GetHalfIronmanTriathlonDefinition()
{
  const Distance SprintTriathlonSwim = { .Value = 1.2, .Units = DistanceUnits_Miles };
  const Distance SprintTriathlonBike = { .Value = 56, .Units = DistanceUnits_Miles };
  const Distance SprintTriathlonRun = { .Value = 13.1, .Units = DistanceUnits_Miles };
  return RaceDefinitionCreateTriathlon(SprintTriathlonSwim, SprintTriathlonBike, SprintTriathlonRun);
}

RaceDefinition GetIronmanTriathlonDefinition()
{
  const Distance SprintTriathlonSwim = { .Value = 2.4, .Units = DistanceUnits_Miles };
  const Distance SprintTriathlonBike = { .Value = 112, .Units = DistanceUnits_Miles };
  const Distance SprintTriathlonRun = { .Value = 26.2, .Units = DistanceUnits_Miles };
  return RaceDefinitionCreateTriathlon(SprintTriathlonSwim, SprintTriathlonBike, SprintTriathlonRun);
}
