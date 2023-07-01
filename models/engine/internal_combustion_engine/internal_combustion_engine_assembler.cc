#include "internal_combustion_engine_assembler.h"

#include <fstream>

#include "nlohmann/json.hpp"

std::unique_ptr<BaseEngine> InternalCombustionEngineAssembler::Assemble() {
  return std::move(engine_);
}

void InternalCombustionEngineAssembler::FromFile(const std::string& file_path) {
  InternalCombustionEngineParameters parameters;

  std::ifstream file(file_path);
  nlohmann::json json;
  file >> json;

  parameters.name = json["name"];
  parameters.I = json["I"];
  parameters.TorqueFromCrankshaftSpeed = LinearFunction(json["V"], json["M"]);
  parameters.OverheatT = json["OverheatT"];
  parameters.Hm = json["Hm"];
  parameters.Hv = json["Hv"];
  parameters.C = json["C"];

  engine_ = std::make_unique<InternalCombustionEngine>(parameters);
}
