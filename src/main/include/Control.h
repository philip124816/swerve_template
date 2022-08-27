#pragma once

#include <iostream>
#include <vector>
#include "ctre/Phoenix.h"

class Control
{
 public:
  Control();
  void dashboard_init();
  void read_dashboard();
  void fore_port(std::vector<double> &target);
  void fore_starboard(std::vector<double> &target);
  void aft_port(std::vector<double> &target);
  void aft_starboard(std::vector<double> &target);

  ~Control();

private:

  struct PidCoeff {
    double kP, kI, kD, kIz, kFF, kMaxOutput, kMinOutput;
  };

 WPI_talonFX m_FORE_PORT_MOTOR {};
 WPI_talonFX m_FORE_STARBOARD_MOTOR {};
 WPI_talonFX m_AFT_PORT_MOTOR {};
 WPI_talonFX m_AFT_STARBOARD_MOTOR {};
  //FP stands for Fore Port
  //FS stands for Fore Starboard
  //AP stands for Aft Port
  //AS stands for Aft Starboard
  PidCoeff m_FP_PID_COEF{};
  PidCoeff m_FS_PID_COEF{};
  PidCoeff m_AP_PID_COEF{};
  PidCoeff m_AS_PID_COEF{};
};
