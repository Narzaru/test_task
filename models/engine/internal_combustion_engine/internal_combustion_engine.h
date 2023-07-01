#ifndef TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_H_
#define TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_H_

#include "internal_combustion_engine_parameters.h"
#include "engine/base_engine.h"

class InternalCombustionEngine : public BaseEngine {
 public:
  using EngineParameters = InternalCombustionEngineParameters;

  ~InternalCombustionEngine() override = default;
  explicit InternalCombustionEngine(EngineParameters parameters);

  void Start(float air_temperature) override;
  void OnTickTime(std::chrono::milliseconds time) override;
  float GetTemperature() override;
  float GetPower() override;
  float GetOverheatT() override;
  const std::string &GetName() override;

 protected:
  float CalculateTorque();
  float CalculateCoolingRate();
  float CalculateHeatingRate();

  EngineParameters parameters_;
  float temperature_;
  float crankshaft_speed_;
  float air_temperature_;
};

#endif  // TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_H_
