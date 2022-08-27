#include "Control.h"

Control::Control(){
  //Initalize PID Controlers

  //Restore to factory default to prevent UB
  m_FORE_PORT_MOTOR.ConfigFactoryDefault();
  m_FORE_STARBOARD_MOTOR.ConfigFactoryDefault();
  m_AFT_PORT_MOTOR.ConfigFactoryDefault();
  m_AFT_STARBOARD_MOTOR.ConfigFactoryDefault();

  //Configure Sensor Source
  m_FORE_PORT_MOTOR.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
  m_FORE_STARBOARD_MOTOR.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
  m_AFT_PORT_MOTOR.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
  m_AFT_STARBOARD_MOTOR.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);

    // Set the peak and nominal outputs
  m_FORE_PORT_MOTOR.ConfigNominalOutputForward(0, 10);
  m_FORE_PORT_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_FORE_PORT_MOTOR.ConfigPeakOutputForward(m_shooterCoeff.kMaxOutput, 10);
  m_FORE_PORT_MOTOR.ConfigPeakOutputReverse(m_shooterCoeff.kMinOutput, 10);

  m_FORE_STARBOARD_MOTOR.ConfigNominalOutputForward(0, 10);
  m_FORE_STARBOARD_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_FORE_STARBOARD_MOTOR.ConfigPeakOutputForward(m_shooterCoeff.kMaxOutput, 10);
  m_FORE_STARBOARD_MOTOR.ConfigPeakOutputReverse(m_shooterCoeff.kMinOutput, 10);

  m_AFT_PORT_MOTOR.ConfigNominalOutputForward(0, 10);
  m_AFT_PORT_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_AFT_PORT_MOTOR.ConfigPeakOutputForward(m_shooterCoeff.kMaxOutput, 10);
  m_AFT_PORT_MOTOR.ConfigPeakOutputReverse(m_shooterCoeff.kMinOutput, 10);

  m_AFT_STARBOARD_MOTOR.ConfigNominalOutputForward(0, 10);
  m_AFT_STARBOARD_MOTOR.ConfigNominalOutputReverse(0, 10);
  m_AFT_STARBOARD_MOTOR.ConfigPeakOutputForward(m_shooterCoeff.kMaxOutput, 10);
  m_AFT_STARBOARD_MOTOR.ConfigPeakOutputReverse(m_shooterCoeff.kMinOutput, 10);


  // Tuning config
  m_FORE_PORT_MOTOR.SelectProfileSlot(0, 0);
  m_FORE_PORT_MOTOR.Config_kF(0, m_shooterCoeff.kFF, 10);
  m_FORE_PORT_MOTOR.config_kP(0, m_shooterCoeff.kP, 10);
  m_FORE_PORT_MOTOR.Config_kI(0, m_shooterCoeff.kI, 10);
  m_FORE_PORT_MOTOR.Config_kD(0, m_shooterCoeff.kD, 10);

  m_FORE_STARBOARD_MOTOR.SelectProfileSlot(0, 0);
  m_FORE_STARBOARD_MOTOR.Config_kF(0, m_shooterCoeff.kFF, 10);
  m_FORE_STARBOARD_MOTOR.config_kP(0, m_shooterCoeff.kP, 10);
  m_FORE_STARBOARD_MOTOR.Config_kI(0, m_shooterCoeff.kI, 10);
  m_FORE_STARBOARD_MOTOR.Config_kD(0, m_shooterCoeff.kD, 10);

  m_AFT_PORT_MOTOR.SelectProfileSlot(0, 0);
  m_AFT_PORT_MOTOR.Config_kF(0, m_shooterCoeff.kFF, 10);
  m_AFT_PORT_MOTOR.config_kP(0, m_shooterCoeff.kP, 10);
  m_AFT_PORT_MOTOR.Config_kI(0, m_shooterCoeff.kI, 10);
  m_AFT_PORT_MOTOR.Config_kD(0, m_shooterCoeff.kD, 10);

  m_AFT_STARBOARD_MOTOR.SelectProfileSlot(0, 0);
  m_AFT_STARBOARD_MOTOR.Config_kF(0, m_shooterCoeff.kFF, 10);
  m_AFT_STARBOARD_MOTOR.config_kP(0, m_shooterCoeff.kP, 10);
  m_AFT_STARBOARD_MOTOR.Config_kI(0, m_shooterCoeff.kI, 10);
  m_AFT_STARBOARD_MOTOR.Config_kD(0, m_shooterCoeff.kD, 10);
}

void Control::dashboard_init() {

  frc::SmartDashboard::PutNumber("Shooter P Gain", m_shooterCoeff.kP);
  frc::SmartDashboard::PutNumber("Shooter I Gain", m_shooterCoeff.kI);
  frc::SmartDashboard::PutNumber("Shooter D Gain", m_shooterCoeff.kD);
  frc::SmartDashboard::PutNumber("Shooter FF Gain", m_shooterCoeff.kFF);


  frc::SmartDashboard::PutNumber("Shooter P Gain", m_shooterCoeff.kP);
  frc::SmartDashboard::PutNumber("Shooter I Gain", m_shooterCoeff.kI);
  frc::SmartDashboard::PutNumber("Shooter D Gain", m_shooterCoeff.kD);
  frc::SmartDashboard::PutNumber("Shooter FF Gain", m_shooterCoeff.kFF);


  frc::SmartDashboard::PutNumber("Overridden RPM", m_overrideRPM);
  frc::SmartDashboard::PutNumber("Shooter P Gain", m_shooterCoeff.kP);
  frc::SmartDashboard::PutNumber("Shooter I Gain", m_shooterCoeff.kI);
  frc::SmartDashboard::PutNumber("Shooter D Gain", m_shooterCoeff.kD);
  frc::SmartDashboard::PutNumber("Shooter FF Gain", m_shooterCoeff.kFF);


  frc::SmartDashboard::PutNumber("Shooter P Gain", m_shooterCoeff.kP);
  frc::SmartDashboard::PutNumber("Shooter I Gain", m_shooterCoeff.kI);
  frc::SmartDashboard::PutNumber("Shooter D Gain", m_shooterCoeff.kD);
  frc::SmartDashboard::PutNumber("Shooter FF Gain", m_shooterCoeff.kFF);

}
void Control::read_dashboard(){}
void Control::fore_port(std::vector<double> &target){}
void Control::fore_starboard(std::vector<double> &target){}
void Control::aft_port(std::vector<double> &target){}
void Control::aft_starboard(std::vector<double> &target){}

Control::~Control(){}
