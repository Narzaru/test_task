cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/json-3.11.2)

add_executable(test
        main.cpp
        models/engine/internal_combustion_engine/internal_combustion_engine.cc
        models/engine/internal_combustion_engine/internal_combustion_engine.h
        models/engine/internal_combustion_engine/internal_combustion_engine_assembler.cc
        models/engine/internal_combustion_engine/internal_combustion_engine_assembler.h
        models/engine/internal_combustion_engine/linear_function.h
        models/engine/internal_combustion_engine/linear_function.cc
        models/engine/internal_combustion_engine/internal_combustion_engine_parameters.h
        models/stand/base_stand.h
        models/stand/overheat_test_stand.cc
        models/stand/overheat_test_stand.h
        models/stand/max_power_stand.cc
        models/stand/max_power_stand.h
        models/stand/runner.h)


target_compile_options(test PUBLIC -O2)
target_link_libraries(test PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(test PRIVATE models third_party/json-3.11.2/include)
