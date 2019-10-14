// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#include "TheodoreEngine.h"

using namespace Theodore;

class MySampleScene : public Scene {
public:
  MySampleScene() : Scene("MySampleScene") {}
  virtual ~MySampleScene() override {}

  virtual void OnAwake() {
    Platform::ChangeTitle(SceneManager::GetActiveScene()->ToString());
  }
};

int main(int argc, char** argv) {
  Application app;
  PlatformContext context;
  context.width=1280;
  context.height=720;

  if (app.Initialize(context)) {
    app.Run();
  }

  return 0;
}