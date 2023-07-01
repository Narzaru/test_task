#include "internal_combustion_engine.h"

InternalCombustionEngine::InternalCombustionEngine(EngineParameters parameters)
    : parameters_{std::move(parameters)},
      temperature_{0},
      crankshaft_speed_{0},
      air_temperature_{0} {}

void InternalCombustionEngine::Start(float air_temperature) {
  air_temperature_ = air_temperature;
  temperature_ = air_temperature_;
  crankshaft_speed_ = 0;
}

void InternalCombustionEngine::OnTickTime(std::chrono::milliseconds time) {
  float d_temp = CalculateCoolingRate() + CalculateHeatingRate();
  float torque = CalculateTorque();
  float crankshaft_acceleration = torque / parameters_.I;

  float seconds = static_cast<float>(time.count()) / 1000.0f;
  temperature_ += d_temp * seconds;
  crankshaft_speed_ += crankshaft_acceleration * seconds;
}

float InternalCombustionEngine::GetTemperature() { return temperature_; }

float InternalCombustionEngine::GetPower() {
  float power = CalculateTorque() * crankshaft_speed_;
  return power / 1000.0f;
}

float InternalCombustionEngine::GetOverheatT() {
  return parameters_.OverheatT;
}

const std::string& InternalCombustionEngine::GetName() {
  return parameters_.name;
}

float InternalCombustionEngine::CalculateTorque() {
  return parameters_.TorqueFromCrankshaftSpeed.GetY(crankshaft_speed_);
}

float InternalCombustionEngine::CalculateCoolingRate() {
  return parameters_.C * (air_temperature_ - temperature_);
}

float InternalCombustionEngine::CalculateHeatingRate() {
  // torque contribution
  float dtM = CalculateTorque() * parameters_.Hm;
  // crankshaft contribution
  float dtV = crankshaft_speed_ * crankshaft_speed_ * parameters_.Hv;

  return dtM + dtV;
}

