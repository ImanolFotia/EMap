#ifndef EMAPBIN_H_INCLUDED
#define EMAPBIN_H_INCLUDED

typedef struct m_header{
char* Identifier;
int Verision;
int revision;
};

typedef struct m_vertex
{

};

typedef struct m_texture
{
    int id;
    const char* path;
};

typedef struct m_mesh
{
    int mNumberOfVertices;
    int mNumberOfIndices;
    int mFirstIndex;
    int numberOfTextures;
    m_texture m_textures[5];
};


#endif // EMAPBIN_H_INCLUDED
