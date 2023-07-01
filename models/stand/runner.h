#ifndef TEST_MODELS_STAND_RUNNER_H_
#define TEST_MODELS_STAND_RUNNER_H_

#include <iostream>
#include <vector>

#include "base_stand.h"
#include "engine/engine_assembler.h"

class Runner {
 public:
  Runner(const std::vector<BaseStand *> &stands,
         const std::vector<EngineAssembler *> &engine_assembler, float air_temperature) {
    for (auto assembler : engine_assembler) {
      auto engine = assembler->Assemble();
      std::cout << "test for: " << engine->GetName() << std::endl;
      for (auto stand : stands) {
        std::cout << "[" << stand->GetName() << "]" << std::endl;
        stand->Start(engine.get(), air_temperature);
        std::cout << stand->GetTestResultString() << std::endl;
      }
    }
  }
};

#endif  // TEST_MODELS_STAND_RUNNER_H_
