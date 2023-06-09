#pragma once
#include "MoonEngine.h"


namespace Mn {
	class Time
	{
	private:
		static double			_DeltaTime;
		static double			_Second;
		static LARGE_INTEGER	_CpuFrequency;
		static LARGE_INTEGER	_PrevFrequency;
		static LARGE_INTEGER	_CurFrequency;
	public:
		static void Initialize();
		static void Update();
		static void Render();

		__forceinline static double DeltaTime() { return _DeltaTime; }
	};

}
