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


EMap::EMap(std::string MapName)
{
    const aiScene* eMap = aiImportFile(MapName.c_str(),
                                       aiProcess_CalcTangentSpace       |
                                       aiProcess_Triangulate            |
                                       aiProcess_SortByPType            |
                                       aiProcess_FindInvalidData        );

    if(!eMap)
    {
        std::cout << "An error has occurred: " << aiGetErrorString() << std::endl;
        return;
    }

    directory = MapName.substr(0, MapName.find_last_of('/'));

    processNode(eMap->mRootNode, eMap);

    aiReleaseImport( eMap);
}

Mesh EMap::ParseMesh(aiMesh* mesh, const aiScene* eMap)
{
    Mesh tmpMesh;

    std::cout << std::endl << "Mesh" << std::endl << "====================================" << std::endl;

    std::cout << "Number of Vertices: " << mesh->mNumVertices << std::endl;

    for(int nVert = 0 ; nVert < mesh->mNumVertices; nVert++)
    {
        aiVector3D pos = mesh->mVertices[nVert];
        VECTOR3D tmpvec3;
        tmpvec3.x = pos.x;
        tmpvec3.y = pos.y;
        tmpvec3.z = pos.z;
        tmpMesh.vPosition.push_back(tmpvec3);


        if(mesh->mTextureCoords[0])
        {

            VECTOR2D tmpvec2;
            tmpvec2.x = mesh->mTextureCoords[0][nVert].x;
            tmpvec2.y = mesh->mTextureCoords[0][nVert].y;
            tmpMesh.TexCoords.push_back(tmpvec2);

        }

        if(mesh->HasNormals())
        {

            aiVector3D nor = mesh->mNormals[nVert];
            VECTOR3D tmpvec3;
            tmpvec3.x = nor.x;
            tmpvec3.y = nor.y;
            tmpvec3.z = nor.z;
            tmpMesh.vNormals.push_back(tmpvec3);

        }

        if(mesh->HasTangentsAndBitangents())
        {

            aiVector3D tan = mesh->mTangents[nVert];
            aiVector3D btan = mesh->mBitangents[nVert];
            VECTOR3D tmpvec3;
            tmpvec3.x = tan.x;
            tmpvec3.y = tan.y;
            tmpvec3.z = tan.z;
            tmpMesh.vTangents.push_back(tmpvec3);
            tmpvec3.x = btan.x;
            tmpvec3.y = btan.y;
            tmpvec3.z = btan.z;
            tmpMesh.vBitangents.push_back(tmpvec3);

        }
    }
    for(UINT i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        // Retrieve all indices of the face and store them in the indices vector
        for(UINT j = 0; j < face.mNumIndices; j++)
            tmpMesh.Indices.push_back(face.mIndices[j]);
    }
    if(mesh->mMaterialIndex >= 0)
    {
        aiMaterial* material = eMap->mMaterials[mesh->mMaterialIndex];
        std::vector<TEXTURE> diffuseMaps = this->loadMaterialTextures(material,
                                           aiTextureType_DIFFUSE, "texture_diffuse");
        tmpMesh.Textures.insert(tmpMesh.Textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        std::vector<TEXTURE> specularMaps = this->loadMaterialTextures(material,
                                            aiTextureType_SPECULAR, "texture_specular");
        tmpMesh.Textures.insert(tmpMesh.Textures.end(), specularMaps.begin(), specularMaps.end());
    }



    return tmpMesh;
}

void EMap::processNode(aiNode* node, const aiScene* scene)
{

    for(UINT j = 0; j < node->mNumMeshes; j++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[j]];
        this->Meshes.push_back(this->ParseMesh(mesh, scene));
    }

    for(UINT i = 0; i < node->mNumChildren; i++)
    {
        this->processNode(node->mChildren[i], scene);
    }
}

std::vector<TEXTURE> EMap::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
    std::vector<TEXTURE> textures;
    for(UINT i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        TEXTURE texture;
        texture.TYPE = typeName;
        std::cout << "Texture Type: " << texture.TYPE << std::endl;
        texture.PATH = str.C_Str();
        std::cout << "Texture Name: " << texture.PATH << std::endl;
        textures.push_back(texture);
    }
    return textures;
}

