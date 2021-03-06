// Copyright (C) 2017 by bodguy
// This code is licensed under Apache 2.0 license (see LICENSE.md for details)

#include "TheodoreEngine.h"

using namespace Theodore;

class CameraScene : public Scene {
public:
	CameraScene() : Scene("CameraScene") {}
	virtual ~CameraScene() override {}

	virtual void OnAwake() override {
		SceneManager::GetMainCamera()->GetTransform()->Translate(Vector3d(0.f, 0.f, 10.f));

		GameObject* spriteObject = new GameObject("mySpriteObject", this);
		spriteRenderer = spriteObject->AddComponent<SpriteRenderer>();
		Sprite* spriteSheet = Sprite::Create(AssetManager::RequestTexture(Application::GetResourcePath() + "dragon.png", TextureFormat::RGBA32));
		spriteRenderer->SetSprite(spriteSheet);
		spriteObject->GetTransform()->SetLocalScale(Vector3d(0.05f, 0.05f, 0.05f));
	}

	virtual void OnStart() override {
		Platform::ChangeTitle(SceneManager::GetActiveScene()->ToString());
	}

	virtual void OnUpdate() override {
		if (Input::GetKeyDown(KEY_ESCAPE)) {
			Platform::GetInstance()->Quit();
		}
		spriteRenderer->SetColor(Color::Lerp(Color(1.f, 0.f, 0.f, 1.f), Color(0.f, 1.f, 1.f, 1.f), Math::PingPong(Time::ElapsedTime(), 1.f)));
	}

private:
	SpriteRenderer* spriteRenderer;
};

int main(int argc, char** argv) {
	Application app;
	PlatformContext context;
	context.width = 1280;
	context.height = 720;

	if (app.Initialize(context)) {
		SceneManager::SetActiveScene(SceneManager::CreateScene<CameraScene>("CameraScene"));
		app.Run();
	}

	return 0;
}
