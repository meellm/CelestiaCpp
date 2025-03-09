#include "Moon.h"

double Moon::calculateAzimuth(double latitude, double longitude, double time) {
    double lw = CelestialMath::RAD * -longitude;
    double phi = CelestialMath::RAD * latitude;
    double d = CelestialMath::calculateJulianDate(time);

    RaDec c = calculateMoonCoords(d);
    double H = CelestialMath::siderealTime(d, lw) - c.ra;

    double azimuth, altitude;
    CelestialMath::calculateAzimuthAltitude(H, phi, c.dec, azimuth, altitude);

    return azimuth;
}

double Moon::calculateAltitude(double latitude, double longitude, double time) {
    double lw = CelestialMath::RAD * -longitude;
    double phi = CelestialMath::RAD * latitude;
    double d = CelestialMath::calculateJulianDate(time);

    RaDec c = calculateMoonCoords(d);
    double H = CelestialMath::siderealTime(d, lw) - c.ra;

    double azimuth, altitude;
    CelestialMath::calculateAzimuthAltitude(H, phi, c.dec, azimuth, altitude);

    return CelestialMath::applyRefraction(altitude);
}

Moon::RaDec Moon::calculateMoonCoords(double d) {
    double L = CelestialMath::RAD * (218.316 + 13.176396 * d);
    double M = CelestialMath::RAD * (134.963 + 13.064993 * d);
    double F = CelestialMath::RAD * (93.272 + 13.229350 * d);

    double l = L + CelestialMath::RAD * 6.289 * sin(M);
    double b = CelestialMath::RAD * 5.128 * sin(F);

    RaDec result;
    result.ra = CelestialMath::rightAscension(l, b);
    result.dec = CelestialMath::declination(l, b);

    return result;
}
