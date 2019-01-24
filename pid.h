/*------------------------------------------------------------------------------
 * Programmer: Shawn Rennegarbe
 * Date: March 8, 2017
 * Description: File contains class pidController called in hw3. This class contains
 *          the proportional, integral, and derivative used to determine the
 *          movement necessary to get the robot back on the black line.
 -------------------------------------------------------------------------------*/
#ifndef HW2_PID_H
#define HW2_PID_H

class pidController {
public:

  int getM_Proportional() const
  {
    return m_Proportional;
  }

  void setM_Proportional(int m_Proportional)
  {
    pidController::m_Proportional = m_Proportional;
  }

  int getM_LastProportional() const
  {
    return m_LastProportional;
  }

  void setM_LastProportional(int m_LastProportional)
  {
    pidController::m_LastProportional = m_LastProportional;
  }

  int getM_Integral() const
  {
    return m_Integral;
  }

  void setM_Integral(int m_Integral)
  {
    pidController::m_Integral = m_Integral;
  }

  int getM_Differential() const
  {
    return m_Differential;
  }

  void setM_Differential(int m_Differential)
  {
    pidController::m_Differential = m_Differential;
  }

  int getLeftMotorSpeed() const
  {
    return m_leftMotorSpeed;
  }

  void setLeftMotorSpeed(int leftMotorSpeed)
  {
    pidController::m_leftMotorSpeed = leftMotorSpeed;
  }

  int getRightMotorSpeed() const
  {
    return m_rightMotorSpeed;
  }

  void setRightMotorSpeed(int rightMotorSpeed)
  {
    pidController::m_rightMotorSpeed = rightMotorSpeed;
  }

  int getM_powerDifference() const
  {
    return m_powerDifference;
  }

  void setM_powerDifference(int m_powerDifference)
  {
    pidController::m_powerDifference = m_powerDifference;
  }

private:
  int m_Proportional{0};
  int m_LastProportional{0};
  int m_Integral{0};
  int m_Differential{0};
  int m_powerDifference{0};
  int m_leftMotorSpeed{0};
  int m_rightMotorSpeed{0};
};

#endif //HW2_PID_H

