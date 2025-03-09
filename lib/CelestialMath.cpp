#include "CelestialMath.h"

double CelestialMath::calculateJulianDate(time_t time) {
    const double secondsPerDay = 86400.0;

    return (static_cast<double>(time) / secondsPerDay) - 10957.5;
}

double CelestialMath::siderealTime(double d, double lw) {
    return RAD * (280.16 + 360.9856235 * d) - lw;
}

double CelestialMath::rightAscension(double l, double b) {
    return atan2(sin(l) * cos(E) - tan(b) * sin(E), cos(l));
}

double CelestialMath::declination(double l, double b) {
    return asin(sin(b) * cos(E) + cos(b) * sin(E) * sin(l));
}

void CelestialMath::calculateAzimuthAltitude(double H, double phi, double dec, double &azimuth, double &altitude) {
    altitude = asin(sin(phi) * sin(dec) + cos(phi) * cos(dec) * cos(H));
    azimuth = atan2(sin(H), cos(H) * sin(phi) - tan(dec) * cos(phi));
    azimuth += PI;
}

double CelestialMath::applyRefraction(double altitude) {
    double h = altitude;
    if(h < 0){
        h = 0;
    }
    double refraction = 0.0002967 / tan(h + 0.00312536 / (h + 0.08901179));
    return altitude + refraction;
}
