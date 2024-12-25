#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>

#include "Calculator.h"
#include "Application.h"

int Application::main()
{
    setUpLoggerWithRotatingFiles();
    spdlog::info("Application start.");

    Calculator calculator;
    std::cout << calculator.evaluate("1*2");

    return 0;
}


void Application::setUpLoggerWithRotatingFiles()
{
    constexpr int logFileMaxSize = 1048576 * 5;
    constexpr int logFiles = 3;
    const auto logger =
            spdlog::rotating_logger_mt("main_logger", "logs/log.txt", logFileMaxSize, logFiles);
    spdlog::set_default_logger(logger);

    spdlog::set_level(spdlog::level::trace);
    spdlog::debug("Initialized logger.");
}