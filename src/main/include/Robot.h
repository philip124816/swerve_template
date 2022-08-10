// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include <vector>
#include <cmath>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
 public:
  std::vector<double> get_strafe_vector(double x_target, double y_target);

  std::vector<double> get_turn_vector(double yTarget,
                                    Robot::module_location module);

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


enum module_location
    {
      FORE_PORT,
      FORE_STARBOARD,
      AFT_PORT,
      AFT_STARBOARD,
    };

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;


  static const double MAX_ANGULAR_VELOCITY;
  static const double ROBOT_RADIUS;
  static const double TURN_MAPPING_CONST;
  // TURN_MAPPING_CONST is the number needed to multiply the driver input into
  // the target rotation speed.

const std::vector<double> FORE_PORT_TURN_VEC = {-1.0, -1.0};
const std::vector<double> FORE_STARBOARD_TURN_VEC = {1.0, -1.0};
const std::vector<double> AFT_PORT_TURN_VEC = {-1.0, 1.0};
const std::vector<double> AFT_STARBOARD_TURN_VEC {1.0, 1.0};

  // MN stands for 'magic number' in this context.
const std::vector<double> FORE_PORT_MN =  { ( (std::sqrt(2) * -1 ) /2 ),
                                                     ( std::sqrt(2) / 2 ) };

const std::vector<double> FORE_STARBOARD_MN( ( std::sqrt(2) / 2 ), 2);
  
const std::vector<double> AFT_PORT_MN( ( ( std::sqrt(2) * -1 ) / 2) , 2);

const std::vector<double> AFT_STARBOARD_MN = { (std::sqrt(2) / 2 ) ,
                                                        ( (std::sqrt(2) / -1 )
                                                          / 2)};

