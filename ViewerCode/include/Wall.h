#ifndef WALL_H
#define WALL_H
#include "Vertex.h"
#include <fstream>
#include <vector>
using namespace std;
class Wall
{
    public:
        Wall();
        ~Wall();
        Wall(Vertex& v1, Vertex& v2, int depth, int height);
        void setWall (Vertex& v1, Vertex& v2, int depth, int height);
        void printVertices(fstream &file);
        void printFaces(fstream &file,int &VertexCount);
        void printTriFaces(fstream &file,int &VertexCount);

    protected:

    private:
        vector <Vertex> points;
        Vertex start;
        Vertex End;

        int depth; //Z Axis
        int height; //Y Axis
        int length; //X Axis

};

#endif // WALL_H
