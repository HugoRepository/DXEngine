#include "Engine.h"

Engine::Engine(HINSTANCE hinstance) : DXApp(hinstance)
{

}

Engine::~Engine()
{
	Memory::SafeDelete(mesh);

	vertexShader->Release();
	Memory::SafeDelete(vertexShader);

	pixelShader->Release();
	Memory::SafeDelete(pixelShader);
}

int Engine::Run()
{
	return window->Run(this);
}

bool Engine::Init()
{
	if (DXApp::Init() == false)
		return false;

	if (InitializeScene() == false)
		return false;

	return true;
}

void Engine::Update()
{

}

void Engine::Render()
{
	float color[] = { 0.0f, 0.5f, 0.5f, 1.0f };

	// ���� Ÿ���� ������ �������� ĥ�ϱ�.
	deviceContext->ClearRenderTargetView(renderTargetView, color);

	// ���̴� ���ε�.
	vertexShader->BindShader(deviceContext);
	pixelShader->BindShader(deviceContext);

	// �޽� �׸���.
	mesh->RenderBuffers(deviceContext);

	// ����� <-> ����Ʈ ���� ��ȯ.
	swapChain->Present(1, 0);
}

bool Engine::InitializeScene()
{
	vertexShader = new VertexShader(TEXT("Shaders//VS.fx"));
	if (vertexShader->CompileShader(device) == false)
		return false;

	if (vertexShader->CreateShader(device) == false)
		return false;

	pixelShader = new PixelShader(TEXT("Shaders//PS.fx"));
	if (pixelShader->CompileShader(device) == false)
		return false;

	if (pixelShader->CreateShader(device) == false)
		return false;

	mesh = new Mesh();
	if (mesh->InitializeBuffers(device, vertexShader->GetShaderBuffer()) == false)
		return false;

	return true;
}