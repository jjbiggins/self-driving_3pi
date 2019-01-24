/*------------------------------------------------------------------------------
<<<<<<< .mine
 * Programmer: Shawn Rennegarbe & Joe Biggins
 * Date: March 7, 2017
 * Description: File contains the function prototypes for track and PiDFunctions.cpp.
 *      These functions are used to move the robot around the track.
=======
 * Programmer: Shawn Rennegarbe & Joe Biggins
 * Date: March 8, 2017
 * Description: This file contains the prototypes for the functions in
 *              trackAndPiDFunctions.cpp used to move the robot around
 *              the track. These functions are called in hw3.cpp.
>>>>>>> .r110290
 -------------------------------------------------------------------------------*/

#ifndef HW2_TRACKANDPIDFUNCTIONS_H
#define HW2_TRACKANDPIDFUNCTIONS_H

#include "trackSelect.h"
#include <pololu/3pi.h>
#include <avr/pgmspace.h>
#include <stdlib.h>

// Prototype of required functions
void set_PID_InputValues(pidController *PID, trackSelector *trackSelect);

void calculate_width(trackSelector *trackSelect);

void white_counter_width(trackSelector *trackSelect);

void onBlackStripe(trackSelector *trackSelect);

void detect_RoadSigns(trackSelector *trackSelect);

void white_counter(trackSelector *trackSelect);

void black_counter(trackSelector *trackSelect);

#endif //HW2_TRACKANDPIDFUNCTIONS_H
