#include "Framework.h"

CVertexShader::CVertexShader(wstring vsPath, DWORD flags)
{
    flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    //쉐이더 정보를 들고있음
    D3DCompileFromFile(vsPath.c_str(),
        NULL, NULL, "VS", "vs_5_0",
        flags, NULL, &blob, NULL);

    DEVICE->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), NULL, &vertexShader);

    //Set InputLayout
    D3D11_INPUT_ELEMENT_DESC layouts[] = {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"UV", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    UINT layoutSize = ARRAYSIZE(layouts);

    DEVICE->CreateInputLayout(layouts, layoutSize,
        blob->GetBufferPointer(), blob->GetBufferSize(), &inputLayout);
}

CVertexShader::~CVertexShader()
{
    vertexShader->Release();
    blob->Release();
}

void CVertexShader::Set()
{
    DC->IASetInputLayout(inputLayout);
    DC->VSSetShader(vertexShader, NULL, 0);
}
