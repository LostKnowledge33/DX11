#include "Framework.h"

CConstBuffer::CConstBuffer(void* data, UINT dataSize)
    : data(data), dataSize(dataSize)
{
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = dataSize;
    bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    DEVICE->CreateBuffer(&bd, NULL, &buffer);
}

CConstBuffer::~CConstBuffer()
{
    buffer->Release();
}

void CConstBuffer::SetVS(UINT slot)
{
    DC->UpdateSubresource(buffer, 0, NULL, data, 0, 0);
    DC->VSSetConstantBuffers(slot, 1, &buffer);    
}

void CConstBuffer::SetPS(UINT slot)
{
    DC->UpdateSubresource(buffer, 0, NULL, data, 0, 0);
    DC->PSSetConstantBuffers(slot, 1, &buffer);
}

void CConstBuffer::Update()
{

}
