#include "PreCompile.h"
#include "MyRenderer.h"

MyRenderer::MyRenderer()
{
	CreateRenderUnit();
	SetMesh("Rect");
	SetMaterial("MyMaterial");

	MyColor.Albedo = float4(1.0f, 1.0f, 1.0f, 1.0f);

	GetRenderUnit().ConstantBufferLinkData("FMyColor", MyColor);
}

MyRenderer::~MyRenderer()
{
}

