#ifndef _MECHANISM_H
#define _MECHANISM_H

#include "headers/Headers.hpp"

class Mech_1 : public frc2::SubsystemBase {
	public:
		Mech_1();

		void setMech_1(double speed);

	private:

		ctre::phoenix6::hardware::TalonFX mech_1_1;
	    ctre::phoenix6::configs::TalonFXConfiguration mech1_1MotorConfig{};
		ctre::phoenix6::hardware::TalonFX mech_1_2;
	    ctre::phoenix6::configs::TalonFXConfiguration mech1_2MotorConfig{};
		

		
};

#endif