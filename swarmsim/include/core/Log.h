//
// Created by kasper on 10/16/19.
//

#ifndef SWARMSIM_LOG_H
#define SWARMSIM_LOG_H
#pragma once

#include "spdlog/spdlog.h"
namespace SwarmSim {
class Log {
   public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

   private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
};

}  // namespace SwarmSim

// Core log macros
#define SWARMSIM_CORE_TRACE(...) SwarmSim::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SWARMSIM_CORE_INFO(...) SwarmSim::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SWARMSIM_CORE_WARN(...) SwarmSim::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SWARMSIM_CORE_ERROR(...) SwarmSim::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SWARMSIM_CORE_CRITICAL(...) SwarmSim::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define SWARMSIM_CORE_DEBUG(...) SwarmSim::Log::GetCoreLogger()->debug(__VA_ARGS__)
#endif  // SWARMSIM_LOG_H