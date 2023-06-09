#pragma once
#include "MoonEngine.h"
#include "MnGameObject.h"
using namespace Mn::math;
namespace Mn
{
	class Circle : public GameObject
	{
	private:
		Vector4 _pos;
		Vector4 _color;
		Vector4 _radius;
		float	_speed;
		float	_scale;
	public:
		Circle();
		~Circle();
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	public:
		Vector4 Pos() { return _pos; }
		float Scale() { return _scale; }
		void Radius(Vector4 radius) { _radius = radius; }
		void GrowUp() { _scale += 0.1; }
	};
}

