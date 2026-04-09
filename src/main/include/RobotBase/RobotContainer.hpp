#ifndef _ROBOT_CONTAINER_H
#define _ROBOT_CONTAINER_H

#include "Headers/Headers.hpp"
#include "Control/Autonomous.hpp"
#include "subsystems/Mechanism/MechFunctions.hpp"
#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <frc/smartdashboard/SmartDashboard.h>
class RobotContainer {
	public:
			DriveSubsystem m_drive;
		RobotContainer();
		frc2::CommandPtr getAutonomousCommand();
		frc2::Command * getSelectedAutonomous();
		void setAutoValues();
		void ConfigureAutonomousChooser();
		//frc2::Command* GetAutonomousCommand();
		
	private:

	
	// Configuration functions
		void ConfigureButtonBindings();
		void ConfigureDashboard();
		void ConfigureDefaultCommands();

	// Controllers
		Driver m_driver{TeleoperatedMode::Controller::Ports::Driver};
		Operator m_operator{TeleoperatedMode::Controller::Ports::Operator};

	// Subsystems
		//DriveSubsystem m_drive;
        MechFunctions m_mechanism;

	// Network Tables

		nt::NetworkTableInstance m_networkTable = nt::NetworkTableInstance::GetDefault();

	// Cameras
		
	//Auto routine
		//frc2::CommandPtr a_main = AutoFctns::autonomousRoutine(&m_drive);
		frc::SendableChooser<int> c_position;
		frc::SendableChooser<int> c_target;
		//frc::SendableChooser<int> c_allianceOverride;
	private:

    frc::SendableChooser<frc2::Command *> autoChooser;	
	Autonomous m_auto =  Autonomous(&m_drive, &m_mechanism);
	frc2::CommandPtr a_newAuto = std::move(m_auto.newAuto());  

};
	

#endif  // _ROBOT_CONTAINER_H