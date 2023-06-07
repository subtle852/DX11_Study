#pragma once
#include "YamYamEngine.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaMesh.h"
#include "yaShader.h"
#include "yaConstantBuffer.h"

using namespace ya::math;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[];
	extern ya::Mesh* mesh;
	extern ya::Shader* shader;
	extern ya::graphics::ConstantBuffer* constantBuffer;

	void Initialize();
	void Release();
}
