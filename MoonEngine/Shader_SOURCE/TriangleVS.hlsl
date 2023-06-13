struct VSIn
{
	float3 Pos : POSITION;
	float4 Color : COLOR;
};

struct VSOut
{
	float4 Pos : SV_Position;
	float4 Color : COLOR;
};

cbuffer Transform : register(b0)
{
	float4 Pos;
}

cbuffer Color : register(b1)
{
    float4 Color;
}

cbuffer Radius : register(b2)
{
    float4 radius;
}


VSOut main(VSIn In)
{
	VSOut Out = (VSOut)0.0f;

	Out.Pos = float4(In.Pos, 1.0f);
    if (any(Out.Pos != Pos))
    {
		Out.Pos.x *= radius.x;
		Out.Pos.y *= radius.y;
    }
	Out.Pos.xy+= Pos.xy;
    Out.Color.rgba = Color.rgba;
	return Out;
}