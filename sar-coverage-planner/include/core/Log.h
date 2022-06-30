//
// Created by kasper on 10/16/19.
//

#ifndef SWARMSIM_LOG_H
#define SWARMSIM_LOG_H
#pragma once

#include "spdlog/spdlog.h"
namespace MRCP {
class Log {
   public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

   private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
};

}  // namespace MRCP

// Core log macros
#define MRCP_CORE_TRACE(...) MRCP::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MRCP_CORE_INFO(...) MRCP::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MRCP_CORE_WARN(...) MRCP::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MRCP_CORE_ERROR(...) MRCP::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MRCP_CORE_CRITICAL(...) MRCP::Log::GetCoreLogger()->critical(__VA_ARGS__)
#endif  // SWARMSIM_LOG_H