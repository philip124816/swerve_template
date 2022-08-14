// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <iostream>


#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>

class Robot : public frc::TimedRobot {

 public:

  enum module_location
    {
      FORE_PORT,
      FORE_STARBOARD,
      AFT_PORT,
      AFT_STARBOARD,
    };

  std::vector<double> get_strafe_vector(double x_target, double y_target);

  std::vector<double> get_turn_vector(double yTarget,
                                      module_location module);

  std::vector<double> get_final_vector(std::vector<double> strafe_vector, 
                                       std::vector<double> turn_vector);

  std::vector<double> xy_to_zm(std::vector<double> in_vector);

  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;




 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::XboxController m_stick {0};

  // The best angles for turning clockwise
const double FORE_PORT_TURN_ANGLE = 45;
const double FORE_STARBOARD_TURN_ANGLE = 315
const double AFT_PORT_TURN_ANGLE = 135;
const double AFT_STARBOARD_TURN_ANGLE = 225;


};
