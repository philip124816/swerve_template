#include "Math.h"

void Math::MathPeriodic()
{
  /* https://docs.google.com/presentation/d/1IBYSYjfh4JwQ7NEGU0dBCiW33O0HDwejURL-Y8JQ0Gg/edit#slide=id.g13ef22b85ee_2_50
     was used as a guide for this code.
  */
  /*
   Note that XY vectors are composed of two doubles of an x coordinate
   and a y coordinate respectively.
   The value of each double can range from -1 to 1 which correspond directly
   to throttle values.
  */
  double x_target = m_stick.GetLeftX();
  double y_target = m_stick.GetLeftY();
  double z_target = m_stick.GetRightY();

  std::vector<double> strafe_vector;
  std::vector<double> turn_vector;

  strafe_vector = get_strafe_vector(x_target, y_target);

  // tv means 'turn vector'
  std::vector<double> tv_fore_port = get_turn_vector(z_target,
                                                     Math::FORE_PORT);
  std::vector<double> tv_aft_port = get_turn_vector(z_target,
                                                     Math::AFT_PORT);

  std::vector<double> tv_fore_starboard = get_turn_vector(z_target,
                                                          Math::FORE_STARBOARD);

  std::vector<double> tv_aft_starboard = get_turn_vector(z_target,
                                                         Math::AFT_STARBOARD);

  // fv means final vector
//  final_vector = get_final_vector(strafe_vector, turn_vector, module)

  std::vector<double> fv_fore_port = get_final_vector(strafe_vector,
                                                      tv_fore_port);

  std::vector<double> fv_aft_port = get_final_vector(strafe_vector,
                                                     tv_aft_port);

  std::vector<double> fv_fore_starboard = get_final_vector(strafe_vector,
                                                           tv_fore_starboard);

  std::vector<double> fv_aft_starboard = get_final_vector(strafe_vector,
                                                          tv_aft_starboard);

}

/**
 * This function returns a XY vector given inputs for strafe.
 * An example of strafe vectors can be found here: https://0x0.st/oeqr.png
 * The vectors for strafing are the same for each wheel
 */
std::vector<double> Math::get_strafe_vector(double &x_target, double &y_target)
{
  // There is a non-zero chance that I screwed this up remarkably.
  // This differs from the 4499 documentation but it makes more sense.
  std::vector<double> x_vector = {x_target, 0.0};
  std::vector<double> y_vector = {0.0, y_target};

  std::vector<double> return_vector;

  return_vector = { ( x_vector[0] + y_vector[0] ),
                    ( x_vector[1] + y_vector[1] ) };

  return return_vector;
}

std::vector<double> Math::get_turn_vector(double &y_target,
                                           module_location module)
{

  /** Returns a ZM vector for turning.
   * The angle remains static regardless of the requested turn,
   * however the magnitude changes depending on the y input.
   */

  std::vector<double> turn_vector;

  switch (module)
    {
  case FORE_PORT:
    turn_vector[0] = FORE_PORT_TURN_ANGLE;
    break;

  case FORE_STARBOARD:
    turn_vector[0] = FORE_STARBOARD_TURN_ANGLE;
      break;

  case AFT_PORT:
       turn_vector[0] = AFT_PORT_TURN_ANGLE;
      break;

  case AFT_STARBOARD:
    turn_vector[0] = AFT_STARBOARD_TURN_ANGLE;
      break;

  default:
    std::cout << "ERROR: No module given for turn calculation." << "\n";
    return {0.0, 0.0};
    break;

  }

  turn_vector[1] = y_target;

  return turn_vector;
}

std::vector<double> Math::xy_to_zm(std::vector<double> &in_vector)
{
  /** Structure of a zm variable is composed of two doubles.
   * The first is the angle from straight forwards.
   * The second is a magnitude that ranges from 0 (no power) to 1 (full power)
   * It is possible that the current code could return a value larger than 0
   * such as sqrt(2).
   * It is unclear what should be done for that issue.
   */
  std::vector<double> out_vector;

  // Distance formula to determine magnitude.
  // Zeroes are included to stay true to the formula.

  out_vector[1] =
    ( std::sqrt( std::pow( ( in_vector[0] - 0.0 ), 2.0 ) +
                 std::pow( ( in_vector[1] - 0.0 ), 2.0 ) ) );

  // Now for the hard part, determining an angle given two points.
  // I do not understand how to do this, however, it looks like std::atan2 does

  //atan2 uses y,x
  // If the point is in quadrants III or IV it will return a negative value.
  // Said value is always the shortest angle from a ray that intersects 1,0

  out_vector[0] = std::atan2( in_vector[1], in_vector[0] );


  return out_vector;
}

std::vector<double> Math::zm_to_xy(std::vector<double> &in_vector)
{
  // Taken from https://keisan.casio.com/exec/system/1223527679#
  std::vector<double> out_vector;
  out_vector[0] = in_vector[1] * std::cos(in_vector[0]);
  out_vector[1] = in_vector[1] * std::sin(in_vector[0]);
  return out_vector;
}

std::vector<double> Math::get_final_vector(std::vector<double> &strafe_vector,
                                            std::vector<double> &turn_vector)
{
  turn_vector = zm_to_xy(turn_vector);
  std::vector<double> return_vector;
  return_vector[0] = (strafe_vector[0] + turn_vector[0]);
  return_vector[1] = (strafe_vector[1] + turn_vector[1]);
  return_vector = xy_to_zm(return_vector);
  return return_vector;
}
