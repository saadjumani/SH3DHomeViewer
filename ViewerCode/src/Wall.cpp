#include "Wall.h"
#include "Vertex.h"

Wall::Wall()
{
    //ctor
}

Wall::~Wall()
{
    //dtor
}

Wall::Wall(Vertex& WallStart, Vertex& WallEnd, int Depth, int Height){
    Vertex Temp;
    length = WallEnd.x-WallStart.x;
    depth=Depth;
    height=Height;

    Temp.SetVertex(WallStart.x,WallStart.y,WallStart.z);
    points.push_back(Temp);
    Temp.SetVertex(WallEnd.x,WallEnd.y,WallEnd.z );
    points.push_back(Temp);
    Temp.SetVertex(WallEnd.x,WallEnd.y+height,WallEnd.z );
    points.push_back(Temp);
    Temp.SetVertex(WallStart.x,WallStart.y+height,WallStart.z);
    points.push_back(Temp);

    Vertex vec1 = WallStart - WallEnd;
    Vertex vec2(0,height,0);

    int normX = (WallStart.y * WallEnd.z) - (WallEnd.y * WallStart.z);
    int normY = (WallStart.x * WallEnd.z) - (WallEnd.x * WallStart.z);
    int normZ = (WallStart.x * WallEnd.y) - (WallEnd.x * WallStart.y);

    if(WallStart.x == WallEnd.x){
        Temp.SetVertex(depth,0,0);
    }
    else if( WallStart.z == WallEnd.z){
        Temp.SetVertex(0,0,depth);
    }
    else{
        Temp.SetVertex(depth,0,depth);
    }

    for(int i=4;i<8;i++){
        points.push_back(points[i-4]+Temp);
    }
}

void Wall::printVertices(fstream &file){
    for(int i=0;i<points.size();i++){
        points[i].printToFile(file);
    }
    file<<"vt 0 0 50"<<endl<<"vt 50 0 0 "<<endl<<"vt 50 50 0 "<<endl<<"vt 0 50 0"<<endl;
    /*for(int i=0;i<4;i++){
        points[i].printTextureCordsToFile(file);
    }*/
}

void Wall::printFaces(fstream &file, int &VertexCount){
    int vtCount = VertexCount/2;
    int faces[24]= {1,2,3,4,1,5,8,4,3,4,8,7,2,3,7,6,1,2,6,5,5,6,7,8};
    for(int i=0;i<24;i++){
        faces[i]=faces[i]+VertexCount;
    }

    file<<"usemtl wallTexture"<<endl;
    file<<endl;
    for(int i=0;i<24;i++){
        if((i)%4==0){
            file<<"\nf ";
        }
        file<<faces[i]<<"/"<<(i%4)+1+vtCount<<" ";
    }

    for(int i=23;i>-1;i--){
        if((i+1)%4==0){
            file<<"\nf ";
        }
        file<<faces[i]<<"/"<<(i%4)+1+vtCount<<" ";
    }

    file<<endl;
    VertexCount = VertexCount+8;
}


void Wall::printTriFaces(fstream &file, int &VertexCount){
/*    int vtCount = VertexCount/2;
    int faces[24]= {1,2,3,4,1,5,8,4,3,4,8,7,2,3,7,6,1,2,6,5,5,6,7,8};
    for(int i=0;i<24;i++){
        faces[i]=faces[i]+VertexCount;
    }

    int base=0;


    file<<"usemtl wallTexture"<<endl;
    file<<endl;

        for(int i=0;i<6;i++){
        file<<"\nf ";
        file<<faces[base]<<" "<<faces[base+1]<<" "<<faces[base+2];
        file<<"\nf ";
        file<<faces[base]<<" "<<faces[base+3]<<" "<<faces[base+2];
        base = base+4;
    }

    file<<endl;
    VertexCount = VertexCount+8;*/



}
