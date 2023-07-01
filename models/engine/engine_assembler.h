#ifndef TEST_MODELS_ENGINE_ENGINE_ASSEMBLER_H_
#define TEST_MODELS_ENGINE_ENGINE_ASSEMBLER_H_

#include "base_engine.h"

class EngineAssembler {
 public:
  virtual ~EngineAssembler() = default;
  virtual std::unique_ptr<BaseEngine> Assemble() = 0;
};

#endif  // TEST_MODELS_ENGINE_ENGINE_ASSEMBLER_H_
