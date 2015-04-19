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

template <typename ELEMENT>
typedef enum meshType
{

    ELEMENT ENTITY      =              0x00000001;
    ELEMENT MESH        =              0x00000010;
    ELEMENT MODEL       =              0x00000011;

};

template <typename ENTITY>
typedef enum ENTITIES
{
    ENTITY LIGHT        =              0x00000100;
    ENTITY INFO_PLAYER  =              0x00000101;
    ENTITY SOUND        =              0x00000110;
    ENTITY TRIGGER      =              0x00000111;
    ENTITY

};

template <typename T>
typedef struct VECTOR3D
{

    T x;
    T y;
    T z;
};

template <typename T>
typedef struct VECTOR2D
{
    T x;
    T y;
};


#endif // EMAPDEFS_H_INCLUDED
