#include "MnCell.h"
#include "MnRenderer.h"
#include "MnGraphicDevice_Dx11.h"
#include "MnTime.h"
#define PI 3.1415926535
#include <random>
#include <ctime>
namespace Mn
{
	using namespace std;
	Cell::Cell()
		: _pos(Vector4::Zero)
		, _color(Vector4::Zero)
		, _radius(Vector4::Zero)
		, _scale(1)
		, _respon(0)
	{
	}
	Cell::~Cell()
	{
	}
	void Cell::Initialize()
	{
		random_device rd;
		mt19937 engine(rd());
		uniform_real_distribution<float> num(-1.0, 1.0);
		vector<float> v;
		for (int i = 0; i < 3;i++)
		{
			v.push_back(num(engine));
		}
		_pos = Vector4(v[0], v[1], 0, 0 );
		renderer::constantBuffer[0]->setData(&_pos);
		renderer::constantBuffer[0]->Bind(eShaderStage::VS);
		_color = Vector4(v[0], v[1], v[2], 0);
		renderer::constantBuffer[1]->setData(&_color);
		renderer::constantBuffer[1]->Bind(eShaderStage::VS);
		uniform_real_distribution<float> snum(0, 4);
		//_scale = num(engine);
		_radius = Vector4(_scale, _scale, 0.0, 1.0f);
		renderer::constantBuffer[2]->setData(&_radius);
		renderer::constantBuffer[2]->Bind(eShaderStage::VS);
	}
	void Cell::Update()
	{
		if (_pos == Vector4(-10, -10, 0, 1.0f))
		{
			_respon += Time::DeltaTime();
			if (_respon >= 3.0f)
			{
				random_device rd;
				mt19937 engine(rd());
				uniform_real_distribution<float> num(-1.0, 1.0);
				vector<float> v;
				for (int i = 0; i < 3; i++)
				{
					v.push_back(num(engine));
				}
				_pos = Vector4(v[0], v[1], 0, 0);
				_color = Vector4(v[0], v[1], 0, 0);
				_respon = 0;
			}
		}
	}
	void Cell::LateUpdate()
	{
	}
	void Cell::Render()
	{
		renderer::constantBuffer[0]->setData(&_pos);
		renderer::constantBuffer[0]->Bind(eShaderStage::VS);
		renderer::constantBuffer[1]->setData(&_color);
		renderer::constantBuffer[1]->Bind(eShaderStage::VS);
		renderer::constantBuffer[2]->setData(&_radius);
		renderer::constantBuffer[2]->Bind(eShaderStage::VS);

		renderer::Circlemesh->BindBuffer();
		renderer::shader->binds();
		graphics::GetDevice()->DrawIndexed(renderer::Circlemesh->GetIndexCount(), 0, 0);
	}
}