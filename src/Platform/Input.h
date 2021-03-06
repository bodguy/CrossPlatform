// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#ifndef Input_h
#define Input_h

#include <map>

#include "KeyCode.h"
#include "Math/Vector3d.h"

namespace Theodore {
  class InputHandler {
  public:
    InputHandler(KeyCode positive, KeyCode negative, float delta);
    ~InputHandler();

    KeyCode GetPositive() const;
    KeyCode GetNegative() const;

    float GetAccumulator() const;
    void Accumulate(float delta);
    void ResetAccumulator();
    float GetDelta() const;

  private:
    KeyCode mPositive;
    KeyCode mNegative;
    float mAccumulator;
    float mDeltaSpeed;
  };

  class Input {
  public:
    Input();
    ~Input();

    void Update();

    static bool GetKeyDown(KeyCode keyCode);
    static bool GetKeyUp(KeyCode keyCode);
    static bool GetKeyHeld(KeyCode keyCode);

    static Vector3d GetMousePosition();
    static Vector3d GetMouseDeltaPosition();
    static bool GetMouseButtonDown(MouseButton button);
    static bool GetMouseButtonUp(MouseButton button);
    static bool GetMouseButtonHeld(MouseButton button);

    static bool AddAxis(const std::string& axisName, InputHandler* handler);
    static float GetAxis(const std::string& axis);
    static float GetAxisRaw(const std::string& axis);

    // Any key or mouse button down
    static bool AnyKeyDown();
    // Any key or mouse button up
    static bool AnyKeyUp();
    // Any key or mouse button get held
    static bool AnyKeyHeld();

  private:
    static Input* instance;

    bool mPreviousKeys[KEY_MAX];
    bool mCurrentKeys[KEY_MAX];

    bool mPreviousMouseButtons[MOUSE_BUTTON_MAX];
    bool mCurrentMouseButtons[MOUSE_BUTTON_MAX];

    std::map<std::string, InputHandler*> mHandlerMapping;

    Vector3d mlastMousePos;
    Vector3d mMouseDelta;
  };
}  // namespace Theodore

#endif /* Input_h */
