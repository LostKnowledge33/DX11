
cbuffer World : register(b0)
{
    matrix world;
}

cbuffer View : register(b1)
{
    matrix view;
}

cbuffer Projection : register(b2)
{
    matrix projection;
}


struct VertexInput
{
    float4 pos : POSITION;
    float4 color : COLOR;
};

struct PixelInput
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

PixelInput VS(VertexInput input)
{
    PixelInput output;
    output.position = mul(input.pos, world);
    output.position = mul(output.position, view);
    output.position = mul(output.position, projection);
    
    output.color = input.color;
    
    return output;
}

