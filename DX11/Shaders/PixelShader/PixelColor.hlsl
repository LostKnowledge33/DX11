
cbuffer ColorBuffer : register(b0)
{
    float4 color;
}

struct PixelInput
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

float4 PS(PixelInput input) : SV_TARGET
{
    return color;
    //return input.color;
}