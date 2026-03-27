#pragma once

#include "subsystems/Mechanism/Mech.hpp"

class MechFunctions : public frc2::SubsystemBase {
	public:
		MechFunctions();

		frc2::StartEndCommand Mech_1_Foward();
		frc2::StartEndCommand Mech_1_Backward();
		frc2::StartEndCommand Mech_2_Foward();
		frc2::StartEndCommand Mech_2_Backward();
		frc2::StartEndCommand Mech_3_Foward();
		frc2::StartEndCommand Mech_3_Backward();
		frc2::StartEndCommand Mech_4_Foward();
		frc2::StartEndCommand Mech_4_Backward();
		frc2::StartEndCommand Mech_5_Foward();
		frc2::StartEndCommand Mech_5_Backward();
		frc2::StartEndCommand Mech_6_Foward();
		frc2::StartEndCommand Mech_6_Backward();
		frc2::SequentialCommandGroup rev();
		frc2::SequentialCommandGroup intake();
		frc2::SequentialCommandGroup shoot();

	private:


		Mech_1 m_Mech_1;
		Mech_2 m_Mech_2;
		Mech_3 m_Mech_3;
		Mech_4 m_Mech_4;
		Mech_5 m_Mech_5;
		Mech_6 m_Mech_6;
		

};

