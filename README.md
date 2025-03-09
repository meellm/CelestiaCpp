# CelestiaCpp

CelestiaCpp is a lightweight C++ library designed to calculate celestial positions of objects such as the Sun and Moon for any given location and time.
It provides a simple yet effective solution for astronomical calculations.

## Features

- Calculations of azimuth (compass direction) and altitude (angle from horizon) for celestial bodies
- Real-time tracking of Sun and Moon positions
- Atmospheric refraction correction
- Object-oriented extensible design
- Calculations for any latitude and longitude coordinates

## Installation

CelestiaCpp is designed as a header-only library. To include it in your project:

```bash
git clone https://github.com/meellm/CelestiaCpp.git
cd CelestiaCpp
```
> Feel free to use this repository in your projects as long as you give appropriate credit and follow the license terms!

## Usage

### Basic Concepts

CelestiaCpp uses a simple object-oriented approach for celestial calculations:

1. **CelestialBody**: An abstract base class that defines the interface for all celestial objects
2. **Sun and Moon**: Concrete implementations for specific celestial bodies
3. **CelestialMath**: A utility class that provides common astronomical calculations

### Working with Celestial Bodies

To calculate positions of celestial bodies:

1. Create an instance of the celestial body you want to track (Sun or Moon)
2. Provide the observer's coordinates (latitude and longitude in degrees)
3. Specify the time for the calculation (as a standard time_t value)
4. Call the appropriate methods to get azimuth and altitude values
5. Convert the returned values from radians to degrees if needed

### Key Methods

* `calculateAzimuth(latitude, longitude, time)`: Returns the compass direction to the celestial body (in radians)
* `calculateAltitude(latitude, longitude, time)`: Returns the angle above the horizon (in radians)
* `getName()`: Returns the name of the celestial body

### Example Workflow

1. Set up your observer location with latitude and longitude values
2. Get the current time or set a specific date/time for calculations
3. Create instances of the celestial bodies you want to track
4. Calculate their positions using the provided methods
5. Convert the results from radians to degrees (if desired)
6. Use the calculated values in your application (visualization, navigation, etc.)

### Integration Tips

* All angle values are returned in radians - multiply by (180/π) to convert to degrees
* Time values use the standard C/C++ time_t type (seconds since Unix epoch)
* The library handles the atmospheric refraction automatically for more accurate altitude values
* For objects below the horizon, altitude values will be negative

## Sample Execution

To run the sample test program:

```bash
g++ -std=c++14 src/celestia_test.cpp lib/CelestialMath.cpp lib/Sun.cpp lib/Moon.cpp -o celestia_test
./celestia_test
```

## Algorithm and Accuracy

CelestiaCpp uses simplified models based on commonly used formulas in astronomy. The implementation includes the following algorithms:

- Julian date calculation
- Local sidereal time determination
- Orbital position calculations for Sun and Moon
- Conversion to horizontal coordinate system (azimuth/altitude)
- Atmospheric refraction correction

The accuracy of these calculations is sufficient for general observation and educational purposes, although more sophisticated models may be required for professional applications:

- Sun position: Approximately ±0.5° deviation
- Moon position: Approximately ±1-2° deviation

**Important Note:** The astronomical constants used in this library are time-sensitive. As years pass, the accuracy will gradually decrease unless the constants are periodically updated to account for changes in celestial mechanics and the Earth's orientation!

## Contributing

Contributions are welcome. Here's how you can contribute:

1. Fork this repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the `LICENSE` file for details.

## Contact

meellm - [GitHub](https://github.com/meellm)

Project Link: [https://github.com/meellm/CelestiaCpp](https://github.com/meellm/CelestiaCpp)
