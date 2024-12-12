#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>

#include "Application.h"
#include "ElectricCar.h"
#include "Truck.h"
#include "Motorcycle.h"


int Application::main()
{
    setUpLoggerWithRotatingFiles();
    spdlog::info("Application start.");

    std::vector<Vehicle *> vehicles;

    // Vehicle* vehiclePtr = new Car("bmw", "1234AB7", 200, 15, 2017, 5);
    // vehicles.push_back(vehiclePtr);
    //
    // vehiclePtr = new ElectricCar("tesla", "4444BB3", 120, 17, 2020, 5, 300.);
    // vehicles.push_back(vehiclePtr);
    //
    // vehiclePtr = new Motorcycle("yamaha", "1313AA3", 150, 12, 2015, "Standard");
    // vehicles.push_back(vehiclePtr);

    for (Vehicle const *vehicle : vehicles) {
        std::cout << vehicle->toString() << '\n';
    }

    for (Vehicle const *vehicle : vehicles) {
        delete vehicle;
    }

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