#pragma once
#include "MnGameObject.h"

namespace Mn
{
	using namespace Mn::math;
	class Cell : public GameObject
	{
	private:
		Vector4 _pos;
		Vector4 _color;
		Vector4 _radius;
		float	_respon;
		float	_scale;
	public:
		Cell();
		~Cell();
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	public:
		Vector4 Pos() { return _pos; }
		void Pos(Vector4 pos) { _pos = pos; }
		float Scale() { return _scale; }
		void Radius(Vector4 radius) { _radius = radius; }
	};
}

