						//�ø�ƽ(Sementic) : ���������� ��� ������� ����
float4 VS( float4 pos : POSITION ) : SV_POSITION //��ȯ���� ���� �ø�ƽ
{												//System Value : �ý��������� �ѱ��(RS)
	
	return pos;
}

float4 PS() : SV_TARGET // SV-> OM, Target->�����(RenderTagetView)
{
	return float4(1.f, 1.f, 0.f, 1.f);
}