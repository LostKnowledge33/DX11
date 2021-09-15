#include "Framework.h"

CPixelShader::CPixelShader(wstring psPath, DWORD flags)
{
    //flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    D3DCompileFromFile(psPath.c_str(),
        NULL, NULL, "PS", "ps_5_0",
        flags, NULL, &blob, NULL);

    DEVICE->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &pixelShader);
}

CPixelShader::~CPixelShader()
{
    pixelShader->Release();
    blob->Release();
}

void CPixelShader::Set()
{
    DC->PSSetShader(pixelShader, NULL, 0);
}

