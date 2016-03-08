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
        Llum(Lights l);
        void setTipusLlum(Lights t);
        vec3 getDiffuseIntensity();
        vec4 getLightPosition();
        void setDiffuseIntensity(vec3 i);
        void setLightPosition(vec4 v);
        void switchOnOff();

        /* Getterts & Setters extras */

        vec3 getAmbientaIntensity();
        vec3 getEspecularIntensity();
        float getAngle();
        int getType();
        void setAmbientaIntensity(vec3 i);
        void setEspecularIntensity(vec3 i);
        void setAngle(float a);
        void setType(int i);
        void ToGPU();
};

#endif // LLUM_H
