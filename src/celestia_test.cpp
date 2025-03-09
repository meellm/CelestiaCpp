#include <iostream>
#include <ctime>
#include <vector>
#include <memory>
#include <iomanip>

#include "../lib/CelestialBody.h"
#include "../lib/Sun.h"
#include "../lib/Moon.h"

double toDegrees(double radians){
    return radians * 180.0 / CelestialMath::PI;
}

int main(){
    double longitude = 28.9784;
    double latitude = 41.0082;

    time_t now = time(nullptr);

    std::vector<std::unique_ptr<CelestialBody>> bodies;

    bodies.push_back(std::make_unique<Sun>());
    bodies.push_back(std::make_unique<Moon>());

    std::cout << "Celestial Bodies Position Test" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Location: Latitude " << latitude << "°, Longitude " << longitude << "°" << std::endl;

    char timeBuffer[80];
    struct tm* timeInfo = localtime(&now);
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    std::cout << "Current Time: " << timeBuffer << std::endl;
    std::cout << "============================" << std::endl;

    for(const auto &body : bodies){
        double azimuth = body->calculateAzimuth(latitude, longitude, now);
        double altitude = body->calculateAltitude(latitude, longitude, now);

        double azimuthDeg = toDegrees(azimuth);
        double altitudeDeg = toDegrees(altitude);

        std::cout << body->getName() << ":" << std::endl;
        std::cout << "Azimuth: " << std::fixed << std::setprecision(2) << azimuthDeg << "°" << std::endl;
        std::cout << "Altitude: " << std::fixed << std::setprecision(2) << altitudeDeg << "°" << std::endl;

        if(altitudeDeg > 0){
            std::cout << "Above Horizon!" << std::endl;
        } else{
            std::cout << "Below Horizon!" << std::endl;
        }

        std::cout << "----------------------------" << std::endl;
    }

    return 0;
}
