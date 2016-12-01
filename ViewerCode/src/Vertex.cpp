#include "Vertex.h"

Vertex::Vertex()
{
    //ctor
}

Vertex::Vertex(int X,int Z){
    x=X;
    y=0;
    z=Z;
}

Vertex::Vertex(int X,int Y,int Z){
    x=X;
    y=Y;
    z=Z;
}

void Vertex::SetVertex(int X,int Y,int Z){
    x=X;
    y=Y;
    z=Z;
}

void Vertex::printToFile(fstream &file){
    file<<"v "<<x<<" "<<y<<" "<<z<<endl;
}

void Vertex::printTextureCordsToFile(fstream &file){
    file<<"vt "<<x<<" "<<y<<" "<<z<<endl;
}

Vertex Vertex::operator+(const Vertex& V1){
    Vertex temp;
    temp.x= V1.x + x;
    temp.y= V1.y + y;
    temp.z= V1.z + z;
    return temp;
}

Vertex Vertex::operator-(const Vertex& V1){
    Vertex temp;
    temp.x= x - V1.x;
    temp.y= y - V1.y;
    temp.z= z - V1.z;
    return temp;
}

