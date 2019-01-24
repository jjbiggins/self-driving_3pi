/*------------------------------------------------------------------------------
<<<<<<< .mine
 * Programmer: Shawn Rennegarbe & Joe Biggins
 * Date: March 7, 2017
 * Description: Adjusts robot's speed based on track encountered
=======
 * Programmer: Shawn Rennegarbe & Joe Biggins
 * Date: March 8, 2017
 * Description: File contains class trackSelector used by robot when determining
 *          current track.  This is used to set the speed of the robot.
>>>>>>> .r110290
 -------------------------------------------------------------------------------*/
#ifndef HW2_GEAR_H
#define HW2_GEAR_H

#define TRACK0 0
#define TRACK1 1
#define TRACK2 2
#define TRACK3 3

#define TRACK0SPEED 250
#define TRACK1SPEED 250
#define TRACK2SPEED 250
#define TRACK3SPEED 250
#define TRACK4SPEED 250

#include <pololu/3pi.h>

class trackSelector {

public:

  int getM_Speed() const
  {
    return m_Speed;
  }

  void setM_Speed(int m_Speed)
  {
    trackSelector::m_Speed = m_Speed;
  }

  int getM_TrackType() const
  {
    return m_TrackType;
  }

  void setM_TrackType(int m_TrackType)
  {
    trackSelector::m_TrackType = m_TrackType;
  }

  void setM_WhiteCounter(int m_WhiteCounter)
  {
    trackSelector::m_WhiteCounter = m_WhiteCounter;
  }

  int getM_WhiteCounter() const
  {
    return m_WhiteCounter;
  }

  void setM_blackCounter(int m_blackCounter)
  {
    trackSelector::m_blackCounter = m_blackCounter;
  }

  int getM_blackCounter() const
  {
    return m_blackCounter;
  }

  void setM_onWhiteDistanceCovered(double m_onWhiteDistanceCovered)
  {
    trackSelector::m_onWhiteDistanceCovered = m_onWhiteDistanceCovered;
  }

  double getM_onWhiteDistanceCovered() const
  {
    return m_onWhiteDistanceCovered;
  }

  void setM_onBlackDistanceCovered(double m_onBlackDistanceCovered)
  {
    trackSelector::m_onBlackDistanceCovered = m_onBlackDistanceCovered;
  }

  double getM_onBlackDistanceCovered() const
  {
    return m_onBlackDistanceCovered;
  }

private:
  int m_Speed{TRACK0SPEED};
  int m_TrackType{TRACK0};
  int m_WhiteCounter{0};
  int m_blackCounter{0};
  double m_onWhiteDistanceCovered;
  double m_onBlackDistanceCovered;
};

#endif //HW2_GEAR_H
