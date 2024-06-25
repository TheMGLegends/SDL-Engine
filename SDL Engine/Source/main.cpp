// INFO: SDL TESTING PURPOSES

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "Time/TimeHandler.h"
#include "Mathematics/Maths.h"
#include "Mathematics/Vector2.h"
#include "Mathematics/Transform.h"
#include "Debugging/Debug.h"
#include "Generics/Templates.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		Debug::LogError("SDL_Init Error: " + std::string(SDL_GetError()));
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("SDL Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, NULL);

	if (window == nullptr)
	{
		Debug::LogError("SDL_CreateWindow Error: " + std::string(SDL_GetError()));
		return 1;
	}

	// INFO: TimeHandler Testing
	/*
	for (int i = 0; i < 10000; i++)
	{
		TimeHandler::Tick();

		//std::cout << "ElapsedTime: " << TimeHandler::GetElapsedTime() << std::endl;
		std::cout << "DeltaTime: " << TimeHandler::GetDeltaTime() << std::endl;
	}
	*/

	// INFO: Vector2 Testing
	/*
	Vector2 v1(1.25f, 2.252f);

	Vector2::UP;
	Vector2::DOWN;
	Vector2::LEFT;
	Vector2::RIGHT;
	Vector2::ZERO;
	Vector2::ONE;

	Vector2 NormalizeV(5.0f, 10.0f);
	Vector2::Normalize(NormalizeV);

	Vector2 DotV1(2.5f, 5.0f);
	Vector2 DotV2(5.0f, 10.0f);
	Vector2::Dot(DotV1, DotV2);

	Vector2 DistanceV1(2.5f, 5.0f);
	Vector2 DistanceV2(5.0f, 10.0f);
	Vector2::Distance(DistanceV1, DistanceV2);

	Vector2 LerpV1(2.5f, 5.0f);
	Vector2 LerpV2(5.0f, 10.0f);
	float t = 0.5f;
	Vector2::Lerp(LerpV1, LerpV2, t);

	Vector2 MagnitudeV(5.0f, 10.0f);
	MagnitudeV.Magnitude();

	Vector2 SqrMagnitudeV(5.0f, 10.0f);
	SqrMagnitudeV.SqrMagnitude();

	Vector2 NormalizedV(5.0f, 10.0f);
	NormalizedV.Normalized();

	Vector2 V1(5.0f, 10.0f);
	Vector2 V2(10.0f, 20.0f);

	Vector2 V3 = V1 + V2;
	Vector2 V4 = V1 - V2;

	Vector2 V5 = V1 * V2;
	Vector2 V6 = V1 / V2;

	Vector2 V7(5.0f, 10.0f);
	float scalar = 2.5f;

	Vector2 V8 = V7 * scalar;
	Vector2 V9 = V7 / scalar;

	Vector2 V10(5.0f, 10.0f);
	Vector2 V11(2, 1);

	V11 += V10;
	V11 -= V10;

	V11 *= V10;
	V11 /= V10;

	float scalar2 = 1.5f;

	V11 *= scalar2;
	V11 /= scalar2;

	V11 = V10;

	V11 == V10;
	V11 != V10;

	V10 = V8;

	V11 == V10;
	V11 != V10;
	*/

	// INFO: Maths Testing
	/*
	Maths::DegToRad(180.0f);
	Maths::RadToDeg(1.0f);
	Maths::Lerp(1.0f, 2.0f, 0.5f);
	Maths::Clamp(5.0f, 1.0f, 3.1f);
	Maths::Max(5.0f, 10.0f);
	Maths::Min(5.0f, 10.0f);
	*/

	// INFO: Transform Testing
	/*
	Transform t(std::weak_ptr<GameObject>(), 5.0f, 10.0f);
	Transform t2{ std::weak_ptr<GameObject>(), Vector2(10.0f, 10.0f)};

	t.Translate(5.0f, 10.0f);
	t.Translate(Vector2(5.0f, 10.0f));

	t.TranslateX(5.0f);
	t.TranslateY(10.0f);

	t2.Up();
	t2.Right();

	t2.RotateZ(90.0f);

	t2.Up();
	t2.Right();

	t2.RotateZ(90.0f);

	t2.Up();
	t2.Right();

	t2.RotateZ(90.0f);

	t2.Up();
	t2.Right();
	*/

	// INFO: Color Command Line Testing
	/*
	//std::cout << "\033[1;31;4m"; // set color to underline red
	//std::cout << "\033[1;33;4m"; // set color to underline yellow
	std::cout << "Hello, world!" << std::endl;
	std::cout << "\033[0m"; // reset color to default
	*/

	// INFO: Debug Testing
	/*
	Vector2 Vect(5.0f, 10.0f);
	int Int = 5;
	float Float = 5.0f;
	Debug::Log(Vect);
	Debug::Log("Hello: " + ToString(Vect) + " World!");
	Debug::Log(std::to_string(Int));
	Debug::Log(Maths::FloatToString(Float));
	Debug::LogWarning(ToString(Vect) + " is bad.");
	Debug::LogError(Maths::FloatToString(Float, 5) + " is breaking the game.");
	*/

	(void)getchar();

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}