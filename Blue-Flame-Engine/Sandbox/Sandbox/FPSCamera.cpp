#include "FPSCamera.h"
#include "BF/Engine.h"
#include "BF/Input/Mouse.h"
#include "BF/Input/Keyboard.h"
#include "BF/System/Debug.h"

using namespace BF::Input;
using namespace BF::Math;

FPSCamera::FPSCamera() :
	movmentSpeed(1.25f), sensitivity(0.05f), yaw(0.0f), pitch(0.0f), lockMouseToCenter(false)
{
	/*cameraFront = Vector3f::Forward();
	cameraUp = Vector3f::Up();
	windowCenter = Vector2f(floor((float)Engine::GetWindow().GetClientWidth() / 2.0f), floor((float)Engine::GetWindow().GetClientHeight() / 2.0f));
	BF::Input::Mouse::ShowMouseCursor(false);
	BF::Input::Mouse::SetPosition(windowCenter);

	position = Vector3f(0.326128f, 4.67649f, -8.06997f);
	yaw = 0.700000;
	pitch = -22.849997;*/
}

FPSCamera::~FPSCamera()
{
}

void FPSCamera::Start()
{
}

void FPSCamera::Update()
{
	/*if (Keyboard::IsKeyHeldDown(Keyboard::Key::Code::W))
		position += cameraFront * movmentSpeed;
	if (Keyboard::IsKeyHeldDown(Keyboard::Key::Code::S))
		position -= cameraFront * movmentSpeed;
	if (Keyboard::IsKeyHeldDown(Keyboard::Key::Code::D))
		position += cameraUp.Cross(cameraFront).Normalize() * movmentSpeed;
	if (Keyboard::IsKeyHeldDown(Keyboard::Key::Code::A))
		position -= cameraUp.Cross(cameraFront).Normalize() * movmentSpeed;

	if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Escape))
	{
		if (!lockMouseToCenter)
		{
			lockMouseToCenter = true;
			Mouse::ShowMouseCursor(false);
		}
		else if (lockMouseToCenter)
		{
			lockMouseToCenter = false;
			Mouse::ShowMouseCursor(true);
		}
	}

	if (lockMouseToCenter)
	{
		BF::Input::Mouse::SetPosition(windowCenter);
		yaw += (Mouse::GetPosition().x - windowCenter.x) * sensitivity;
		pitch += (windowCenter.y - Mouse::GetPosition().y) * sensitivity;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	cameraFront.x = sin(ToRadians(yaw)) * cos(ToRadians(pitch));
	cameraFront.y = sin(ToRadians(pitch));
	cameraFront.z = cos(ToRadians(yaw)) * cos(ToRadians(pitch));
	cameraFront = cameraFront.Normalize();

	systemBuffer.viewMatrix = Matrix4::LookAt(position, position + cameraFront, cameraUp);
	systemBuffer.cameraPosition = Vector4f(position.x, position.y, position.z, 1.0f);*/
}