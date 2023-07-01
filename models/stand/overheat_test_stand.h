#ifndef TEST_MODELS_STAND_OVERHEAT_TEST_STAND_H_
#define TEST_MODELS_STAND_OVERHEAT_TEST_STAND_H_

#include "base_stand.h"

class OverheatTestStand : public BaseStand {
 public:
  ~OverheatTestStand() override = default;
  std::string GetTestResultString() override;
  void Start(BaseEngine *engine, float air_temperature) override;
  std::string GetName() override;

 private:
  float time_{0};
  bool test_passed_{false};
};

#endif  // TEST_MODELS_STAND_OVERHEAT_TEST_STAND_H_
