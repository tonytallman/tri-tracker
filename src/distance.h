#pragma once

typedef enum
{
  DistanceUnits_Zero = 0,
  DistanceUnits_Miles,
  DistanceUnits_Kilometers
} DistanceUnits;

typedef struct
{
  float Value;
  DistanceUnits Units;
} Distance;

const Distance DistanceZero = {.Value = 0, .Units = 0};