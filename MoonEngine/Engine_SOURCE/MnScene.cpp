#include "MnScene.h"
#include "MnCircle.h"
#include "MnCell.h"

namespace Mn
{
	Scene::Scene()
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		_GameObjects.push_back(new Circle());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		_GameObjects.push_back(new Cell());
		for (auto gameObj : _GameObjects)
		{
			gameObj->Initialize();
		}
	}
	void Scene::Update()
	{
		_playerPos = dynamic_cast<Circle*>(_GameObjects[0])->Pos();
		for (auto food : _GameObjects)
		{
			if (dynamic_cast<Cell*>(food))
			{
				_foodPos = dynamic_cast<Cell*>(food)->Pos();
				float fs = dynamic_cast<Cell*>(food)->Scale();
				float ps = dynamic_cast<Circle*>(_GameObjects[0])->Scale();
				float rx = _foodPos.x - _playerPos.x;
				float ry = _foodPos.y - _playerPos.y;
				float a= sqrtf((rx * rx) + (ry * ry));
				if (a <= (0.05*fs)+(0.05*ps))
				{
					dynamic_cast<Cell*>(food)->Pos(Vector4(-10, -10, 0, 1.0f));
					dynamic_cast<Circle*>(_GameObjects[0])->GrowUp();
				}
			}
		}

		for (auto gameObj : _GameObjects)
		{
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
	}
	void Scene::Render()
	{
		for (auto gameObj : _GameObjects)
		{
			gameObj->Render();
		}
	}
}