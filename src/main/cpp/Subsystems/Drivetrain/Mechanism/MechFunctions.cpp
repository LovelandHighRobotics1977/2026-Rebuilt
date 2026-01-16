#include "subsystems/Mechanism/MechFunctions.hpp"

MechFunctions::MechFunctions(){}

frc2::StartEndCommand MechFunctions::Mech_1_Foward(){
	return frc2::StartEndCommand(
		[this] {m_Mech_1.setMech_1(0.4); } , 
		[this] { m_Mech_1.setMech_1(0); }
	);
}

frc2::StartEndCommand MechFunctions::Mech_1_Backward(){
	return frc2::StartEndCommand(
		[this] { m_Mech_1.setMech_1(-0.4); } , 
		[this] { m_Mech_1.setMech_1(0); } 
	);
}


/*
void alignArm(bool align){

}
*/
