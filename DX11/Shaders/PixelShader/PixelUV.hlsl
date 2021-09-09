
cbuffer ColorBuffer : register(b0)
{
    float4 color;
}

struct PixelInput
{
    float4 position : SV_POSITION;
    float2 uv : UV;
};

Texture2D map : register(t0);
SamplerState samp : register(s0);


float4 PS(PixelInput input) : SV_TARGET
{
    return map.Sample(samp, input.uv) * color;
    //return color;
    //return input.color;
}