#include "linear_function.h"

class Interval {
 public:
  explicit Interval(const std::vector<float>& point) : points_(point) {}

  int GetInterval(float value, double epsilon = 1e-2) const {
    const auto &points = points_.get();
    int index_of_interval{0};

    if (value < points.front()) {
      // before end interval
      return -1;
    } else if (value > points.back()) {
      // past end interval
      return static_cast<int>(points.size());
    }

    for (int i = 0; i < points.size() - 1; ++i) {
      if (value >= points[i]) {
        index_of_interval = static_cast<int>(i);
      }
    }

    return index_of_interval;
  }

 private:
  std::reference_wrapper<const std::vector<float>> points_;
};

LinearFunction::LinearFunction(std::vector<float> x, std::vector<float> y)
    : x_(std::move(x)), y_(std::move(y)) {
  FindLinearCoefficients();
}

float LinearFunction::GetY(float x) {
  int i = Interval(x_).GetInterval(x);

  auto [k, b] = coefficients_[i];
  return k * x + b;
}

void LinearFunction::FindLinearCoefficients() {
  for (int i = 0; i < x_.size() - 1; ++i) {
    float dy = y_[i + 1] - y_[i];
    float dx = x_[i + 1] - x_[i];

    float k = dy / dx;
    float b = y_[i] - k * x_[i];

    coefficients_.push_back({k, b});
  }
}
