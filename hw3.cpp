/*------------------------------------------------------------------------------
 * Programmer: Shawn Rennegarbe & Joe Biggins
 * Date:March 8, 2017
 * Description: hw3.cpp is the main file for Homework 3 in CIE.  The object of
 *      this homework is to move the 3pi robot around tracks as fast as possible
 *      using its sensors. The robot must recognize the track, beep when passing a
 *      road sign, and use several mathematical functions to get it to drive.
 -------------------------------------------------------------------------------*/

#include "robotHelperFunctions.h"
#include "pid.h"
#include "trackAndPiDFunctions.h"
#include "trackSelect.h"
#include <pololu/Pololu3pi.h>

int main() {
  // set up the 3pi
  initializeRobot();
  pidController PID;
  trackSelector trackSelect;

  unsigned int sensors[5] = {0}; // an array to hold sensor values
  unsigned int position;

  trackSelect.setM_TrackType(TRACK0);
  set_motors(trackSelect.getM_Speed(), trackSelect.getM_Speed());
  clear();

  while (1) {
    // This is the "main loop" - it will run forever.
    // Get the position of the line.  Note that we *must* provide
    // the "sensors" argument to read_line() here, even though we
    // are not interested in the individual sensor readings.

    position = read_line(sensors, IR_EMITTERS_ON);
    lcd_goto_xy(0, 1);
    display_readings(sensors);

    // determine if sensors ar on black stripe
    if (sensors[0] > 700 && sensors[4] > 700) {
      //call function to count the amount of times the black stripe is sensed
      black_counter(&trackSelect);

      //use this to create a beep for the stripe
      if (trackSelect.getM_WhiteCounter() > 0) {
        detect_RoadSigns(&trackSelect);
      }
    }
    else {
      //increment white counter when not on black stripe
      white_counter(&trackSelect);
      onBlackStripe(&trackSelect);
    }

    // use to steer robot using PID
    int proportional = ((int) position) - 2000; //changes proportional values to be centered around 0 rather than 2000 (value returned if on track)
    PID.setM_Proportional(proportional);
    set_PID_InputValues(&PID, &trackSelect);
  }
}





































    /*
    else{
      int white_counter = trackSelect.getM_WhiteCounter();
      trackSelect.setM_WhiteCounter((white_counter + 1));
      if(trackSelect.getM_WhiteCounter() > 500){
        num_black_stripes = 0;
      }
    }
    if(num_black_stripes == 0){
      clear();
      lcd_goto_xy(1, 0);
    }
    else if(num_black_stripes < 50){
      lcd_goto_xy(1,0);
      clear();
      trackSelect.setM_TrackType(1);
      print_long(trackSelect.getM_TrackType());
    }
    else if(num_black_stripes < 80){
      lcd_goto_xy(1, 0);
      clear();
      trackSelect.setM_TrackType(2);
      print_long(trackSelect.getM_TrackType());
    }
    else if(num_black_stripes < 100) {
      lcd_goto_xy(1, 0);
      clear();
      trackSelect.setM_TrackType(3);
      print_long(trackSelect.getM_TrackType());
    }
    else if(num_black_stripes < 200) {
      lcd_goto_xy(1, 0);
      clear();
      trackSelect.setM_TrackType(4);
      print_long(trackSelect.getM_TrackType());
    }*/




