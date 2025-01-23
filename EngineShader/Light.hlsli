// 빛을 계산하기 위한 상수버퍼용 구조체
struct FLightData
{
	float4 LightPos; // 빛의 위치
	float4 LightDir; // 빛의 Forward
	float4 LightRevDir; // 빛의 반대방향이 < L!!!!! <= 
	float4 LightColor;
	float4 AmbientLight;
	float4 ViewLightPos;
	float4 ViewLightDir;
	float4 ViewLightRevDir;
	float4 CameraPosition;
};

cbuffer FLightDatas : register(b11)
{
	int LightCount;
	FLightData LightArr[256];
};

// 헤더에서는 전역함수도 만들수 있다.
// 참고로 레퍼런스나 포인터같은 개념은 Hlsl문법에서는 존재하지 않는다.

// N내적 L

float4 CalSpacularLight(float4 _ViewPos, float4 _ViewNormal, FLightData _Data)
{
	float ResultLight = 0.0f;

	float3 N = normalize(_ViewNormal.xyz);
	float3 L = normalize(_Data.ViewLightRevDir.xyz);
	
	// 반사 벡터를 구할수가 있다.
	float3 Reflection = normalize(2.0f * N.xyz * dot(L.xyz, N.xyz) - L.xyz);
	
	// 고정
	float3 Eye = normalize(_Data.CameraPosition.xyz - _ViewPos.xyz);
	
	// 0~1사이의 값이 나올수 밖에 없다.
	ResultLight = max(0.0f, dot(Reflection.xyz, Eye.xyz));
	
	// 내가 바라보는 방향백터의 영방향 반사벡터를 구합니다.
	
	ResultLight = pow(ResultLight, 60.0f);
	
	// float4 Reflection
	return ResultLight;
}

float4 CalDiffusLight(float4 _ViewNormal, FLightData _Data)
{
	float4 N = normalize(_ViewNormal);
	float4 L = normalize(_Data.ViewLightRevDir);
	// _Data.LightRevDir 뷰공간에 존재하는 녀석이어야 공식이 성립한다.
	
	// Ratio비율에 가까운 값
	float ResultLight;
	
	// 스위즐링(swizzling) 문법 Hlsl에서만 사용가능
	// .xz
	ResultLight = dot(N, L);
	
	// 음수가 나올수가 있기 때문에.
	// 최소값을 0으로 고정    최소값  최대값
	ResultLight = max(0.0f, ResultLight);
	
	// 빛의 강도
	return ResultLight * 0.5f;

}

