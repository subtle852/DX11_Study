#include "yaRenderer.h"



namespace renderer
{
	Vertex vertexes[4] = {};



	// Input Layout (���� ����)
	ID3D11InputLayout* triangleLayout = nullptr;

	// Vertex Buffer
	ya::Mesh* mesh = nullptr;
	
	//ID3D11Buffer* triangleBuffer = nullptr;
	//ID3D11Buffer* triangleIdxBuffer = nullptr;

	ID3D11Buffer* triangleConstantBuffer = nullptr;


	ya::Shader* shader = nullptr;
	//// error blob
	//ID3DBlob* errorBlob = nullptr;

	//// Vertex Shader code -> Binary Code
	//ID3DBlob* triangleVSBlob = nullptr;

	//// Vertex Shader
	//ID3D11VertexShader* triangleVSShader = nullptr;

	//// Pixel Shader code -> Binary Code
	//ID3DBlob* trianglePSBlob = nullptr;

	// Vertex Shader
	ID3D11PixelShader* trianglePSShader = nullptr;

	void SetupState()
	{




	}

	void LoadBuffer()
	{
		// Vertex Buffer
		mesh = new ya::Mesh();
		mesh->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);

		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Constant Buffer
		D3D11_BUFFER_DESC triangleCSDesc = {};
		triangleCSDesc.ByteWidth = sizeof(Vector4);
		triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		triangleCSDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		ya::graphics::GetDevice()->CreateBuffer(&triangleConstantBuffer, &triangleCSDesc, nullptr);

		Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);
		ya::graphics::GetDevice()->SetConstantBuffer(triangleConstantBuffer, &pos, sizeof(Vector4));
		ya::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, triangleConstantBuffer);
		//
	}

	void LoadShader()
	{
		//ya::graphics::GetDevice()->CreateShader();
		
		shader = new ya::Shader();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
	}

	void Initialize()
	{
		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		SetupState();
		LoadBuffer();
		LoadShader();
	}

	void Release()
	{
		if (triangleLayout != nullptr)
			triangleLayout->Release();

		if (triangleConstantBuffer != nullptr)
			triangleConstantBuffer->Release();

		if (trianglePSShader != nullptr)
			trianglePSShader->Release();
	}
}



