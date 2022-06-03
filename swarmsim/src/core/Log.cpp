//
// Created by kasper on 10/16/19.
//

#include "core/Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;

void Log::Init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_CoreLogger = spdlog::stdout_color_mt("HERD", spdlog::color_mode::automatic);
    s_CoreLogger->set_level(spdlog::level::trace);
}
