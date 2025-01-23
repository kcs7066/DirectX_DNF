#include "Light.hlsli"
#include "Transform.hlsli"

struct EngineVertex
{
	float4 POSITION : POSITION;
	float4 TEXCOORD : TEXCOORD; // UV값이라고 불리는 존재로 텍스처가 매핑되는 비율을 지정해줍니다.
	float4 COLOR : COLOR;
	float4 NORMAL : NORMAL; // 면의 법선 백터가 필요하다.
	float4 BINORMAL : BINORMAL; // 범프 매핑을 위한 데이터가 탄젠트 공간을 만들기 위한것.
	float4 TANGENT : TANGENT; // 범프 매핑을 위한 데이터가 탄젠트 공간을 만들기 위한것.
};

// 버텍스 쉐이더는 무조건 리턴값이 있어야 합니다.
// 인풋어셈블러2로 넘길 값을 리턴해줘야하는데.
// 이때도 규칙이 있습니다.

struct VertexShaderOutPut
{
	// 랜더링 파이프라인상 ViewPort 행렬이 곱해져서
	float4 SVPOSITION : SV_POSITION; 
	float4 TEXCOORD : TEXCOORD; 
	float4 COLOR : COLOR;
	
	float4 VIEWPOS : POSITION;
	float4 NORMAL : NORMAL; 
	float4 BINORMAL : BINORMAL; 
	float4 TANGENT : TANGENT; 
};




VertexShaderOutPut MeshLight_VS(EngineVertex _Vertex /*, int _DataIndex*/)
{
	VertexShaderOutPut OutPut;
	
	// 모니터공간 간 포지션이 된다.
	OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
	OutPut.TEXCOORD = _Vertex.TEXCOORD;
	OutPut.COLOR = _Vertex.COLOR;
	// 빛은 일반적으로 뷰공간에서 계산합니다.
	// 뷰공간으로 노말을 보냈어
	
	// 뷰공간으로 보낸 포지션이 됩니다.
	OutPut.VIEWPOS = mul(_Vertex.POSITION, World * View);
	
	// 실수로 w에 1이 들어가면 이동값을 적용받게 된다.
	// 그러므로 이동값이 적용되는것을 확실하게 차단하기 위해서 w를 신경써주는게 좋다.
	_Vertex.NORMAL.w = 0.0f;
	OutPut.NORMAL = mul(_Vertex.NORMAL, World * View);
	
	_Vertex.BINORMAL.w = 0.0f;
	OutPut.BINORMAL = mul(_Vertex.BINORMAL, World * View);
	
	_Vertex.TANGENT.w = 0.0f;
	OutPut.TANGENT = mul(_Vertex.TANGENT, World * View);
	
	// 빛 계산공식을 여기에서 해버리고 넘기면 고로쉐이딩이라고 한다.
	// OutPut.LIGHTCOLOR = 
	
	return OutPut;
}

cbuffer MeshColor : register(b0)
{
	float4 SettingColor;
};

float4 MeshLight_PS(VertexShaderOutPut _Vertex) : SV_Target0
{
	float4 ResultColor;
	ResultColor = SettingColor;
	
	// _Vertex.NORMAL = CalBumpNormal(_Vertex.NORMAL, NormalTexture);
	
	// 여기서 
	float4 DiffuseColor;
	float4 SpacularLight;
	float4 AmbiantLight = (0.1f, 0.1f, 0.1f, 0.1f);
	
	for (int i = 0; i < LightCount; ++i)
	{
		DiffuseColor += CalDiffusLight(_Vertex.NORMAL, LightArr[i]);
		SpacularLight += CalSpacularLight(_Vertex.VIEWPOS, _Vertex.NORMAL, LightArr[i]);
		//AmbiantLight += LightArr[0].AmbientLight;
	}
	
	ResultColor.xyz *= (DiffuseColor.xyz + SpacularLight.xyz + AmbiantLight.xyz);
	ResultColor.a = 1.0f;
	
	// ResultColor = _Vertex.NORMAL;
	// ResultColor = _Vertex.VIEWPOS;
	
	return ResultColor;
	// return float4(1.0f, 0.0f, 0.0f, 1.0f);
};

