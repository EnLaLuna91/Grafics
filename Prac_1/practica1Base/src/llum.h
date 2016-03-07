#ifndef LLUM_H
#define LLUM_H

#include <Common.h>

using namespace std;

typedef Common::vec3 RGB;

// Tipus de llums
enum Lights {Puntual, Direccional, SpotLight};

// Classe que representa els atributs d'una llum
class Llum {
    private:
        RGB puntual;
        RGB direccional;
        RGB spotLight;

        Lights luces;


    public:
        Llum(Lights l);
        void setTipusLlum(Lights t);
        vec3 getDiffuseIntensity();
        vec4 getLightPosition();
        void setDiffuseIntensity(vec3 i);
        void setLightPosition(vec4 v);
        void switchOnOff();
};

#endif // LLUM_H
