#ifndef ESCENA_H
#define ESCENA_H

#include <cmath>
#include <iostream>
#include <stdlib.h>

#include <list>
#include <vector>
#include <string>
#include <stdio.h>

#include <Common.h>
#include <objecte.h>
#include <llum.h>
#include <llumdireccional.h>
#include <llumpuntual.h>
#include <llumspotlight.h>

using namespace std;

// Virtual World: contains all objects, lights to visualize the scene
// the viewer is placed in the z+ axis and the  visible frustum is enclosed to (-1,-1,-1) to (1,1,1)



class Mon {
private:
//    Llum luz;
    llumPuntual *LuzPunt;
    llumDireccional *LuzDirec;
    llumSpotlight *LuzSpot;
    vec3 AmbientLight;

    bool PhongTex;
    bool GouraudTex;

public:
    Mon();
    ~Mon();

    void addObjecte(Objecte *obj);


    void draw();

    void addLlum(Llum *l);
    Llum *getLlumActual();
    void llumsToGPU(QGLShaderProgram *program);
    //Intensitat global que es passarà a la GPU per a
    //ser utilitzada pels shaders
    void setAmbientToGPU(QGLShaderProgram *program);

    vector <Objecte*> elements;
    vector<Llum*> llums;

    void phongTexOnOff();
    void phongTexToGPU(QGLShaderProgram *program);

    void gouraudTexOnOff();
    void gouraudTexToGPU(QGLShaderProgram *program);

};

#endif // ESCENA_H
