#ifndef LLUMAMBIENT_H
#define LLUMAMBIENT_H

#include <llum.h>

//using namespace std;

//typedef Common::vec3 RGB;

class llumPuntual: public Llum
{
protected:
    int on;
public:
    llumPuntual();
    ~llumPuntual();
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
};

#endif // LLUMAMBIENT_H
