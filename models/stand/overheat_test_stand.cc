#include "overheat_test_stand.h"

#include <cmath>
#include <sstream>

std::string OverheatTestStand::GetTestResultString() {
  std::stringstream buf;
  buf << "Test is " << (test_passed_ ? "" : "not ") << "passed";
  if (!test_passed_) {
    buf << std::endl << "Overheat time: " << time_ << " secs";
  }

  return buf.str();
}

void OverheatTestStand::Start(BaseEngine *engine, float air_temperature) {
  float previous_temperature;
  test_passed_ = false;
  time_ = 0;
  engine->Start(air_temperature);
  previous_temperature = engine->GetTemperature();

  while (engine->GetTemperature() < engine->GetOverheatT()) {
    engine->OnTickTime(std::chrono::milliseconds(1000));
    time_ += 1;
    if (std::fabs(engine->GetTemperature() - previous_temperature) <= 1e-6) {
      test_passed_ = true;
      break;
    } else {
      previous_temperature = engine->GetTemperature();
    }
  }
}

std::string OverheatTestStand::GetName() { return "Overheat test stand"; }
