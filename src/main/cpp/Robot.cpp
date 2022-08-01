// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic()
{
  // NOTE: this project is a demo and not expected to work

  /*
   Note that XY vectors are composed of two doubles of an x coordinate
   and a y coordinate respectively.
   The value of each double can range from -1 to 1 which correspond directly
   to throttle values.
  */
  double x_target = m_stick.GetX();
  double y_target = m_stick.GetY();
  double z_target;

  std::vector<double> *strafe_vector;
  std::vector<double> *turn_vector;

  x_vector = &Robot::get_strafe_vector(&x_target, &y_target);
  y_vector = &Robot::get_y_vector();
  z_vector = &Robot::get_z_vector();

}

/**
 * This function returns a XY vector given inputs for strafe.
 * An example of strafe vectors can be found here: https://0x0.st/oeqr.png
 * The vectors for strafing are the same for each wheel
 */
std::vector<double> Robot::get_strafe_vector(double *x_target, double *y_target)
{
  std::vector<double> x_vector {&x_target, 0.0};
  std::vector<double> y_vector {0.0, &y_target};

  std::vector<double> return_vector;

  return_vector = { ( x_vector.at(0) + y_vector.at(0) ),
                    ( x_vector.at(1) + y_vector.at(1) ) };

  return return_vector;

double Robot::get_turn_vector(double yTarget) {}

double Robot::GetZVector(double zTarget) {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
