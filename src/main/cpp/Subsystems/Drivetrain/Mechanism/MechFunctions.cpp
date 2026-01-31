#include "subsystems/Mechanism/MechFunctions.hpp"

MechFunctions::MechFunctions(){}

frc2::StartEndCommand MechFunctions::Mech_1_Foward(){
	return frc2::StartEndCommand(
		[this] {m_Mech_1.setMech_1(0.6);}, 
		[this] { m_Mech_1.setMech_1(0); }
	);
}

frc2::StartEndCommand MechFunctions::Mech_1_Backward(){
	return frc2::StartEndCommand(
		[this] { m_Mech_1.setMech_1(-0.6); } , 
		[this] { m_Mech_1.setMech_1(0); } 
	);
}
frc2::StartEndCommand MechFunctions::Mech_2_Foward(){
	return frc2::StartEndCommand(
		[this] {m_Mech_2.setMech_2(0.6);}, 
		[this] { m_Mech_2.setMech_2(0); }
	);
}

frc2::StartEndCommand MechFunctions::Mech_2_Backward(){
	return frc2::StartEndCommand(
		[this] { m_Mech_2.setMech_2(-0.6); } , 
		[this] { m_Mech_2.setMech_2(0); } 
	);
}
frc2::StartEndCommand MechFunctions::Mech_3_Foward(){
	return frc2::StartEndCommand(
		[this] {m_Mech_3.setMech_3(0.6);}, 
		[this] { m_Mech_3.setMech_3(0); }
	);
}

frc2::StartEndCommand MechFunctions::Mech_3_Backward(){
	return frc2::StartEndCommand(
		[this] { m_Mech_3.setMech_3(-0.6); } , 
		[this] { m_Mech_3.setMech_3(0); } 
	);
}
frc2::StartEndCommand MechFunctions::Mech_4_Foward(){
	return frc2::StartEndCommand(
		[this] {m_Mech_4.setMech_4(0.6);}, 
		[this] { m_Mech_4.setMech_4(0); }
	);
}

frc2::StartEndCommand MechFunctions::Mech_4_Backward(){
	return frc2::StartEndCommand(
		[this] { m_Mech_4.setMech_4(-0.6); } , 
		[this] { m_Mech_4.setMech_4(0); } 
	);
}
frc2::StartEndCommand MechFunctions::Mech_5_Foward(){
	return frc2::StartEndCommand(
		[this] {m_Mech_5.setMech_5(0.6);}, 
		[this] { m_Mech_5.setMech_5(0); }
	);
}

frc2::StartEndCommand MechFunctions::Mech_5_Backward(){
	return frc2::StartEndCommand(
		[this] { m_Mech_5.setMech_5(-0.6); } , 
		[this] { m_Mech_5.setMech_5(0); } 
	);
}
frc2::StartEndCommand MechFunctions::Mech_6_Foward(){
	return frc2::StartEndCommand(
		[this] {m_Mech_6.setMech_6(0.1);}, 
		[this] { m_Mech_6.setMech_6(0); }
	);
}

frc2::StartEndCommand MechFunctions::Mech_6_Backward(){
	return frc2::StartEndCommand(
		[this] { m_Mech_6.setMech_6(-0.1); } , 
		[this] { m_Mech_6.setMech_6(0); } 
	);
}


/*
void alignArm(bool align){

}
*/
