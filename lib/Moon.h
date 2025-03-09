#ifndef MOON_H
#define MOON_H

#include "CelestialBody.h"
#include "CelestialMath.h"

class Moon : public CelestialBody {
    private:
        struct RaDec { double ra; double dec;};
        RaDec calculateMoonCoords(double d);
    public:
        Moon() : CelestialBody("Moon") {}

        virtual double calculateAzimuth(double latitude, double longitude, double time) override;
        virtual double calculateAltitude(double latitude, double longitude, double time) override;
};

#endif
