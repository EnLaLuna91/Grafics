#ifndef LLUMSPOTLIGHT_H
#define LLUMSPOTLIGHT_H

#include <llum.h>

//using namespace std;

//typedef Common::vec3 RGB;

class llumSpotlight: public Llum
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

    /* Angulo para el SpotLight */
    float angulo;

    int type;

public:
    llumSpotlight();
    ~llumSpotlight();
    virtual vec3 getDiffuseIntensity();
    virtual vec4 getLightPosition();
    virtual void setDiffuseIntensity(vec3 i);
    virtual void setLightPosition(vec4 v);
    virtual void switchOnOff();

    virtual int getType();
    virtual void ToGPU(QGLShaderProgram *program);
    void setAngle(float f);
    float getAngle();
};

#endif // LLUMSPOTLIGHT_H
