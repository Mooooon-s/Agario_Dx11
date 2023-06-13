#pragma once
#include "MnEntity.h"
#include "MnGameObject.h"
#include "MnCircle.h"

namespace Mn
{
	class Scene : public Entity
	{
	private:
		std::vector<GameObject*> _GameObjects;
		Vector4 _playerPos;
		Vector4 _foodPos;
	public:
		Scene();
		virtual ~Scene();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	};
}

