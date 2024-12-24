struct EngineVertex
{
	float4 POSITION : POSITION;
	float4 UV : TEXCOORD;
	float4 COLOR : COLOR;
};

// 버텍스 쉐이더는 무조건 리턴값이 있어야 합니다.
// 인풋어셈블러2로 넘길 값을 리턴해줘야하는데.
// 이때도 규칙이 있습니다.

struct VertexShaderOutPut
{
	float4 SVPOSITION : SV_POSITION; // 뷰포트행렬이 곱해지는 포지션입니다.
	float4 UV : TEXCOORD; // 
	float4 COLOR : COLOR;
};

// 상수버퍼를 사용하겠다.
cbuffer FTransform : register(b0)
{
	float4 Scale;
	float4 Rotation;
	float4 Location;

	float4x4 ScaleMat;
	float4x4 RotationMat;
	float4x4 LocationMat;
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
	float4x4 WVP;
};

// 상수버퍼는 아무것도 세팅해주지 않으면 기본값이 0으로 채워집니다.
cbuffer FSpriteData : register(b1)
{
	float4 CuttingPos;
	float4 CuttingSize;
};

// 버텍스쉐이더를 다 만들었다.
VertexShaderOutPut VertexToWorld(EngineVertex _Vertex)
{
	// CPU에서 계산한 값을 쉐이더에게 넘기는 방법을 알아야 하는데
	// 상수버퍼라고 부릅니다.
	// 그중에서 가장 기본적인 것은 상수버퍼를 
	
	// float4x4 WVP;
	
	VertexShaderOutPut OutPut;
	// _Vertex 0.5, 0.5
	OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
	
	// 00 10 => 0.3 0.3  0.7 0.3
	// 01 11 => 0.3 0.7  0.7 0.7
	
	// CuttingPos 0.3 0.3
	// CuttingSize 0.4 0.4 
	
	OutPut.UV.x = (_Vertex.UV.x * CuttingSize.x) + CuttingPos.x;
	OutPut.UV.y = (_Vertex.UV.y * CuttingSize.y) + CuttingPos.y;
	
	
	
	OutPut.COLOR = _Vertex.COLOR;
	return OutPut;
}

// 텍스처 1장과 
Texture2D ImageTexture : register(t0);
// 샘플러 1개가 필요합니다.
SamplerState ImageSampler : register(s0);

// 이미지를 샘플링해서 이미지를 보이게 만들고
float4 PixelToWorld(VertexShaderOutPut _Vertex) : SV_Target0
{
	
	// ImageTexture.Load({0,0));
	float4 Color = ImageTexture.Sample(ImageSampler, _Vertex.UV.xy);
	return Color;
}