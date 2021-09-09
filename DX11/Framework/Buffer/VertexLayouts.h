#pragma once

struct Vertex {
    Float3 position;
    Float2 uv;

    Vertex(float x, float y, float u, float v)
    {
        position = Float3(x, y, 0);
        uv = Float2(u, v);
    }
};

struct VertexColor { //정점 : 3차원 공간에서의 한점
    Float3 position;
    Float4 color;

    VertexColor(float x, float y, float r, float g, float b)
    {
        position = Float3(x, y, 0);
        color = Float4(r, g, b, 1);
    }
};

