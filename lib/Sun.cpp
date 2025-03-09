#include "Sun.h"

double Sun::calculateAzimuth(double latitude, double longitude, double time) {
    double lw = CelestialMath::RAD * -longitude;
    double phi = CelestialMath::RAD * latitude;
    double d = CelestialMath::calculateJulianDate(time);

    RaDec c = calculateSunCoords(d);
    double H = CelestialMath::siderealTime(d, lw) - c.ra;

    double azimuth, altitude;
    CelestialMath::calculateAzimuthAltitude(H, phi, c.dec, azimuth, altitude);

    return azimuth;
}

double Sun::calculateAltitude(double latitude, double longitude, double time) {
    double lw = CelestialMath::RAD * -longitude;
    double phi = CelestialMath::RAD * latitude;
    double d = CelestialMath::calculateJulianDate(time);

    RaDec c = calculateSunCoords(d);
    double H = CelestialMath::siderealTime(d, lw) - c.ra;

    double azimuth, altitude;
    CelestialMath::calculateAzimuthAltitude(H, phi, c.dec, azimuth, altitude);

    return CelestialMath::applyRefraction(altitude);
}

Sun::RaDec Sun::calculateSunCoords(double d) {
    double M = solarMeanAnomaly(d);
    double L = eclipticLongitude(M);

    RaDec result;
    result.ra = CelestialMath::rightAscension(L, 0);
    result.dec = CelestialMath::declination(L, 0);

    return result;
}

double Sun::solarMeanAnomaly(double d) {
    return CelestialMath::RAD * (357.5291 + 0.98560028 * d);
}

double Sun::eclipticLongitude(double M) {
    double C = CelestialMath::RAD * (1.9148 * sin(M) + 0.02 * sin(2 * M) + 0.0003 * sin(3 * M));
    double P = CelestialMath::RAD * 102.9372;

    return M + C + P + CelestialMath::PI;
}
