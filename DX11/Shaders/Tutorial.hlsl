						//시멘틱(Sementic) : 변수정보를 어떻게 사용할지 지정
float4 VS( float4 pos : POSITION ) : SV_POSITION //반환형에 대한 시멘틱
{												//System Value : 시스템쪽으로 넘긴다(RS)
	
	return pos;
}

float4 PS() : SV_TARGET // SV-> OM, Target->백버퍼(RenderTagetView)
{
	return float4(1.f, 1.f, 0.f, 1.f);
}