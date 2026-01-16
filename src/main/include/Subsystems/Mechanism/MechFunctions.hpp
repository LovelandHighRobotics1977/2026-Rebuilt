#pragma once

#include "subsystems/Mechanism/Mech.hpp"

class MechFunctions : public frc2::SubsystemBase {
	public:
		MechFunctions();

		frc2::StartEndCommand Mech_1_Foward();
		frc2::StartEndCommand Mech_1_Backward();



		//void alignArm(bool align);



	private:


		Mech_1 m_Mech_1;
		

};

