#include "subsystems/Mechanism/Mech.hpp"

Mech_1::Mech_1() : mech_1_1{Mechanism::Mech_1_1}, mech_1_2{Mechanism::Mech_1_2}{
    mech1_1MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Coast);
    mech1_1MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive);
    mech1_1MotorConfig.CurrentLimits.WithSupplyCurrentLimit(static_cast<units::current::ampere_t>(20));
    mech_1_1.GetConfigurator().Apply(mech1_1MotorConfig);

    mech1_2MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Coast);
    mech1_2MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::Clockwise_Positive);
    mech1_2MotorConfig.CurrentLimits.WithSupplyCurrentLimit(static_cast<units::current::ampere_t>(20));
    mech_1_2.GetConfigurator().Apply(mech1_2MotorConfig);

}

void Mech_1::setMech_1(double speed){
    mech_1_1.Set(speed);
    mech_1_2.Set(speed);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                