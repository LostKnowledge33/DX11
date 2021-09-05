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

//시멘틱(Sementic) : 변수정보를 어떻게 사용할지 지정
//SV_POSITION : 반환형에 대한 시멘틱
//System Value : 시스템쪽으로 넘긴다(RS)

PixelInput VS(VertexInput input)
{												
    PixelInput output;
    output.position = input.pos;
    output.color = input.color;
    
	return output;
}

float4 PS(PixelInput input) : SV_TARGET // SV-> OM, Target->백버퍼(RenderTagetView)
{
	return input.color;
}