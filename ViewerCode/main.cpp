#include <iostream>
#include <irrlicht.h>
#include <fstream>
#include "Vertex.h"
#include "Wall.h"
using namespace irr;
using namespace std;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main()
{

    SIrrlichtCreationParameters params = SIrrlichtCreationParameters();
    params.AntiAlias = 4;
    params.DriverType = video::EDT_OPENGL;
    params.WindowSize = core::dimension2d<u32>(800, 700);
    IrrlichtDevice *device = createDeviceEx(params);

    if (!device){
        return 1;
    }

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();
    IMesh* mesh = smgr->getMesh("models/house.obj");

    smgr->setAmbientLight(video::SColorf(3.0f,3.0f,3.0f));

    IMeshSceneNode * node = smgr->addMeshSceneNode(mesh);

    node->setMaterialFlag(EMF_LIGHTING, true);
    node->setScale(core::vector3df(20,20,20));
    node->setScale(core::vector3df(0.3,0.3,0.3));

    node->setScale(core::vector3df(0.3,0.3,0.3));

    smgr->addCameraSceneNodeFPS(0, 100.0f,0.1f,-1,0,0,false,0.f,false,true);

    scene::ILightSceneNode* nodeLight = smgr->addLightSceneNode(0, core::vector3df(0, 0, 0), video::SColorf(1.0f, 1.0f, 1.0f),0.00001f);

    while(device->run())
    {
        driver->beginScene(true, true, SColor(255,100,101,140));
        smgr->drawAll();
        guienv->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}
