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

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "EMapDefs.h"

namespace EMap{

class CollParser
{
public:
    CollParser();
    virtual ~CollParser(){}

public:
    std::vector<Mesh> getMeshCollection();

public:
    int NumMeshes;
    int NumLights;

private:
    std::vector<Mesh> Meshes;

};

class Mesh{

public:
    Mesh();
    virtual ~Mesh(){}

public:

    std::vector<VECTOR3D> vPosition;
    std::vector<VECTOR2D> TexCoords;
    std::vector<VECTOR3D> vNormals;
    std::vector<VECTOR3D> vTangents;
    std::vector<VECTOR3D> vBitangents;
    std::vector<VECTOR3D> Indices;

    std::string Texture;




};
}
#endif // RAWPARSER_H_INCLUDED
