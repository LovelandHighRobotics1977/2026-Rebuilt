/*
 __         __     ______     ______     __   __     ______     ______    
╱╲ ╲       ╱╲ ╲   ╱╲  ___╲   ╱╲  ___╲   ╱╲ "-.╲ ╲   ╱╲  ___╲   ╱╲  ___╲   
╲ ╲ ╲____  ╲ ╲ ╲  ╲ ╲ ╲____  ╲ ╲  __╲   ╲ ╲ ╲-.  ╲  ╲ ╲___  ╲  ╲ ╲  __╲   
 ╲ ╲_____╲  ╲ ╲_╲  ╲ ╲_____╲  ╲ ╲_____╲  ╲ ╲_╲╲"╲_╲  ╲╱╲_____╲  ╲ ╲_____╲ 
  ╲╱_____╱   ╲╱_╱   ╲╱_____╱   ╲╱_____╱   ╲╱_╱ ╲╱_╱   ╲╱_____╱   ╲╱_____╱ 
                                                                          
                               License                                             

Copyright (c) FIRST and other WPILib contributors. 
Open Source Software; you can modify and╱or share it under the terms of 
the WPILib BSD license file in the root directory of this project.

The license is also pasted below for reference:

================

Copyright (c) 2009-2024 FIRST and other WPILib contributors
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and╱or other materials provided with the distribution.
   * Neither the name of FIRST, WPILib, nor the names of other WPILib
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY FIRST AND OTHER WPILIB CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY NONINFRINGEMENT AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL FIRST OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

================
 ______     ______     ______     _____     __     ______   ______    
╱╲  ___╲   ╱╲  == ╲   ╱╲  ___╲   ╱╲  __-.  ╱╲ ╲   ╱╲__  _╲ ╱╲  ___╲   
╲ ╲ ╲____  ╲ ╲  __<   ╲ ╲  __╲   ╲ ╲ ╲╱╲ ╲ ╲ ╲ ╲  ╲╱_╱╲ ╲╱ ╲ ╲___  ╲  
 ╲ ╲_____╲  ╲ ╲_╲ ╲_╲  ╲ ╲_____╲  ╲ ╲____-  ╲ ╲_╲    ╲ ╲_╲  ╲╱╲_____╲ 
  ╲╱_____╱   ╲╱_╱ ╱_╱   ╲╱_____╱   ╲╱____╱   ╲╱_╱     ╲╱_╱   ╲╱_____╱ 
                                                                      
                                Credits

Lead Programmer: 
    - Gabe
    -Collin
Assistant Programmer: 
    -Dinesh  

Loveland High Robotics programming team:            
     [ Willem ]
    [ Bradley ]     
        
Leacy Programers
    [ Wyllow  ]  [ Jacob  ]
    [Dean Morgan] [Salem Lessem]
Team mentors:
    - Mike Pintaric
    - Bruce Bowman

FRC teams:
    - 1977: The PowerSquids
    - 1822: Electric Calamari

Sites I used for this file to make it look *fancy*:
    - https://tree.nathanfriend.io/
    - https://patorjk.com/software/taag/

 ______     ______   ______     __  __     ______     ______   __  __     ______     ______    
╱╲  ___╲   ╱╲__  _╲ ╱╲  == ╲   ╱╲ ╲╱╲ ╲   ╱╲  ___╲   ╱╲__  _╲ ╱╲ ╲╱╲ ╲   ╱╲  == ╲   ╱╲  ___╲   
╲ ╲___  ╲  ╲╱_╱╲ ╲╱ ╲ ╲  __<   ╲ ╲ ╲_╲ ╲  ╲ ╲ ╲____  ╲╱_╱╲ ╲╱ ╲ ╲ ╲_╲ ╲  ╲ ╲  __<   ╲ ╲  __╲   
 ╲╱╲_____╲    ╲ ╲_╲  ╲ ╲_╲ ╲_╲  ╲ ╲_____╲  ╲ ╲_____╲    ╲ ╲_╲  ╲ ╲_____╲  ╲ ╲_╲ ╲_╲  ╲ ╲_____╲ 
  ╲╱_____╱     ╲╱_╱   ╲╱_╱ ╱_╱   ╲╱_____╱   ╲╱_____╱     ╲╱_╱   ╲╱_____╱   ╲╱_╱ ╱_╱   ╲╱_____╱ 
                                                                                               
                                            Structure

.
└── Main/
    ├── cpp/
    │   ├── Control/
    │   │   └── Autonomous.cpp
    │   ├── RobotBase/
    │   │   ├── Robot.cpp
    │   │   └── RobotContainer.cpp
    │   └── Subsystems/
    │       ├── Drivetrain/
    │       │   ├── Commands.cpp
    │       │   ├── DriveSubsystem.cpp
    │       │   └── SwerveModule.cpp
    │       ├── NoteMechanism/
    │       │   ├── Intake.cpp
    │       │   ├── NoteMechanism.cpp
    │       │   └── Shooter.cpp
    │       └── Climber/
    │           ├── Climber.cpp
    │           └── Actuator.cpp
    └── include/
        ├── Control/
        │   ├── Autonomous.h
        │   └── Controllers.h
        ├── Headers╱
        │   ├── Headers.h
        │   ├── Libraries.h
        │   ├── ProjectInfo.h
        │   └── Util.h
        ├── RobotBase/
        │   ├── Parameters/
        │   │   ├── AutoParameters.h
        │   │   ├── MechParameters.h
        │   │   ├── RobotParameters.h        { Include this file to include all parameters }
        │   │   └── TeleopParameters.h
        │   ├── Specifications/
        │   │   ├── FullBotKrakens.h
        │   │   ├── GenericFalcons.h
        │   │   └── RobotSpecifications.h    { Include this file to include correct specifications }
        │   ├── Robot.h
        │   └── RobotContainer.h
        └── Subsystems/
            ├── Devices/
            │   ├── Devices.h
            │   ├── Field.h
            │   ├── Gyro.h
            │   └── PDH.h
            ├── Drivetrain/
            │   ├── Commands.h
            │   ├── DriveSubsystem.h
            │   └── SwerveModule.h
            ├── NoteMechanism/
            │   ├── Intake.h
            │   ├── NoteMechanism.h
            │   └── Shooter.h
            └── Climber/
                ├── Climber.h
                └── Actuator.h


 ______     ______     ______     ______     ______  
╱╲  == ╲   ╱╲  __ ╲   ╱╲  == ╲   ╱╲  __ ╲   ╱╲__  _╲ 
╲ ╲  __<   ╲ ╲ ╲╱╲ ╲  ╲ ╲  __<   ╲ ╲ ╲╱╲ ╲  ╲╱_╱╲ ╲╱ 
 ╲ ╲_╲ ╲_╲  ╲ ╲_____╲  ╲ ╲_____╲  ╲ ╲_____╲    ╲ ╲_╲ 
  ╲╱_╱ ╱_╱   ╲╱_____╱   ╲╱_____╱   ╲╱_____╱     ╲╱_╱ 
                                                     
                      Robot Info

                        

*/