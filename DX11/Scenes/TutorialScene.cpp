#include "Framework.h"

CTutorialScene::CTutorialScene()
{
    CVertexShader* vs = new CVertexShader(L"Shaders/Tutorial.hlsl", NULL);
    CPixelShader* ps = new CPixelShader(L"Shaders/Tutorial.hlsl", NULL);

    int degree = 1;

    for (int i = 0; i < 360 / degree; i++) {
        float temp = degree * i;

        cout << (float)cosf(XMConvertToRadians(degree * i)) << endl;
        cout << (float)sinf(XMConvertToRadians(degree * i)) << endl;

        vertices.emplace_back(0, 0, 0, 0, 0);
        vertices.emplace_back(cosf(XMConvertToRadians(temp + degree)) * 0.5f, sinf(XMConvertToRadians(temp + degree)) * 0.5f, 1, 1, 0);
        vertices.emplace_back(cosf(XMConvertToRadians(temp)) * 0.5f, sinf(XMConvertToRadians(temp)) * 0.5f, 1, 1, 0);
    }

    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(Vertex) * vertices.size();
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = vertices.data();

    CDevice::Get()->GetDevice()->CreateBuffer(&bd, &initData, vs->GetVB());
}

CTutorialScene::~CTutorialScene()
{

}

void CTutorialScene::Update()
{

}

void CTutorialScene::Render()
{
    CDevice::Get()->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    CDevice::Get()->GetDeviceContext()->Draw(vertices.size(), 0);
}
