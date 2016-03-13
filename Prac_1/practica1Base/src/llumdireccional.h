#ifndef LLUMDIRECCIONAL_H
#define LLUMDIRECCIONAL_H

#include <llum.h>

//using namespace std;

//typedef Common::vec3 RGB;

class llumDireccional: public Llum
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
    llumDireccional();
    ~llumDireccional();
    virtual vec3 getDiffuseIntensity();
    virtual vec4 getLightPosition();
    virtual void setDiffuseIntensity(vec3 i);
    virtual void setLightPosition(vec4 v);
    virtual void switchOnOff();

    virtual int getType();
    virtual void ToGPU(QGLShaderProgram *program);
};

#endif // LLUMDIRECCIONAL_H
