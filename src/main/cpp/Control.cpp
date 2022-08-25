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

}
void Control::dashboard_init(){}
void Control::read_dashboard(){}
void Control::fore_port(std::vector<double> &target){}
void Control::fore_starboard(std::vector<double> &target){}
void Control::aft_port(std::vector<double> &target){}
void Control::aft_starboard(std::vector<double> &target){}

Control::~Control(){}
