#include "MnCircle.h"
#include "MnRenderer.h"
#include "MnGraphicDevice_Dx11.h"
#include "MnInput.h"
#include "MnTime.h"

namespace Mn
{
	Circle::Circle()
		:_speed(3)
		,_pos(Vector4::Zero)
		,_radius(Vector4::Zero)
		, _scale(1)
	{
	}
	Circle::~Circle()
	{
	}
	void Circle::Initialize()
	{
		_pos = Vector4::Zero;
		_radius = Vector4(_scale,_scale,0.0f,1.0f);
	}
	void Circle::Update()
	{
		if (_pos.x >= 1 || _pos.x <= -1 || _pos.y >= 1 || _pos.y <= -1)
		{
			if (_pos.x + (0.5 * _scale) >= 1)
			{
				_pos.x -= 0.1*Time::DeltaTime();
			}
			else if (_pos.x - (0.5 * _scale) <= -1)
			{
				_pos.x += 0.1 * Time::DeltaTime();
			}
			else if (_pos.y + (0.5 * _scale) >= 1)
			{
				_pos.y -= 0.1 * Time::DeltaTime();
			}
			else if (_pos.y - (0.5 * _scale) <= -1)
			{
				_pos.y += 0.1 * Time::DeltaTime();
			}
		}
		else 
		{
			if (Input::GetKey(eKeyCode::W))
			{
				_pos += Vector4(0.0f, 0.1f, 0.0f, 1.0f) * _speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::A))
			{
				_pos += Vector4(-0.1f, 0.0f, 0.0f, 1.0f) * _speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::S))
			{
				_pos += Vector4(0.0f, -0.1f, 0.0f, 1.0f) * _speed * Time::DeltaTime();
			}
			if (Input::GetKey(eKeyCode::D))
			{
				_pos += Vector4(0.1f, 0.0f, 0.0f, 1.0f) * _speed * Time::DeltaTime();
			}

		}
	}
	void Circle::LateUpdate()
	{
	}
	void Circle::Render()
	{
		renderer::constantBuffer[0]->setData(&_pos);
		renderer::constantBuffer[0]->Bind(eShaderStage::VS);
		_color = Vector4(1.0f, 1.0f, 0.0f, 1.0f);
		renderer::constantBuffer[1]->setData(&_color);
		renderer::constantBuffer[1]->Bind(eShaderStage::VS);
		_radius = Vector4(_scale,_scale,0.0f,1.0f);
		renderer::constantBuffer[2]->setData(&_radius);
		renderer::constantBuffer[2]->Bind(eShaderStage::VS);

		renderer::Circlemesh->BindBuffer();
		renderer::shader->binds();
		graphics::GetDevice()->DrawIndexed(renderer::Circlemesh->GetIndexCount(), 0, 0);
	}
}