#ifndef Transform_h
#define Transform_h

#include "Vector3d.h"
#include "Matrix4x4.h"
#include "Quaternion.h"

namespace Quark {
	class Transform {
	public:
		Transform();

		void Translate(const Vector3d& translation);
		void Rotate(const Vector3d& axis, float angle);
		void Rotate(const Vector3d& eulerAngles);

		Vector3d GetPosition() const;
		Vector3d GetScale() const;
		Vector3d GetRotation() const;

		Vector3d GetForward() const;
		Vector3d GetUp() const;
		Vector3d GetRight() const;
		Vector3d GetEulerAngles() const;

		Matrix4x4 GetLocalToWorldMatrix() const;
		Matrix4x4 GetWorldToLocalMatrix() const;

		void SetPosition(const Vector3d& position);
		void SetScale(const Vector3d& scale);
		void SetEulerAngles(const Vector3d& euler);

	private:
		Vector3d mPosition;
		Vector3d mScale;
		Quaternion mRotation;

		mutable Vector3d mForward;
		mutable Vector3d mUp;
		mutable Vector3d mRight;

		Vector3d mEulerAngles;
		mutable Matrix4x4 mLocalToWorldMatrix;
		mutable Matrix4x4 mWorldToLocalMatrix;
	};
}

#endif /* Transform_h */