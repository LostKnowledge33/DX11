#include "Framework.h"

CVertexShader::CVertexShader(LPCWSTR vsPath, DWORD flags)
{
    flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    ID3DBlob* vertexBlob; //쉐이더 정보를 들고있음
    D3DCompileFromFile(vsPath,
        NULL, NULL, "VS", "vs_5_0",
        flags, NULL, &vertexBlob, NULL);

    CDevice::Get()->GetDevice()->CreateVertexShader(vertexBlob->GetBufferPointer(), vertexBlob->GetBufferSize(), NULL, &vertexShader);

    //Set InputLayout
    D3D11_INPUT_ELEMENT_DESC layouts[] = {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
        {"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    UINT layoutSize = ARRAYSIZE(layouts);

    CDevice::Get()->GetDevice()->CreateInputLayout(layouts, layoutSize,
        vertexBlob->GetBufferPointer(), vertexBlob->GetBufferSize(), &inputLayout);

    vertexBlob->Release();

    UINT stride = sizeof(Vertex);
    UINT offset = 0;

    CDevice::Get()->GetDeviceContext()->IASetInputLayout(inputLayout);
    CDevice::Get()->GetDeviceContext()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

    CDevice::Get()->GetDeviceContext()->VSSetShader(vertexShader, NULL, 0);
}

CVertexShader::~CVertexShader()
{
}
