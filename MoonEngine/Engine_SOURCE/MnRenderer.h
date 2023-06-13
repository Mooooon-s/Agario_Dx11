#pragma once
#include "MoonEngine.h"
#include "MnGraphicDevice_Dx11.h"
#include "MnMesh.h"
#include "MnShader.h"
#include "MnConstantBuffer.h"

using namespace Mn::math;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertices[];
	extern Vertex CVertices[];
	extern ID3D11InputLayout* triangleLayout;
	extern Mn::Mesh* mesh;
	extern Mn::Mesh* Circlemesh;
	extern Mn::Shader* shader;
	extern Mn::Shader* Cicleshader;
	extern std::vector<Mn::graphics::ConstantBuffer*> constantBuffer;

	void Initialize();
	void Release();

	void Circle();

}