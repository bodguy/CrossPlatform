// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#ifndef Time_h
#define Time_h

#include <chrono>
#include <ctime>
#include <string>

namespace Theodore {
  typedef std::chrono::high_resolution_clock Clock;
  typedef std::chrono::duration<float, std::milli> milli;
  typedef std::chrono::time_point<Clock> TimePoint;

  class Time {
  public:
    Time();

    static void Reset();
    void Update();

    static float DeltaTime();
    static float DeltaTimeUnscaled();
    static float ElapsedTime();
    static float ElapsedTimeUnscaled();
    static float FixedDeltaTime();
    static float FixedDeltaTimeUnscaled();

    static int FPS();
    static void SetTimeScale(float value);
    static std::string GetDateTime();
    static TimePoint GetTime();
    static float GetInterval(TimePoint start, TimePoint end);

  private:
    static Time* instance;

    TimePoint mStart;
    TimePoint mCurrentTime;
    float mAccumulator;  // for internal use
    int mFrameCounter;   // for internal use
    int mFrameRate;
    float mTimeScale;

    float mDeltaTime;
    float mUnscaledDeltaTime;
    float mTime;
    float mUnscaledTime;
    float mFixedDeltaTime;
    float mUnscaledFixedDeltaTime;
  };
}  // namespace Theodore

#endif /* Time_h */
