/**
	@brief intro scene
	@author bodguy
	@date 17.07.17
	@todo 
	@bug 
*/

#ifndef SplashScene_h
#define SplashScene_h

#include "TheodoreEngine.h"

namespace Theodore {
	class SplashScene : public Scene {
	public:
		SplashScene() : Scene("SplashScene") {
			speed = 20.f;
			rotationY = 0.f;
			rotationX = 0.f;
			sensitivity = 8.0f;
			moveSensitivity = 0.5f;
			fieldOfView = 60.f;
		}

		virtual ~SplashScene() {}

		virtual void OnAwake() {
			tiger = new GameObject("spriteTest", this);
			tiger->AddComponent<SpriteRenderer>()->SetSprite(
				Sprite::Create(AssetManager::RequestTexture("Contents/sprite.png", TextureFormat::RGBA32)));
			rigidBody = tiger->AddComponent<RigidBody2D>();

			SceneManager::GetMainCamera()->GetTransform()->Translate(Vector3d(0.f, 0.f, 20.f));
		}

		virtual void OnUpdate() {
			Transform* trans = tiger->GetTransform();

			if (Input::GetKeyHeld(KEY_RIGHT)) {
				trans->Translate(trans->GetRight() * Vector3d(0.2f, 0.f, 0.f));
			}
			else if (Input::GetKeyHeld(KEY_LEFT)) {
				trans->Translate(-trans->GetRight() * Vector3d(0.2f, 0.f, 0.f));
			}
			else if (Input::GetKeyHeld(KEY_UP)) {
				trans->Translate(trans->GetUp() * Vector3d(0.f, 0.2f, 0.f));
			}
			else if (Input::GetKeyHeld(KEY_DOWN)) {
				trans->Translate(-trans->GetUp() * Vector3d(0.f, 0.2f, 0.f));
			}
			else if (Input::GetKeyDown(KEY_1)) {
				rigidBody->AddForce(Vector2d(0.f, 2.f));
			}
			else if (Input::GetKeyDown(KEY_2)) {
				rigidBody->AddTorque(2.f);
			}

			CameraUpdate();
		}

		void CameraUpdate() {
			if (Input::GetKeyDown(KEY_ESCAPE)) {
				Platform::GetInstance()->Quit();
			}

			Camera* cam = SceneManager::GetMainCamera();
			Transform* trans = cam->GetTransform();

			if (Input::GetMouseButtonHeld(MOUSE_LEFT)) {
				Vector3d right = SceneManager::GetMainCamera()->GetTransform()->GetRight();
				right *= Input::GetMouseDeltaPosition().x * moveSensitivity * Time::DeltaTime();
				SceneManager::GetMainCamera()->GetTransform()->Translate(right);

				Vector3d up = SceneManager::GetMainCamera()->GetTransform()->GetUp();
				up *= Input::GetMouseDeltaPosition().y * moveSensitivity * Time::DeltaTime();
				SceneManager::GetMainCamera()->GetTransform()->Translate(-up);
			}

			if (Input::GetKeyHeld(KEY_LSHIFT) || Input::GetKeyHeld(KEY_RSHIFT)) {
				speed = 100.f;
			}
			else {
				speed = 20.f;
			}

			// camera translation
			if (Input::GetKeyHeld(KEY_D)) {
				Vector3d right = trans->GetRight();
				right *= speed * Time::DeltaTime();
				SceneManager::GetMainCamera()->GetTransform()->Translate(right);
			}
			else if (Input::GetKeyHeld(KEY_A)) {
				Vector3d left = trans->GetRight();
				left *= -speed * Time::DeltaTime();
				trans->Translate(left);
			}
			else if (Input::GetKeyHeld(KEY_W)) {
				Vector3d forward = trans->GetForward();
				forward *= speed * Time::DeltaTime();
				trans->Translate(forward);
			}
			else if (Input::GetKeyHeld(KEY_S)) {
				Vector3d backward = trans->GetForward();
				backward *= -speed * Time::DeltaTime();
				trans->Translate(backward);
			}
			else if (Input::GetKeyHeld(KEY_Q)) {
				Vector3d down = trans->GetUp();
				down *= -speed * Time::DeltaTime();
				trans->Translate(down);
			}
			else if (Input::GetKeyHeld(KEY_E)) {
				Vector3d up = trans->GetUp();
				up *= speed * Time::DeltaTime();
				trans->Translate(up);
			}

			// camera rotation
			if (Input::GetMouseButtonHeld(MOUSE_RIGHT)) {
				// zoom in, out
				if (Input::GetKeyHeld(KEY_V)) {
					fieldOfView++;
				}
				else if (Input::GetKeyHeld(KEY_C)) {
					fieldOfView--;
				}
				cam->SetFieldOfView(fieldOfView);

				rotationY = Input::GetMouseDeltaPosition().x * sensitivity * Time::DeltaTime();
				rotationX = Input::GetMouseDeltaPosition().y * sensitivity * Time::DeltaTime();

				trans->Rotate(Vector3d::up, -rotationY);
				trans->Rotate(trans->GetRight(), -rotationX);
			}
			else {
				fieldOfView = 60.f;
				cam->ResetFieldOfView();
			}
		}

		GameObject* tiger;
		RigidBody2D* rigidBody;
		float speed;
		float rotationY;
		float rotationX;
		float sensitivity;
		float moveSensitivity;
		float fieldOfView;
	};
}

#endif /* SplashScene_h */