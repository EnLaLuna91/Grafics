#ifndef LLUMSPOTLIGHT_H
#define LLUMSPOTLIGHT_H

#include <llum.h>

//using namespace std;

//typedef Common::vec3 RGB;

class llumSpotlight: public Llum
{
private:

    /* Angulo para el SpotLight */
    float angulo;
public:
    llumSpotlight();
    ~llumSpotlight();
    vec3 getDiffuseIntensity();
    vec4 getLightPosition();
    void setDiffuseIntensity(vec3 i);
    void setLightPosition(vec4 v);
    void switchOnOff();

    int getType();
    void ToGPU(QGLShaderProgram *program);
    void setAngle(float f);
    float getAngle();
};

#endif // LLUMSPOTLIGHT_H
