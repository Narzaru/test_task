#ifndef TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_INTERNAL_COMBUSTION_ENGINE_PARAMETERS_H_
#define TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_INTERNAL_COMBUSTION_ENGINE_PARAMETERS_H_

#include <string>

#include "linear_function.h"

struct InternalCombustionEngineParameters {
  std::string name;
  float I{std::numeric_limits<float>::quiet_NaN()};
  float OverheatT{std::numeric_limits<float>::quiet_NaN()};
  LinearFunction TorqueFromCrankshaftSpeed;
  float Hm{std::numeric_limits<float>::quiet_NaN()};
  float Hv{std::numeric_limits<float>::quiet_NaN()};
  float C{std::numeric_limits<float>::quiet_NaN()};
};

#endif  // TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_INTERNAL_COMBUSTION_ENGINE_PARAMETERS_H_
