#include "Framework.h"

CPixelShader::CPixelShader(LPCWSTR psPath, DWORD flags)
{
    flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    ID3DBlob* pixelBlob;
    D3DCompileFromFile(psPath,
        NULL, NULL, "PS", "ps_5_0",
        flags, NULL, &pixelBlob, NULL);

    CDevice::Get()->GetDevice()->CreatePixelShader(pixelBlob->GetBufferPointer(), pixelBlob->GetBufferSize(), NULL, &pixelShader);
    pixelBlob->Release();

    CDevice::Get()->GetDeviceContext()->PSSetShader(pixelShader, NULL, 0);
}

CPixelShader::~CPixelShader()
{

}
