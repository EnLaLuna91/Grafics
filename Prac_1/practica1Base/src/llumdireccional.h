#ifndef LLUMDIRECCIONAL_H
#define LLUMDIRECCIONAL_H

#include <llum.h>

//using namespace std;

//typedef Common::vec3 RGB;

class llumDireccional: public Llum
{
public:
    llumDireccional();
    ~llumDireccional();
    vec3 getDiffuseIntensity();
    vec4 getLightPosition();
    void setDiffuseIntensity(vec3 i);
    void setLightPosition(vec4 v);
    void switchOnOff();
    void setLightDirecction(vec4 v);
    vec4 getLightDirecction();

    int getType();
    void ToGPU(QGLShaderProgram *program);
};

#endif // LLUMDIRECCIONAL_H
