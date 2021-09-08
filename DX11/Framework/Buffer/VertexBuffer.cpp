#include "Framework.h"

CVertexBuffer::CVertexBuffer(void* data, UINT stride, UINT count)
    : stride(stride), offset(0)
{
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = stride * count;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = data;

    DEVICE->CreateBuffer(&bd, &initData, &buffer);
}

CVertexBuffer::~CVertexBuffer()
{
    buffer->Release();
}

void CVertexBuffer::Set(D3D11_PRIMITIVE_TOPOLOGY type)
{
    DC->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
    DC->IASetPrimitiveTopology(type);
}
