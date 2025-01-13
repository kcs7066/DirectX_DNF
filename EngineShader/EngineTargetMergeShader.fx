struct EngineVertex
{
	float4 POSITION : POSITION;
	float4 UV : TEXCOORD;
};

struct VertexShaderOutPut
{
	float4 SVPOSITION : SV_POSITION; // 뷰포트행렬이 곱해지는 포지션입니다.
	float4 UV : TEXCOORD; // 
};

// 버텍스쉐이더를 다 만들었다.
VertexShaderOutPut TargetMerge_VS(EngineVertex _Vertex)
{
	VertexShaderOutPut OutPut;
	OutPut.SVPOSITION = _Vertex.POSITION;
	OutPut.UV = _Vertex.UV;
	return OutPut;
}
Texture2D MergeTex : register(t0);
// 샘플러 1개가 필요합니다.
SamplerState ImageSampler : register(s0);

// 이미지를 샘플링해서 이미지를 보이게 만들고
float4 TargetMerge_PS(VertexShaderOutPut _Vertex) : SV_Target0
{
	float4 Color = MergeTex.Sample(ImageSampler, _Vertex.UV.xy);
	
	if (0.0f >= Color.a)
	{
		clip(-1);
	}
	
	Color.a = max(Color.a, 1.0f);
	
	return Color;
};
