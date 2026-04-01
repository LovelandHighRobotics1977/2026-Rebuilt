// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotBase/RobotContainer.hpp"
#include "headers/Headers.hpp"
#include "Subsystems/Drivetrain/AutoAim.hpp"
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Command.h>
#include <memory>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/path/PathPlannerPath.h>
#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <pathplanner/lib/auto/NamedCommands.h>
#include <pathplanner/lib/events/EventTrigger.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Commands.h>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include "Subsystems/Mechanism/MechFunctions.hpp"

RobotContainer::RobotContainer() {
	autoChooser = pathplanner::AutoBuilder::buildAutoChooser("Good auto");
	frc::SmartDashboard::PutData("Auto", &autoChooser);
	ConfigureDashboard();
	ConfigureButtonBindings();
	ConfigureDefaultCommands();
	ConfigureAutonomousChooser();
	pathplanner::NamedCommands::registerCommand("Shoot", std::move(m_mechanism.shoot()).ToPtr());
	pathplanner::NamedCommands::registerCommand("Intake", std::move(m_mechanism.intake()).ToPtr());
	pathplanner::NamedCommands::registerCommand("Rev", std::move(m_mechanism.rev()).ToPtr());
}

/*frc2::Command * RobotContainer::getSelectedAutonomous() {
  // Returns a frc2::Command* that is freed at program termination
  return autoChooser.GetSelected();
}*/
using namespace pathplanner;
frc2::CommandPtr RobotContainer::getAutonomousCommand() {
  return PathPlannerAuto("Good auto").ToPtr();
}
void RobotContainer::ConfigureDefaultCommands() {
	m_driver.SetDefaultCommand(frc2::RunCommand( [this] { m_driver.update(); } , {&m_driver} ));
	m_operator.SetDefaultCommand(frc2::RunCommand( [this] { m_operator.update(); } , {&m_operator} ));
	m_drive.SetDefaultCommand(frc2::RunCommand( 
		[this] { m_drive.Drive({ 
			m_driver.forward * Drivetrain::Movement::Maximum::Linear::Velocity, 
			m_driver.strafe * Drivetrain::Movement::Maximum::Linear::Velocity, 
			m_driver.rotate * Drivetrain::Movement::Maximum::Angular::Velocity, 
			m_driver.field_relative,
			Drivetrain::Movement::Rotate::Around::Center,
			m_driver.coast_mode_toggle });}, 
		{&m_drive}
	));
	/*
	m_mechanism.SetDefaultCommand(frc2::RunCommand( 
		[this] { m_mechanism.alignArm(false); },
		{&m_mechanism}
	));
	*/
}

void RobotContainer::ConfigureButtonBindings() {
	frc2::Trigger resetGyro([this] { return m_driver.gyro_reset; });
	resetGyro.OnTrue(frc2::InstantCommand( [] {Gyro::GetInstance()->ahrs.Reset();} ).ToPtr());

	frc2::Trigger Mech_1_Foward([this] { return m_operator.Mech_1_Foward; });
	Mech_1_Foward.WhileTrue(m_mechanism.Mech_1_Foward().ToPtr());

	frc2::Trigger Mech_1_Backward([this] { return m_operator.Mech_1_Backward; });
	Mech_1_Backward.WhileTrue(m_mechanism.Mech_1_Backward().ToPtr());

		frc2::Trigger Mech_2_Foward([this] { return m_operator.Mech_2_Foward; });
	Mech_2_Foward.WhileTrue(m_mechanism.Mech_2_Foward().ToPtr());

	frc2::Trigger Mech_2_Backward([this] { return m_operator.Mech_2_Backward; });
	Mech_2_Backward.WhileTrue(m_mechanism.Mech_2_Backward().ToPtr());
		
	frc2::Trigger Mech_3_Foward([this] { return m_operator.Mech_3_Foward; });
	Mech_3_Foward.WhileTrue(m_mechanism.Mech_3_Foward().ToPtr());

	frc2::Trigger Mech_3_Backward([this] { return m_operator.Mech_3_Backward; });
	Mech_3_Backward.WhileTrue(m_mechanism.Mech_3_Backward().ToPtr());
		
	frc2::Trigger Mech_4_Foward([this] { return m_operator.Mech_4_Foward; });
	Mech_4_Foward.WhileTrue(m_mechanism.Mech_4_Foward().ToPtr());

	frc2::Trigger Mech_4_Backward([this] { return m_operator.Mech_4_Backward; });
	Mech_4_Backward.WhileTrue(m_mechanism.Mech_4_Backward().ToPtr());
		
	frc2::Trigger Mech_5_Foward([this] { return m_operator.Mech_5_Foward; });
	Mech_5_Foward.WhileTrue(m_mechanism.Mech_5_Foward().ToPtr());

	frc2::Trigger Mech_5_Backward([this] { return m_operator.Mech_5_Backward; });
	Mech_5_Backward.WhileTrue(m_mechanism.Mech_5_Backward().ToPtr());
		
	frc2::Trigger Mech_6_Foward([this] { return m_operator.Mech_6_Foward; });
	Mech_6_Foward.WhileTrue(m_mechanism.Mech_6_Foward().ToPtr());

	frc2::Trigger Mech_6_Backward([this] { return m_operator.Mech_6_Backward; });
	Mech_6_Backward.WhileTrue(m_mechanism.Mech_6_Backward().ToPtr());
	



}

void RobotContainer::ConfigureAutonomousChooser() {

	//Starting position option
	
	//c_position.AddOption("Field Center", 1);
	//c_position.AddOption("Team Center", 2);
	//c_position.AddOption("Outside of Field", 3);
	

	//frc::SmartDashboard::PutData("Auto Position", &c_position);
	//create c_position dropdown menu

	//Position set option
	/*c_target.AddOption("10/21", 1); //The front
	c_target.AddOption("9/20", 2); 
	c_target.AddOption("8/19", 3);
	c_target.AddOption("7/18", 4); //The back
	c_target.AddOption("6/17", 5);
	c_target.AddOption("11/22", 6);
	*/
	//frc::SmartDashboard::PutData("Auto Target", &c_target);

	//Alliancee override option
	//c_allianceOverride.SetDefaultOption("Base Option",0);
	//c_allianceOverride.AddOption("Red",1);
	//c_allianceOverride.AddOption("Blue",2);

	//frc::SmartDashboard::PutData("Alliance Override", &c_allianceOverride);
}

void RobotContainer::setAutoValues() {
	//Set team color, which will provide positive/negative multiplier:
	/*if(c_allianceOverride.GetSelected() == 0){
		if(auto check = frc::DriverStation::GetAlliance()){
			AutoInfo::colorSet = frc::DriverStation::GetAlliance();
		}
		else{
			AutoInfo::colorSet = frc::DriverStation::Alliance::kRed; //default to red on issue
		}
	}else{
		switch(c_allianceOverride.GetSelected()){
			case 1: AutoInfo::colorSet = frc::DriverStation::Alliance::kRed;
				[[fallthrough]];
			case 2: AutoInfo::colorSet = frc::DriverStation::Alliance::kBlue;
			
		}
	}*/
	//Set the starting position, which affects arching angle
	switch(c_position.GetSelected()){
		case 1: AutoInfo::positionSet = 1;//true center value
		case 2: AutoInfo::positionSet = 2;//team center value
		case 3: AutoInfo::positionSet = 3;//edge value
		default: AutoInfo::positionSet = 3;
	}
	//Set the Apriltag Target and provide speed and rotation modifiers
	switch(c_target.GetSelected()){
		case 1: AutoInfo::targetSetR = 10; //set red target
				AutoInfo::targetSetB = 21; //set blue target
		case 2: AutoInfo::targetSetR = 9;
				AutoInfo::targetSetB = 20;
		case 3: AutoInfo::targetSetR = 8;
				AutoInfo::targetSetB = 19;
		case 4: AutoInfo::targetSetR = 7;
				AutoInfo::targetSetB = 18;
		case 5: AutoInfo::targetSetR = 6;
				AutoInfo::targetSetB = 17;
		case 6: AutoInfo::targetSetR = 11;
				AutoInfo::targetSetB = 22;
		default: AutoInfo::targetSetR = 10;
				AutoInfo::targetSetB = 21;
	}
}

void RobotContainer::ConfigureDashboard() {

	cs::UsbCamera DriveCamera = frc::CameraServer::StartAutomaticCapture(0);

}
/*frc2::CommandPtr RobotContainer::getAutonomousCommand() {

}*/