#pragma once
#include "YamYamEngine.h"
#include "yaGraphicDevice_Dx11.h"
#include "yaMesh.h"
#include "yaShader.h"
#include "yaConstantBuffer.h"

using namespace ya::math;
using namespace ya::graphics;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
		Vector2 uv;
	};

	extern Vertex vertexes[];
	extern ya::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];

	void Initialize();
	void Release();
}
