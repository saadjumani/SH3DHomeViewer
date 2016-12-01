#ifndef VERTEX_H
#define VERTEX_H
#include <fstream>
using namespace std;
class Vertex
{
    friend class Wall;
    //a class to hold a 3D point, but can also be used as a direction vector
    public:
        Vertex();
        Vertex(int,int);
        Vertex(int,int,int);
        void printToFile(fstream &file);
        void printTextureCordsToFile(fstream &file);
        Vertex operator+(const Vertex& V1);
        Vertex operator-(const Vertex& V1);
        void SetVertex(int X,int Y,int Z);

    protected:

    private:
        int x;
        int y;
        int z;
};

#endif // VERTEX_H
