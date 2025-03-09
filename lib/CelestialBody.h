#ifndef CELESTIAL_BODY_H
#define CELESTIAL_BODY_H

#include <string>

class CelestialBody {
    protected:
        std::string name;
    public:
        CelestialBody(std::string name) : name(name) {}
        virtual ~CelestialBody() {}

        virtual double calculateAzimuth(double latitude, double longitude, double time) = 0;
        virtual double calculateAltitude(double latitude, double longitude, double time) = 0;

        std::string getName() const { return name; }
};

#endif
