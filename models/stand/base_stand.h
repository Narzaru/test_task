#ifndef TEST_MODELS_STAND_BASE_STAND_H_
#define TEST_MODELS_STAND_BASE_STAND_H_

#include <string>
#include "engine/base_engine.h"

class BaseStand {
 public:
  virtual ~BaseStand() = default;

  virtual std::string GetName() = 0;
  virtual std::string GetTestResultString() = 0;
  virtual void Start(BaseEngine *engine, float air_temperature) = 0;
};

#endif  // TEST_MODELS_STAND_BASE_STAND_H_
