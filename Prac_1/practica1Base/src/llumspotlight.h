#ifndef LLUMSPOTLIGHT_H
#define LLUMSPOTLIGHT_H

#include <llum.h>

//using namespace std;

//typedef Common::vec3 RGB;

class llumSpotlight: public Llum
{
protected:
    int on;
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
    void setLightDirecction(vec4 v);
    vec4 getLightDirecction();
    float getA();
    float getB();
    float getC();
    int getSwitchOnOff();

    int getType();
    void ToGPU(QGLShaderProgram *program);
    void setAngle(float f);
    float getAngle();
};

#endif // LLUMSPOTLIGHT_H
