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
class Mech_2 : public frc2::SubsystemBase {
	public:
		Mech_2();

		void setMech_2(double speed);
		
	private:

		ctre::phoenix6::hardware::TalonFX mech_2;
	    ctre::phoenix6::configs::TalonFXConfiguration mech2MotorConfig{};

		
};
class Mech_3 : public frc2::SubsystemBase {
	public:
		Mech_3();

		void setMech_3(double speed);
		
	private:

		ctre::phoenix6::hardware::TalonFX mech_3;
	    ctre::phoenix6::configs::TalonFXConfiguration mech3MotorConfig{};

		
};
class Mech_4 : public frc2::SubsystemBase {
	public:
		Mech_4();

		void setMech_4(double speed);
		
	private:

		ctre::phoenix6::hardware::TalonFX mech_4;
	    ctre::phoenix6::configs::TalonFXConfiguration mech4MotorConfig{};
		

		
};
class Mech_5 : public frc2::SubsystemBase {
	public:
		Mech_5();

		void setMech_5(double speed);
		
	private:

		ctre::phoenix6::hardware::TalonFX mech_5;
	    ctre::phoenix6::configs::TalonFXConfiguration mech5MotorConfig{};
		

		
};
class Mech_6 : public frc2::SubsystemBase {
	public:
		Mech_6();

		void setMech_6(double speed);
		
	private:

		ctre::phoenix6::hardware::TalonFX mech_6;
	    ctre::phoenix6::configs::TalonFXConfiguration mech6MotorConfig{};
		

		
};

class Mech_7 : public frc2::SubsystemBase {
	public:
		Mech_7();

		void setMech_7(double speed);
		
	private:

		ctre::phoenix6::hardware::TalonFX mech_7;
	    ctre::phoenix6::configs::TalonFXConfiguration mech7MotorConfig{};
		

		
};

#endif