/*------------------------------------------------------------------------------
<<<<<<< .mine
 * Programmer: Shawn Rennegarbe & Joe Biggins
 * Date: March 7, 2017
 * Description: This file contains the functions called in hw3.cpp that move the 3pi
 *        robot around the tracks.  This involves using the proportional, derivative,
 *        and integral to calculate the distance the robot is from the black line and
 *        changing the motors to return the robot to the line.
=======
 * Programmer: Shawn Rennegarbe & Joe Biggins
 * Date: March 8, 2017
 * Description: This file contains the functions called in hw3.cpp to move the
 *      3pi robot around the tracks.  These contain functions that use mathmatical
 *      functions to determine the robot's position and use the robot's sensors
 *      to determine its surroundings.
>>>>>>> .r110290
 -------------------------------------------------------------------------------*/
#include "pid.h"
#include "trackSelect.h"
#include "trackAndPiDFunctions.h"





/*
 * Function sets PID values for each sensor reading. Reading uses proportional, integral, and
 * derivative to determine robot's position and movement needed to get the robot back on the
 * black line. This function also sets the motors necessary based on this reading.
 */
void set_PID_InputValues(pidController *PID, trackSelector *trackSelect){
  // The "proportional" term should be 0 when we are on the line.
  // Compute the derivative (change) and integral (sum) of the

  // NEGATIVE PROPORTIONAL == RIGHT OF LINE
  // POSITIVE PROPORTIONAL == LEFT OF LINE
  // 0 = ON THE LINE
  int proportional = PID->getM_Proportional();
  int last_proportional = PID->getM_LastProportional();
  int derivative = proportional - last_proportional;
  PID->setM_Differential(derivative);

  int integral = PID->getM_Integral();
  integral += proportional;
  PID->setM_Integral(integral);

  // Remember the last position.
  PID->setM_LastProportional(proportional);

  // Compute the difference between the two motor power settings,
  // m1 - m2.  If this is a positive number the robot will turn
  // to the right.  If it is a negative number, the robot will
  // turn to the left, and the magnitude of the number determines
  // the sharpness of the turn.
  int power_difference = proportional / 10 + integral / 600 + derivative * 7 / 2;
  PID->setM_powerDifference(power_difference);

  int base_speed = trackSelect->getM_Speed();

  //adjusts power difference so that following if/else statement can use only if <0 or >0

  //set power_difference so that following if/else statement can be used in two sets

  if (power_difference > base_speed) {
    power_difference = base_speed;
  }
  if (power_difference < -base_speed) {
    power_difference = -base_speed;
  }

  //robot is left of the line- turn right
  if (power_difference < 0){
    //robot is left of the line... turn right
    PID->setLeftMotorSpeed(base_speed + power_difference);
    PID->setRightMotorSpeed(base_speed);
    set_motors(base_speed + power_difference, base_speed); //make left wheel go faster
  }
  else{
    PID->setLeftMotorSpeed(base_speed);
    PID->setRightMotorSpeed(base_speed - power_difference);
    set_motors(base_speed, base_speed - power_difference);
  }

}


//function to count non-black
void white_counter(trackSelector *trackSelect){
  trackSelect->setM_WhiteCounter((trackSelect->getM_WhiteCounter() + 1));
  white_counter_width(trackSelect);
}
//function to count black stripe
void black_counter(trackSelector *trackSelect){
  trackSelect->setM_blackCounter((trackSelect->getM_blackCounter()+ 1));
  calculate_width(trackSelect);
}

//function to determine the distance traveled when not on black stripe
void white_counter_width(trackSelector *trackSelect){
  double base_speed = trackSelect->getM_Speed();
  int num_white = trackSelect->getM_WhiteCounter();
  double onWhiteDistanceCovered = base_speed * num_white;
  trackSelect->setM_onWhiteDistanceCovered(onWhiteDistanceCovered);
}


//Function calculates approximate distance covered from the time robot registers black for width of one stripe.
void calculate_width(trackSelector *trackSelect) {
  int base_speed = trackSelect->getM_Speed();
  int num_black_stripes = trackSelect->getM_blackCounter();
  double onBlackDistanceCovered = base_speed * num_black_stripes;
  trackSelect->setM_onBlackDistanceCovered(onBlackDistanceCovered);
}


//Function is used to detect the road signs passed along.
void detect_RoadSigns(trackSelector *trackSelect){
  (play(">g32>>c32"));
  trackSelect->setM_TrackType((trackSelect->getM_TrackType() + 1));
  print_long(trackSelect->getM_TrackType());
  trackSelect->setM_WhiteCounter(0);
}

// compare the two distances. if white is far greater. reset trackType and the black counter
void onBlackStripe(trackSelector *trackSelect) {
  if (5 * trackSelect->getM_onBlackDistanceCovered() < trackSelect->getM_onWhiteDistanceCovered()) {
    trackSelect->setM_TrackType(0);
    trackSelect->setM_blackCounter(0);
  }
}




















