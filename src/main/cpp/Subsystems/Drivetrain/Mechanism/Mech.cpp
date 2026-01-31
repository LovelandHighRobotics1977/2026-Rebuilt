#include "subsystems/Mechanism/Mech.hpp"

Mech_1::Mech_1() : mech_1_1{Mechanism::Mech_1_1}, mech_1_2{Mechanism::Mech_1_2}{
    mech1_1MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Coast);
    mech1_1MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::Clockwise_Positive);
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
Mech_2::Mech_2() : mech_2{Mechanism::Mech_2}{
    mech2MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Coast);
    mech2MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive);
    mech2MotorConfig.CurrentLimits.WithSupplyCurrentLimit(static_cast<units::current::ampere_t>(20));
    mech_2.GetConfigurator().Apply(mech2MotorConfig);
}

void Mech_2::setMech_2(double speed){
    mech_2.Set(speed);
}
Mech_3::Mech_3() : mech_3{Mechanism::Mech_3} {
    mech3MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Coast);
    mech3MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive);
    mech3MotorConfig.CurrentLimits.WithSupplyCurrentLimit(static_cast<units::current::ampere_t>(20));
    mech_3.GetConfigurator().Apply(mech3MotorConfig);
}

void Mech_3::setMech_3(double speed){
    mech_3.Set(speed);
}
Mech_4::Mech_4() : mech_4{Mechanism::Mech_4}{
    mech4MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Coast);
    mech4MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive);
    mech4MotorConfig.CurrentLimits.WithSupplyCurrentLimit(static_cast<units::current::ampere_t>(20));
    mech_4.GetConfigurator().Apply(mech4MotorConfig);
}

void Mech_4::setMech_4(double speed){
    mech_4.Set(speed);
}
Mech_5::Mech_5() : mech_5{Mechanism::Mech_5}{
    mech5MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Brake);
    mech5MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive);
    mech5MotorConfig.CurrentLimits.WithSupplyCurrentLimit(static_cast<units::current::ampere_t>(20));
    mech_5.GetConfigurator().Apply(mech5MotorConfig);

}

void Mech_5::setMech_5(double speed){
    mech_5.Set(speed);
    mech_5.Set(speed);
}
Mech_6::Mech_6() : mech_6{Mechanism::Mech_6}{
    mech6MotorConfig.MotorOutput.WithNeutralMode(ctre::phoenix6::signals::NeutralModeValue::Brake);
    mech6MotorConfig.MotorOutput.WithInverted(ctre::phoenix6::signals::InvertedValue::CounterClockwise_Positive);
    mech6MotorConfig.CurrentLimits.WithSupplyCurrentLimit(static_cast<units::current::ampere_t>(20));
    mech_6.GetConfigurator().Apply(mech6MotorConfig);
}

void Mech_6::setMech_6(double speed){
    mech_6.Set(speed);
    mech_6.Set(speed);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                