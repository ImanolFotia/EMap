/**========= Copyright Diego Imanol Fotia, All rights reserved. ============//

The MIT License (MIT)

Copyright (c) 2015 Diego Imanol Fotia

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

=============================================================================*/
#ifndef RAWPARSER_H_INCLUDED
#define RAWPARSER_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <EMapDefs.h>


class Entity{

public:

    Entity();
    ~Entity(){}

public:

    UINT eType;
    VECTOR3D ePosition;
    std::string eName;
};



class Mesh{

public:

    std::vector<VECTOR3D> vPosition;
    std::vector<VECTOR2D> TexCoords;
    std::vector<VECTOR3D> vNormals;
    std::vector<VECTOR3D> vTangents;
    std::vector<VECTOR3D> vBitangents;
    std::vector<UINT> Indices;

    std::vector<TEXTURE> Textures;

    std::string Name;
private:

};

class Light{

public:
    Light(){}
    ~Light(){}

public:
    VECTOR3D Position;
    VECTOR3D Direction;
    VECTOR3D Color;

};

class EMap
{
public:
    EMap(std::string MapName);
    virtual ~EMap(){}

    UINT eMapNumMeshes;

    std::vector<Mesh> Meshes;
    std::vector<Light> Lights;
private:
    void getLights(const aiScene* eMap);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh ParseMesh(aiMesh* mesh, const aiScene* eMap);
    std::vector<TEXTURE> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
    std::string directory;
};


#endif // RAWPARSER_H_INCLUDED
