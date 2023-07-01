#ifndef TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_ASSEMBLER_H_
#define TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_ASSEMBLER_H_

#include <map>
#include <memory>

#include "engine/internal_combustion_engine/internal_combustion_engine.h"
#include "engine/engine_assembler.h"

class InternalCombustionEngineAssembler : public EngineAssembler {
 public:
  ~InternalCombustionEngineAssembler() override = default;

  void FromFile(const std::string &file_path);

  std::unique_ptr<BaseEngine> Assemble() override;

 private:
  std::unique_ptr<BaseEngine> engine_;
};

#endif  // TEST_MODELS_ENGINE_INTERNAL_COMBUSTION_ENGINE_ASSEMBLER_H_
