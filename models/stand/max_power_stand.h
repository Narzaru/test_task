#ifndef TEST_MODELS_STAND_MAX_POWER_STAND_H_
#define TEST_MODELS_STAND_MAX_POWER_STAND_H_

#include "base_stand.h"

class MaxPowerTestStand : public BaseStand {
 public:
  ~MaxPowerTestStand() override = default;
  std::string GetTestResultString() override;
  void Start(BaseEngine *engine, float air_temperature) override;
  std::string GetName() override;

 private:
  float max_power_;
};

#endif  // TEST_MODELS_STAND_MAX_POWER_STAND_H_
