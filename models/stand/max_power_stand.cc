#include "max_power_stand.h"

#include <cmath>
#include <sstream>

std::string MaxPowerTestStand::GetName() { return "Max power stand"; }

std::string MaxPowerTestStand::GetTestResultString() {
  std::stringstream buf;
  buf << "Max motor power = " << max_power_ << " kW";

  return buf.str();
}

void MaxPowerTestStand::Start(BaseEngine *engine, float air_temperature) {
  float last_power;
  engine->Start(air_temperature);
  max_power_ = engine->GetPower();
  last_power = max_power_;
  bool stop_test{false};

  while (!stop_test) {
    engine->OnTickTime(std::chrono::milliseconds(1000));

    if (auto power = engine->GetPower();
        std::fabs(power - last_power) <= 1e-6) {
      stop_test = true;
    }

    last_power = engine->GetPower();
    max_power_ = std::max(last_power, max_power_);
  }
}
