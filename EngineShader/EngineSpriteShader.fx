struct EngineVertex
{
    float4 POSITION : POSITION;
    float4 UV : TEXCOORD;
    float4 COLOR : COLOR;
};


struct VertexShaderOutPut
{
    float4 SVPOSITION : SV_POSITION;     float4 UV : TEXCOORD;     float4 COLOR : COLOR;
};

cbuffer FTransform : register(b0)
{
				    float4 Scale;
    float4 Rotation;
    float4 Qut;
    float4 Location;

	    float4 RelativeScale;
    float4 RelativeRotation;
    float4 RelativeQut;
    float4 RelativeLocation;

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

cbuffer FSpriteData : register(b1)
{
    float4 CuttingPos;
    float4 CuttingSize;
    float4 Pivot; };

VertexShaderOutPut VertexToWorld(EngineVertex _Vertex)
{
				
		
    VertexShaderOutPut OutPut;
	
	
			
			
	    _Vertex.POSITION.x += (1.0f - Pivot.x) - 0.5f;
    _Vertex.POSITION.y += (1.0f - Pivot.y) - 0.5f;
	
    OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
	
    OutPut.UV.x = (_Vertex.UV.x * CuttingSize.x) + CuttingPos.x;
    OutPut.UV.y = (_Vertex.UV.y * CuttingSize.y) + CuttingPos.y;
	
	
	
    OutPut.COLOR = _Vertex.COLOR;
    return OutPut;
}

cbuffer MatColor : register(b1)
{
    float4 Albedo;
};


struct OutTargetColor
{
    float4 Target0 : SV_Target0;     float4 Target1 : SV_Target1;     float4 Target2 : SV_Target2;     float4 Target3 : SV_Target3;     float4 Target4 : SV_Target4;     float4 Target5 : SV_Target5;     float4 Target6 : SV_Target6;     float4 Target7 : SV_Target7; };


Texture2D ImageTexture : register(t0);
SamplerState ImageSampler : register(s0);

float4 PixelToWorld(VertexShaderOutPut _Vertex) : SV_Target0
{
	
	    float4 Color = ImageTexture.Sample(ImageSampler, _Vertex.UV.xy);
    return Color;
	
	};
