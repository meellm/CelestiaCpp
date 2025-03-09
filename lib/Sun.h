#ifndef SUN_H
#define SUN_H

#include "CelestialBody.h"
#include "CelestialMath.h"

class Sun : public CelestialBody {
    private:
        struct RaDec { double ra; double dec;};
        RaDec calculateSunCoords(double d);
        double solarMeanAnomaly(double d);
        double eclipticLongitude(double M);
    public:
        Sun() : CelestialBody("Sun") {}

        virtual double calculateAzimuth(double latitude, double longitude, double time) override;
        virtual double calculateAltitude(double latitude, double longitude, double time) override;
};

#endif
