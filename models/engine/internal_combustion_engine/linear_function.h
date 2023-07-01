#ifndef TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_LINEAR_FUNCTION_H_
#define TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_LINEAR_FUNCTION_H_

#include <cmath>
#include <vector>

class LinearFunction {
 public:
  LinearFunction() = default;
  LinearFunction(std::vector<float> x, std::vector<float> y);

  float GetY(float x);

 private:
  struct Coefficients {
    float k{0.0};
    float b{0.0};
  };

  void FindLinearCoefficients();

  std::vector<float> x_;
  std::vector<float> y_;
  std::vector<Coefficients> coefficients_;
};

#endif  // TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_LINEAR_FUNCTION_H_
