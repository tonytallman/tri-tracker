#ifndef RACEDEFINITION
#define RACEDEFINITION

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
  float DistanceInKilometers;
} RaceSegment;

struct RaceDefinitionStruct;
typedef struct RaceDefinitionStruct RaceDefinition;

RaceDefinition* RaceDefinitionCreateTriathlon(float swimDistanceInKilometers, float bikeDistanceInKilometers, float runDistanceInKilometers);
void RaceDefinitionAddSegment(RaceDefinition *race, RaceSegmentType type, float segmentDistanceInKilometers);
int RaceDefinitionGetSegmentCount(RaceDefinition *race);
RaceSegment* RaceDefinitionGetRaceSegment(RaceDefinition *race, int segmentNumber);

#endif