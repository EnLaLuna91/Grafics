#ifndef LLUMAMBIENT_H
#define LLUMAMBIENT_H

#include <llum.h>

//using namespace std;

//typedef Common::vec3 RGB;

class llumPuntual: public Llum
{
private:
    /* Declaro los tipos de luz */
    RGB ambiental;
    RGB especular;
    RGB difusa;

    /* Lights */
    Lights luces;

    /* Coordenadas de la luz */
    vec4 coordenadas;

    int type;

public:
    llumPuntual();
    ~llumPuntual();
    virtual vec3 getDiffuseIntensity();
    virtual vec4 getLightPosition();
    virtual void setDiffuseIntensity(vec3 i);
    virtual void setLightPosition(vec4 v);
    virtual void switchOnOff();

    virtual int getType();
    virtual void ToGPU(QGLShaderProgram *program);
};

#endif // LLUMAMBIENT_H
