#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "../RobotMap.h"
#include "Encoder.h"

// Shooting Range in Inches
#define MIN_RANGE 55
#define MAX_RANGE 65

// Starting power for calibrated distance to target
#define SHOOT_POWER 0.4
#define OPTIMUM_SHOOTER_RPM (double)1500 // FIXME: Calibrate for actual 'bot

// Calibrated based on measured distance
#define IN_FACTOR 1 / .00625
#define FT_FACTOR IN_FACTOR / 12

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *shootMotor;
	CANTalon *gateMotor;
	Counter *shooterCounter;
	Relay *doorSolenoid;
	Relay *rangeLight;
	AnalogInput *rangeBoiler;

public:
	Shooter();
	void InitDefaultCommand();
	void Shoot(float);
	void Stop();
	double GetRPM(); // Show shooter RPM
	void FeederStart();
	void FeederStop();
	void FeederReverse();
	void Light(unsigned int); // Target within range indicator
	float GetAverageVoltage(void); // rangefinder
	float GetRangeInches(void); // Distance to boiler
	void DoorOpen();
	void DoorClose();
};

#endif  // Shooter_H
