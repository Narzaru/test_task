#include <iostream>

#include "engine/internal_combustion_engine/internal_combustion_engine.h"
#include "engine/internal_combustion_engine/internal_combustion_engine_assembler.h"
#include "stand/max_power_stand.h"
#include "stand/overheat_test_stand.h"
#include "stand/runner.h"

int main() {
  InternalCombustionEngineAssembler assembler;

  try {
    assembler.FromFile("datasets/example_engine.json");
  } catch (...) {
    std::cerr << "cannot open file (datasets/example_engine.json) or there is "
                 "an error in the file";
    return -1;
  }

  float air_temperature{20.0f};
  std::cout << "Input air temperature:(*C)" << std::endl << "> ";
  std::cin >> air_temperature;
  if (!std::cin) {
    std::cerr << "parse input error";
    return -1;
  }

  std::vector<BaseStand *> stands;
  stands.emplace_back(new OverheatTestStand);
  stands.emplace_back(new MaxPowerTestStand);
  std::vector<EngineAssembler *> assemblers;
  assemblers.push_back(&assembler);

  Runner runner(stands, assemblers, air_temperature);

  for (auto stand : stands) {
    delete stand;
  }
  return 0;
}
