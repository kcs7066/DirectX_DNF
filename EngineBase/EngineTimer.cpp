#include "PreCompile.h"
#include "EngineTimer.h"

UEngineTimer::UEngineTimer()
{
	QueryPerformanceFrequency(&Count);

	TimeCounter = static_cast<double>(Count.QuadPart);

	QueryPerformanceCounter(&PrevTime);
	QueryPerformanceCounter(&CurTime);

	int a = 0;
}

UEngineTimer::~UEngineTimer()
{
}

void UEngineTimer::TimeStart()
{
	QueryPerformanceCounter(&PrevTime);
}

float UEngineTimer::End()
{
	TimeCheck();
	return GetDeltaTime();
}

double UEngineTimer::DEnd()
{
	TimeCheck();
	return GetDoubleDeltaTime();
}

void UEngineTimer::TimeCheck()
{

	QueryPerformanceCounter(&CurTime);

	double Tick = static_cast<double>(CurTime.QuadPart - PrevTime.QuadPart);
	DeltaTime = Tick / TimeCounter * TimeScale;
	fDeltaTime = static_cast<float>(DeltaTime);
	PrevTime.QuadPart = CurTime.QuadPart;
}
