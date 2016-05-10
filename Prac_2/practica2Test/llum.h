#ifndef LLUM_H
#define LLUM_H

#include <Common.h>
// #include <QGLShaderProgram>

using namespace std;

typedef Common::vec3 RGB;

// Tipus de llums
enum Lights {Puntual, Direccional, SpotLight};

// Classe que representa els atributs d'una llum
class Llum {
    protected:
        /* Lights */
        Lights luces;

        /* Declaro los tipos de luz */
        RGB ambiental;
        RGB especular;
        RGB difusa;

        /* Coordenadas de la luz */
        vec4 coordenadas;

        /* Direccion luz */
        vec4 direccion;

        int type;

        float a, b, c;

        bool on;

        // 1. Es declara un vector d'identificadors
        struct gl_Light{
            GLuint ambiental;
            GLuint especular;
            GLuint difusa;
            GLuint coordenadas;
            GLuint direccion;
            GLuint tipo;
            GLuint angulo;
            GLuint a;
            GLuint b;
            GLuint c;
            GLuint on;
        };
        gl_Light gl_LightVector[3];


    public:
        Llum(Lights l);
        virtual ~Llum();
        void setTipusLlum(Lights t);
        virtual vec3 getDiffuseIntensity();
        virtual vec4 getLightPosition();
        virtual void setDiffuseIntensity(vec3 i);
        virtual void setLightPosition(vec4 v);
        virtual void switchOnOff();
        virtual void setLightDirecction(vec4 v);
        virtual vec4 getLightDirecction();
        virtual float getA();
        virtual float getB();
        virtual float getC();
        virtual int getSwitchOnOff();

        /* Getterts & Setters extras */


        virtual int getType();
        virtual void ToGPU(QGLShaderProgram *program);

        vec3 getAmbientaIntensity();
        vec3 getEspecularIntensity();
        void setAmbientaIntensity(vec3 i);
        void setEspecularIntensity(vec3 i);
        void setType(int i);





};

#endif // LLUM_H
