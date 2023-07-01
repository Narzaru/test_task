#ifndef TEST_MODELS_ENGINE_BASE_ENGINE_H_
#define TEST_MODELS_ENGINE_BASE_ENGINE_H_

#include <chrono>
#include <string>

class BaseEngine {
 public:
  virtual ~BaseEngine() = default;
  virtual void Start(float air_temperature) = 0;
  virtual void OnTickTime(std::chrono::milliseconds tick_time) = 0;

  virtual float GetTemperature() = 0;
  virtual float GetPower() = 0;

  virtual float GetOverheatT() = 0;

  virtual const std::string &GetName() = 0;
};

#endif  // TEST_MODELS_ENGINE_BASE_ENGINE_H_
