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

//�ø�ƽ(Sementic) : ���������� ��� ������� ����
//SV_POSITION : ��ȯ���� ���� �ø�ƽ
//System Value : �ý��������� �ѱ��(RS)

PixelInput VS(VertexInput input)
{												
    PixelInput output;
    output.position = input.pos;
    output.color = input.color;
    
	return output;
}

float4 PS(PixelInput input) : SV_TARGET // SV-> OM, Target->�����(RenderTagetView)
{
	return input.color;
}