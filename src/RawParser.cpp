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
#include <RawParser.h>

EMap::EMap(const char* MapName)
{
    const aiScene* eMap = aiImportFile(MapName,
                                       aiProcess_CalcTangentSpace       |
                                       aiProcess_Triangulate            |
                                       aiProcess_SortByPType);

    if(!scene)
    {
        std::cout << "An error has occurred, aborting." << std::endl;
        return;
    }

    directory = MapName.substr(0, MapName.find_last_of('/'));

    processNode(eMap->mRootNode, eMap);
}

void EMap::ParseMesh(aiMesh* mesh, const aiScene eMap)
{
    if(eMap.HasMeshes())
    {
        eMapNumMeshes = eMap.mNumMeshes;
        Meshes.reserve(eMapNumMeshes);

        Mesh* tmpMesh = new Mesh();

        tmpMesh->mNumVertices = mesh->mNumVertices;

        for(int nVert = 0 ; nVert < mesh->mNumVertices; i++)
        {
            aiVector3D pos = mesh.mVertices[nVert];
            VECTOR3D tmpvec3;
            tmpvec3.x = pos.x;
            tmpvec3.y = pos.y;
            tmpvec3.z = pos.z;
            tmpMesh->vPosition.push_back(tmpvec3);
        }

        if(mesh->HasTextureCoords())
        {
            for(int nVert = 0 ; nVert < mesh->mNumVertices; i++)
            {
                aiVector2D txc = mesh.mTextureCoords[nVert];
                VECTOR2D tmpvec2;
                tmpvec2.x = txc.x;
                tmpvec2.y = txc.y;
                tmpMesh->TexCoords.push_back(tmpvec2);
            }
        }

        if(mesh->HasNormals())
        {
            for(int nVert = 0 ; nVert < mesh->mNumVertices; i++)
            {
                aiVector2D nor = mesh.mNormals[nVert];
                VECTOR3D tmpvec3;
                tmpvec3.x = nor.x;
                tmpvec3.y = nor.y;
                tmpvec3.z = nor.z;
                tmpMesh->vNormals.push_back(tmpvec3);
            }
        }

        if(mesh->HasTangentsAndBitangents())
        {
            for(int nVert = 0 ; nVert < mesh->mNumVertices; i++)
            {
                aiVector2D tan = mesh.mTangents[nVert];
                aiVector2D btan = mesh.mBitangents[nVert];
                VECTOR3D tmpvec3;
                tmpvec3.x = tan.x;
                tmpvec3.y = tan.y;
                tmpvec3.z = tan.z;
                tmpMesh->vTangents.push_back(tmpvec3);
                tmpvec3.x = btan.x;
                tmpvec3.y = btan.y;
                tmpvec3.z = btan.z;
                tmpMesh->vBitangents.push_back(tmpvec3);
            }
        }
        eMap

        delete tmpMesh;

        if(eMap->HasTextures())


            const aiMaterial* mmat = eMap->mMaterials[0];

        mmat->GetTexture()


    }
}

void EMap::processNode(aiNode* node, const aiScene* scene)
{
    // Process all the node's meshes (if any)
    for(GLuint i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        this->Meshes.push_back(this->processMesh(mesh, scene));
    }
    // Then do the same for each of its children
    for(GLuint i = 0; i < node->mNumChildren; i++)
    {
        this->processNode(node->mChildren[i], scene);
    }
}
