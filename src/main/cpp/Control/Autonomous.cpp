#include "Control/Autonomous.hpp"
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/config/RobotConfig.h>
#include <pathplanner/lib/controllers/PPHolonomicDriveController.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/DriverStation.h>
#include "Subsystems/Drivetrain/DriveSubsystem.hpp"
#include  "Subsystems/Drivetrain/Commands.hpp"
#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include "RobotBase/RobotContainer.hpp"
#include "headers/Headers.hpp"
#include "Subsystems/Drivetrain/AutoAim.hpp"
#include <pathplanner/lib/auto/AutoBuilder.h>
#include "Subsystems/Mechanism/MechFunctions.hpp"
//#include "headers/limelighthelpers.h"

Autonomous::Autonomous(DriveSubsystem *drive, MechFunctions *mechFunctions){
	m_drive = drive;
	m_mechFunctions = mechFunctions;
}

frc2::CommandPtr Autonomous::newAuto(){
	auto drive = m_drive;
	auto mech = m_mechFunctions;
	return frc2::SequentialCommandGroup(
	/*	frc2::ParallelRaceGroup(
			frc2::RunCommand([drive]{drive->HubAutoAlign();}),frc2::WaitCommand(3_s)
	)*/
		drive->resetPose({0_m, 0_m, 0_deg}),
		frc2::ParallelCommandGroup(frc2::InstantCommand([mech]{mech->hardrev();}),
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({6.5_fps, 0_fps, 3_deg_per_s, 0});}, {drive}),
				frc2::WaitCommand(.75_s)
			))
		),
		frc2::InstantCommand([drive] { drive->Drive({});}),
		//frc2::RunCommand([drive]{drive->HubAutoAlign();}),
		frc2::SequentialCommandGroup(frc2::ParallelRaceGroup(
			mech->shoot(.48), 

			frc2::WaitCommand(3_s)
		)),
		mech->shootCancel(),
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
		//	frc2::RunCommand([mech] { mech->Mech_6_Foward();}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({3_fps, -2_fps, -30_deg_per_s, 0});}, {drive}),
				frc2::WaitCommand(1.07_s)
			)
		),
	
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({4_fps, 0_fps, 30_deg_per_s, 0});}, {drive}),
				mech->intake(),
				frc2::WaitCommand(1.55_s)
			)
		),
		frc2::WaitCommand(0.5_s),
		frc2::WaitCommand(1_s),
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({-4_fps, 0_fps, 0_deg_per_s, 0});}, {drive}),
				frc2::WaitCommand(.75_s)
			)
		),
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({0_fps, -5_fps, 0_deg_per_s, 0});}, {drive}),
				frc2::WaitCommand(0.2_s)
			)
		),
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({4_fps, 0_fps, -30_deg_per_s, 0});}, {drive}),
				frc2::WaitCommand(1.5_s)
			)
		),
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({-4_fps, 0_fps, 35_deg_per_s, 0});}, {drive}),
				frc2::WaitCommand(1_s)
			),
			frc2::InstantCommand([drive] { drive->Drive({});})
		),
		frc2::ParallelRaceGroup(
			frc2::RunCommand([drive]{drive->HubAutoAlign();}),
			frc2::WaitCommand(2.5_s)
		),
		frc2::SequentialCommandGroup(
			frc2::InstantCommand([drive] { drive->Drive({});}),
			frc2::ParallelRaceGroup(
				frc2::RunCommand([drive] { drive->Drive({-4_fps, 0_fps, 0_deg_per_s, 0});}, {drive}),
				frc2::WaitCommand(.75_s)
			)
		),
		frc2::InstantCommand([drive] { drive->Drive({});}),
		frc2::SequentialCommandGroup(frc2::ParallelRaceGroup(
			mech->rev(),
			frc2::WaitCommand(1_s)
		)),
		//frc2::WaitCommand(1_s),
		frc2::SequentialCommandGroup(frc2::ParallelRaceGroup(
			mech->shoot(.52),
			frc2::WaitCommand(3.5_s)
		)),

		mech->intakeCancel(),
		mech->shootCancel()
	).ToPtr();
}

/*frc2::CommandPtr RobotContainer::getAutonomousCommand(){
    // This method loads the auto when it is called, however, it is recommended
    // to first load your paths/autos when code starts, then return the
    // pre-loaded auto/path
	
    return PathPlannerAuto("Test").ToPtr();
}*/
//In the future, pose estimation will be used to determine the location and accuracy for auto
//must go forward 224 in. and 136 in left

/* example auto routine

sets the auto routine name and devices to be used.  In this case, it is named smapleAuto, and will
use the drivetrain and note mechanism:
frc2::CommandPtr `Routine::sampleAuto(DriveSubsystem *drive, NoteMechanism *noteMechanism) {

	This tells the auto routine to complete all of the actions in order
    return frc2::SequentialCommandGroup(

		This will reset the gyro
        drive->ZeroOdometry({0_m, 0_m, 0_deg}),

            frc2::SequentialCommandGroup(

				This will have the bot immediately stop:
				frc2::InstantCommand([drive] { drive->Drive({});}),

				This will have the bot shoot a note, which takes around 0.5 seconds:
				noteMechanism->ShootNote()

				//This will set a function to be called
				frc2::ParallelRaceGroup(

					In this case, the function is to drive, which is determined by (forwards/backwards, left/right, rotation, and orientation base):
                    frc2::RunCommand([drive] { drive->Drive({0_fps, 0_fps, 0_deg_per_s, 0});}, {drive}),

					This line will have the robot pick up a note while driving:
                    frc2::RunCommand([noteMechanism] { noteMechanism->PickupNote();}, {noteMechanism}),

					//This line will have the robot wait for the amount of time specified.  Normally, 1 second is enough:
                    frc2::WaitCommand(1_s)
                ),

				frc2::ParallelRaceGroup(

					//this command will reset the gyro
					//Be sure to stop the robot before hand, using the instant command
					drive->ZeroOdometry({0_m, 0_m, 0_deg}),

                    frc2::WaitCommand(1_s)

                ) Last line doesn't need a comma
			)
	).ToPtr();
}
*/
//void AutoFctns::setAutoRoutineValues(int position, int targetR, int targetB, std::optional<frc::DriverStation::Alliance> color){

//}


/*frc2::CommandPtr AutoFctns::autonomousRoutine(DriveSubsystem *drive) {
	//AutoFctns::setAutoRoutineValues(AutoInfo::positionSet, AutoInfo::targetSetA, AutoInfo::colorSet);
	return frc2::SequentialCommandGroup(
		
		//This will reset the gyro
        drive->ResetOdometry({0_m, 0_m, 0_deg}),
		frc2::SequentialCommandGroup(
				frc2::InstantCommand([drive] { drive->Drive({});}),
				
				frc2::ParallelRaceGroup(
                    frc2::RunCommand([drive] { drive->Drive({0_fps, 0_fps, 0_deg_per_s, 0});}, {drive}), 

                    frc2::WaitCommand(2_s)
                ),
				frc2::ParallelRaceGroup(

                    frc2::RunCommand([drive] { drive->Drive({0_fps, 0_fps, 0_deg_per_s, 0});}, {drive}), 
                    frc2::WaitCommand(1_s)
                ),
				frc2::InstantCommand([drive] { drive->Drive({});})

		)
	).ToPtr();
}*/

/*
Determine how to find distance from limelight, in addition to angle if possible
Use a combination of the three provided values to obtain movement in x and y, rotation
Use an until statement to drive at the set values until the target april tag is seen, then use a command to drive
itowards the limelight and autoalign a scoring mechanism.
*/