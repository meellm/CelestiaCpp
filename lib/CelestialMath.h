#ifndef CELESTIAL_MATH_H
#define CELESTIAL_MATH_H

#include <cmath>
#include <ctime>

class CelestialMath {
    public:
        static constexpr double PI = 3.14159265358979323846;
        static constexpr double RAD = PI / 180.0;
        static constexpr double E = RAD * 23.4397;

        static double calculateJulianDate(time_t time);
        static double siderealTime(double d, double lw);
        static double rightAscension(double l, double b);
        static double declination(double l, double b);
        static void calculateAzimuthAltitude(double H, double phi, double dec, double &azimuth, double &altitude);
        static double applyRefraction(double altitude);
};

#endif
