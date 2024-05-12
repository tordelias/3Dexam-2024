#include "Construct.h"

std::vector<Vertex> Construct::Cube(glm::vec3 Color)
{
    std::vector<Vertex> CubeArray;
    glm::vec3 sizeXYZ = glm::vec3(1.f, 1.f, 1.f);
    CubeArray.resize(36);

    // Front face vertices
    Vertex v0{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v1{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v2{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v3{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z ,  Color.x, Color.y, Color.z, 0.0f, 0.0f };

    // Right face vertices
    Vertex v4{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v5{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v6{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v7{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };

    // Back face vertices
    Vertex v8{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v9{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v10{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v11{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };

    // Left face vertices
    Vertex v12{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v13{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v14{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v15{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };

    // Top face vertices
    Vertex v16{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v17{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v18{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v19{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };

    // Bottom face vertices
    Vertex v20{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v21{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v22{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v23{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };

    // Assign vertices to CubeArray
    CubeArray[0] = v0;
    CubeArray[1] = v1;
    CubeArray[2] = v2;
    CubeArray[3] = v2;
    CubeArray[4] = v3;
    CubeArray[5] = v0;

    CubeArray[6] = v4;
    CubeArray[7] = v5;
    CubeArray[8] = v6;
    CubeArray[9] = v6;
    CubeArray[10] = v7;
    CubeArray[11] = v4;

    CubeArray[12] = v8;
    CubeArray[13] = v9;
    CubeArray[14] = v10;
    CubeArray[15] = v10;
    CubeArray[16] = v11;
    CubeArray[17] = v8;

    CubeArray[18] = v12;
    CubeArray[19] = v13;
    CubeArray[20] = v14;
    CubeArray[21] = v14;
    CubeArray[22] = v15;
    CubeArray[23] = v12;

    CubeArray[24] = v16;
    CubeArray[25] = v17;
    CubeArray[26] = v18;
    CubeArray[27] = v18;
    CubeArray[28] = v19;
    CubeArray[29] = v16;

    CubeArray[30] = v20;
    CubeArray[31] = v21;
    CubeArray[32] = v22;
    CubeArray[33] = v22;
    CubeArray[34] = v23;
    CubeArray[35] = v20;

    return CubeArray;
}

std::vector<Vertex> Construct::CubeNoTexture(glm::vec3 Color)
{
    std::vector<Vertex> CubeArray;
    glm::vec3 sizeXYZ = glm::vec3(1.f, 1.f, 1.f);
    CubeArray.resize(36);

    // Front face vertices
    Vertex v0{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v1{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v2{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v3{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z ,  Color.x, Color.y, Color.z};

    // Right face vertices
    Vertex v4{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v5{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v6{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v7{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z};

    // Back face vertices
    Vertex v8{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v9{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v10{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v11{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z};

    // Left face vertices
    Vertex v12{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v13{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v14{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v15{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z};

    // Top face vertices
    Vertex v16{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v17{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v18{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v19{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z};

    // Bottom face vertices
    Vertex v20{ -sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v21{ sizeXYZ.x, -sizeXYZ.y, -sizeXYZ.z, Color.x, Color.y, Color.z};
    Vertex v22{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z};
    Vertex v23{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z};

    // Assign vertices to CubeArray
    CubeArray[0] = v0;
    CubeArray[1] = v1;
    CubeArray[2] = v2;
    CubeArray[3] = v2;
    CubeArray[4] = v3;
    CubeArray[5] = v0;

    CubeArray[6] = v4;
    CubeArray[7] = v5;
    CubeArray[8] = v6;
    CubeArray[9] = v6;
    CubeArray[10] = v7;
    CubeArray[11] = v4;

    CubeArray[12] = v8;
    CubeArray[13] = v9;
    CubeArray[14] = v10;
    CubeArray[15] = v10;
    CubeArray[16] = v11;
    CubeArray[17] = v8;

    CubeArray[18] = v12;
    CubeArray[19] = v13;
    CubeArray[20] = v14;
    CubeArray[21] = v14;
    CubeArray[22] = v15;
    CubeArray[23] = v12;

    CubeArray[24] = v16;
    CubeArray[25] = v17;
    CubeArray[26] = v18;
    CubeArray[27] = v18;
    CubeArray[28] = v19;
    CubeArray[29] = v16;

    CubeArray[30] = v20;
    CubeArray[31] = v21;
    CubeArray[32] = v22;
    CubeArray[33] = v22;
    CubeArray[34] = v23;
    CubeArray[35] = v20;

    return CubeArray;
}

std::vector<Vertex> Construct::Table(glm::vec3 Color)
{
    std::vector<Vertex> TableArray;
    TableArray.resize(36);
    float size = 1;

    Vertex v0{ -size, -size, size , Color.x, Color.y, Color.z };
    Vertex v1{ size, -size, size, Color.x, Color.y, Color.z };
    Vertex v2{ size, size, size , Color.x, Color.y, Color.z };
    Vertex v3{ -size, size, size ,  Color.x, Color.y, Color.z };
    Vertex v4{ -size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v5{ size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v6{ size, size, -size ,  Color.x, Color.y, Color.z };
    Vertex v7{ -size, size, -size , Color.x, Color.y, Color.z };

    Vertex v8{(3 * -size),  size, (4 * size) , Color.x, Color.y, Color.z};
    Vertex v9{(3 * size),  size, (4 * size) , Color.x, Color.y, Color.z };
    Vertex v10{ (3 * -size) ,  size,(4 * -size), Color.x, Color.y, Color.z };
    Vertex v11{(3 * size), size,(4 * -size) , Color.x, Color.y, Color.z };

    TableArray = {
        // Front face
        v0, v1, v3,
        v3, v1, v2,

        // Back face
        v4, v5, v7,
        v7, v5, v6,

        // Right face
        v1, v5, v2,
        v2, v5, v6,

        // Left face
        v4, v0, v7,
        v7, v0, v3,

        // Top face
        v8, v9, v10,
        v10, v9, v11,


        // Bottom face
        v4, v5, v0,
        v0, v5, v1
    };

    return TableArray;
}

std::vector<Vertex> Construct::House(glm::vec3 Color)
{
    std::vector<Vertex> houseArray;
    houseArray.resize(48);
    float size = 1.f; 

    // House
    Vertex v0{ -size, -size, size , Color.x, Color.y, Color.z };
    Vertex v1{ size, -size, size, Color.x, Color.y, Color.z };
    Vertex v2{ size, size, size , Color.x, Color.y, Color.z };
    Vertex v3{ -size, size, size ,  Color.x, Color.y, Color.z };
    Vertex v4{ -size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v5{ size, -size, -size ,  Color.x, Color.y, Color.z };
    Vertex v6{ size, size, -size ,  Color.x, Color.y, Color.z };
    Vertex v7{ -size, size, -size , Color.x, Color.y, Color.z };

    // Roof
    Vertex v8{ 0.0f, size + size / 2,  size, Color.x, Color.y, Color.z };
    Vertex v9{ 0.0f, size + size / 2, -size, Color.x, Color.y, Color.z };

    houseArray =
    {
        // Front face
        v0, v1, v3,
        v3, v1, v2,

        // Back face
        v4, v5, v7,
        v7, v5, v6,

        // Right face
        v1, v5, v2,
        v2, v5, v6,

        // Left face
        v4, v0, v7,
        v7, v0, v3,

        // Bottom face
        v4, v5, v0, 
        v0, v5, v1, 

        // Roof faces
        // Front triangle
        v3, v2, v8,
        // Back triangle
        v6, v7, v9,

        // Left roof face
        v3, v7, v8,
        v7, v8, v9,

        // Right roof face
        v2, v6, v8,
        v6, v8, v9
    };

    return houseArray;
}

std::vector<Vertex> Construct::NotAPlane(glm::vec3 Color)
{
    std::vector<Vertex> PlaneArray;
    PlaneArray.resize(6);
    glm::vec3 sizeXYZ = glm::vec3(1.0f, 1.0f, 1.0f);

    //  = glm::vec3(sizeXYZ.x / 4, sizeXYZ.x / 2, 0);
    Vertex v2{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v3{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z ,  Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v6{ sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z ,  Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v7{ -sizeXYZ.x, sizeXYZ.y, -sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 0.0f };


    v6.y += 0.5;
    //v2.y += 0.5;
    //v7.y = newHeight2;
    PlaneArray[0] = v3;
    PlaneArray[1] = v2;
    PlaneArray[2] = v6;
    PlaneArray[3] = v6;
    PlaneArray[4] = v7;
    PlaneArray[5] = v3;

    return PlaneArray;

}

std::vector<Vertex> Construct::Triangle(glm::vec3 Color)
{
    std::vector<Vertex> TriangleArray;
    TriangleArray.resize(3); 
    glm::vec3 sizeXYZ = glm::vec3(1.0f, 1.0f, 1.0f);

    Vertex v0{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v1{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v2{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v3{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z ,  Color.x, Color.y, Color.z, 0.0f, 0.0f };

    TriangleArray[0] = v0;
    TriangleArray[1] = v1;
    TriangleArray[2] = v2;



    return TriangleArray;
}

std::vector<Vertex> Construct::Square(glm::vec3 Color)
{
    std::vector<Vertex> SquareArray;
    SquareArray.resize(6);
    glm::vec3 sizeXYZ = glm::vec3(1.0f, 1.0f, 1.0f);

    Vertex v0{ -sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 0.0f, 1.0f };
    Vertex v1{ sizeXYZ.x, -sizeXYZ.y, sizeXYZ.z, Color.x, Color.y, Color.z, 1.0f, 1.0f };
    Vertex v2{ sizeXYZ.x, sizeXYZ.y, sizeXYZ.z , Color.x, Color.y, Color.z, 1.0f, 0.0f };
    Vertex v3{ -sizeXYZ.x, sizeXYZ.y, sizeXYZ.z ,  Color.x, Color.y, Color.z, 0.0f, 0.0f };

    SquareArray[0] = v0;
    SquareArray[1] = v1;
    SquareArray[2] = v2;
    SquareArray[3] = v2;
    SquareArray[4] = v3;
    SquareArray[5] = v0;

    return SquareArray;
}

std::vector<Vertex> Construct::Cubicinterpolation(glm::vec3 Color)
{
    Math_class math; 
    std::vector<Vertex> LineArray;
    glm::vec3 sizeXYZ = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec4 points = { 0, 1, 2, 3 };
    glm::vec4 y_cords = { 0, 5, -4, 9 };
    float num_y; 
    glm::vec<4, double> X = math.CubicInterpolation(points, y_cords);
    Vertex v0; 
    for (float i = 0; i < 10; i += 0.05)
    {
        num_y = ((X.x * powf(i,3)) + (X.y * powf(i, 2)) + (X.z * i) + X.w);
        v0 = { i, num_y, 0, Color.x, Color.y, Color.z }; 

        std::cout << v0.x << ", " << v0.y << std::endl;
        LineArray.push_back(v0); 
    }
    std::cout << X.x << ", " << X.y << ", " << X.z << ", " << X.w << std::endl;
    return LineArray;
}

std::vector<Vertex> Construct::Quadraticinterpolation(glm::vec3 Color)
{
    Math_class math;
    std::vector<Vertex> LineArray;
    glm::vec3 sizeXYZ = glm::vec3(1.0f, 1.0f, 1.0f);

    glm::vec3 points = { 0, 1, 2};
    glm::vec3 y_cords = { 0, 5, -4};
    float num_y;
    glm::vec<3, double> X = math.QuadraticInterpolation(points, y_cords);
    Vertex v0;
    for (float i = 0; i < 10; i += 0.05)
    {
        num_y = ((X.x * powf(i, 3)) + (X.y * powf(i, 2)) + X.z);
        v0 = { i, 0, num_y, Color.x, Color.y, Color.z };

        std::cout << v0.x << ", " << v0.y << std::endl;
        LineArray.push_back(v0);
       
        if (num_y < y_cords.z) // endre </> etter om posetiv/negativ 
            return LineArray;
    }
    std::cout << X.x << ", " << X.y << ", " << X.z  << std::endl;

    return LineArray; 
}

std::vector<Vertex> Construct::CoolPlane(glm::vec3 Color)
{
    std::vector<Vertex> TerrainArray;
    glm::vec3 sizeXYZ = glm::vec3(10.0f, 1.0f, 10.0f); // Adjust the size of the terrain

    int divisionsX = 50;
    int divisionsZ = 50;

    float stepX = sizeXYZ.x / divisionsX;
    float stepZ = sizeXYZ.z / divisionsZ;

    // Generate vertices
    for (int i = 0; i < divisionsZ; ++i) {
        for (int j = 0; j < divisionsX; ++j) {
            Vertex v0, v1, v2, v3;

            v0.x = j * stepX - sizeXYZ.x / 2.0f;
            v0.z = i * stepZ - sizeXYZ.z / 2.0f;
            v0.y = sin(v0.x * 0.5f) * cos(v0.z * 0.5f);

            v1.x = (j + 1) * stepX - sizeXYZ.x / 2.0f;
            v1.z = i * stepZ - sizeXYZ.z / 2.0f;
            v1.y = sin(v1.x * 0.5f) * cos(v1.z * 0.5f);

            v2.x = (j + 1) * stepX - sizeXYZ.x / 2.0f;
            v2.z = (i + 1) * stepZ - sizeXYZ.z / 2.0f;
            v2.y = sin(v2.x * 0.5f) * cos(v2.z * 0.5f);

            v3.x = j * stepX - sizeXYZ.x / 2.0f;
            v3.z = (i + 1) * stepZ - sizeXYZ.z / 2.0f;
            v3.y = sin(v3.x * 0.5f) * cos(v3.z * 0.5f);

            // Set color
            v0.r = v1.r = v2.r = v3.r = Color.r;
            v0.g = v1.g = v2.g = v3.g = Color.g;
            v0.b = v1.b = v2.b = v3.b = Color.b;

            // Set texture coordinates
            v0.u = j / (float)divisionsX;
            v0.v = i / (float)divisionsZ;

            v1.u = (j + 1) / (float)divisionsX;
            v1.v = i / (float)divisionsZ;

            v2.u = (j + 1) / (float)divisionsX;
            v2.v = (i + 1) / (float)divisionsZ;

            v3.u = j / (float)divisionsX;
            v3.v = (i + 1) / (float)divisionsZ;

            TerrainArray.push_back(v0);
            TerrainArray.push_back(v1);
            TerrainArray.push_back(v2);

            TerrainArray.push_back(v0);
            TerrainArray.push_back(v2);
            TerrainArray.push_back(v3);
        }
    }

    return TerrainArray;
}
