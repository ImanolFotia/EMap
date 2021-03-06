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
#ifndef EMAPDEFS_H_INCLUDED
#define EMAPDEFS_H_INCLUDED

typedef char BYTE;
typedef unsigned int UINT;

typedef enum meshType
{

    ENTITY      =              0x00000001,
    MESH        =              0x00000010,
    MODEL       =              0x00000011

};

typedef enum ENTITIES
{
    LIGHT        =              0x00000100,
    INFO_PLAYER  =              0x00000101,
    SOUND        =              0x00000110,
    TRIGGER      =              0x00000111,
    SMOKE        =              0x00001000

};

typedef enum eLIGHT
{

     POINT,
     DIRECTIONAL,
     SPOTLIGHT
};

struct VECTOR3D
{
    double x;
    double y;
    double z;
};

struct VECTOR4D
{
    int x;
    int y;
    int z;
    int w;
};

struct LIGHT
{
    VECTOR3D l_position;
    VECTOR3D l_direction;
    VECTOR3D l_color;
};

struct VECTOR2D
{
    int x;
    int y;
};

struct TEXTURE{

    std::string PATH;
    std::string TYPE;
};

#endif // EMAPDEFS_H_INCLUDED
