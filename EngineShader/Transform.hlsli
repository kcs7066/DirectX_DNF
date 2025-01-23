// 상수버퍼를 사용하겠다.
// 상수버퍼는 용량제한이 있습니다.
cbuffer FTransform : register(b0)
{
	// transformupdate는 
	// 아래의 값들을 다 적용해서
	// WVP를 만들어내는 함수이다.
	// 변환용 벨류
	float4 Scale;
	float4 Rotation;
	float4 Qut;
	float4 Location;

	// 릴리에티브 로컬
	float4 RelativeScale;
	float4 RelativeRotation;
	float4 RelativeQut;
	float4 RelativeLocation;

	// 월드
	float4 WorldScale;
	float4 WorldRotation;
	float4 WorldQuat;
	float4 WorldLocation;

	float4x4 ScaleMat;
	float4x4 RotationMat;
	float4x4 LocationMat;
	float4x4 RevolveMat;
	float4x4 ParentMat;
	float4x4 LocalWorld;
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
	float4x4 WVP;
};


// 상수버퍼를 사용하겠다.
struct FTransformStruct
{
	// transformupdate는 
	// 아래의 값들을 다 적용해서
	// WVP를 만들어내는 함수이다.
	// 변환용 벨류
	float4 Scale;
	float4 Rotation;
	float4 Qut;
	float4 Location;

	// 릴리에티브 로컬
	float4 RelativeScale;
	float4 RelativeRotation;
	float4 RelativeQut;
	float4 RelativeLocation;

	// 월드
	float4 WorldScale;
	float4 WorldRotation;
	float4 WorldQuat;
	float4 WorldLocation;

	float4x4 ScaleMat;
	float4x4 RotationMat;
	float4x4 LocationMat;
	float4x4 RevolveMat;
	float4x4 ParentMat;
	float4x4 LocalWorld;
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
	float4x4 WVP;
};

// 겹쳐서 문제가 될수 있으므로 12번 슬롯으로 고정
StructuredBuffer<FTransformStruct> TransformBuffer : register(t0);