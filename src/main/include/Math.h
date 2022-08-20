#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#include <frc/XboxController.h>

class Math
{
  public:
  void MathPeriodic();

  enum module_location
    {
      FORE_PORT,
      FORE_STARBOARD,
      AFT_PORT,
      AFT_STARBOARD,
    };

  std::vector<double> get_strafe_vector(double &x_target, double &y_target);

  std::vector<double> get_turn_vector(double &y_target,
                                      module_location rmodule);

  std::vector<double> get_final_vector(std::vector<double> &strafe_vector,
                                       std::vector<double> &turn_vector);

  std::vector<double> xy_to_zm(std::vector<double> &in_vector);

  std::vector<double> zm_to_xy(std::vector<double> &in_vector);

 private:

  frc::XboxController m_stick {0};

  // The best angles for turning clockwise.
  // All units are radians.
  const double FORE_PORT_TURN_ANGLE = 0.78549815;
  const double FORE_STARBOARD_TURN_ANGLE = -0.78549815;
  const double AFT_PORT_TURN_ANGLE = 2.35619;
  const double AFT_STARBOARD_TURN_ANGLE =  -2.35619;


};
