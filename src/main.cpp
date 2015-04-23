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
#include <iostream>
#include <RawParser.h>
using namespace std;

int main(int argc, char* argv[])
{
    //std::string filename(argv[1]);
    EMap eMap("mapa counter.dae");

    cout << "Epsilon Map Compiler" << endl;

    for(int i = 0 ; i < eMap.Meshes.size() ; i++)
    {
        std::cout << "Mesh: " <<eMap.Meshes[i].Name<< std::endl;

        std::cout << "Number of Vertices: " << eMap.Meshes[i].vPosition.size() << std::endl<< std::endl;
        std::cout << "\tMesh textures: "<< std::endl;
        for(int j = 0 ; j < eMap.Meshes[i].Textures.size() ; j++)
        {
            std::cout << "\tTexture Type: " << eMap.Meshes[i].Textures[j].TYPE << std::endl;
            std::cout << "\tTexture Name: " << eMap.Meshes[i].Textures[j].PATH << std::endl << std::endl;
        }
        std::cout << "======================================= "<< std::endl;
    }
    cout << eMap.Lights.size() << endl;
    for(int i = 0 ; i < eMap.Lights.size() ; i++)
    {
        cout << "Light #" << i << endl;
        cout << "Light Position: " << "Vector3D: (" << eMap.Lights[i].Position.x << " " <<eMap.Lights[i].Position.y<< " " <<eMap.Lights[i].Position.z<<  " )" << endl;
        cout << "Light Direction: " << "Vector3D: (" << eMap.Lights[i].Direction.x << " " <<eMap.Lights[i].Direction.y<< " " <<eMap.Lights[i].Direction.z<<  " )" << endl;
        cout << "Light Color: " << endl << "(" << eMap.Lights[i].Color.x << " "  << eMap.Lights[i].Color.y<< " " <<eMap.Lights[i].Color.z <<  " )" << endl;

        std::cout << "======================================= "<< std::endl;
    }

    return 0;
}
