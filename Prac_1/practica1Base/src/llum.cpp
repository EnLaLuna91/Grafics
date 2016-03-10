#include "llum.h"

Llum::Llum(Lights t) {
//    this->ambiental = {1.0, 1.0, 1.0};
//    this->especular = {1.0, 1.0, 1.0};
//    this->spotLight = {1.0, 1.0, 1.0};


    this->luces = t;

//    if (t == Puntual){
//        this->luces.Puntual = t;
//        cout << "Luz Puntual: " << t << endl;
//    }else if (t == Direccional){
//        this->luces.Direccional = t;
//        cout << "Luz Direccional: " << t << endl;
//    }else if (t == SpotLight){
//        this->luces.SpotLight = t;
//        cout << "Luz SpotLight: " << t << endl;
//    }

    this->ambiental[0] = 1.0;
    this->ambiental[1] = 0.0;
    this->ambiental[2] = 1.0;

    this->especular[0] = 1.0;
    this->especular[1] = 1.0;
    this->especular[2] = 0.0;

    this->difusa[0] = 0.0;
    this->difusa[1] = 0.0;
    this->difusa[2] = 1.0;

//    this->coordenadas[0] = 1.0;
//    this->coordenadas[1] = 1.0;
//    this->coordenadas[2] = 1.0;
//    this->coordenadas[3] = 1.0;

    this->angulo = 0.0;

    cout << "Lights: " << this->luces <<  endl;

}

void Llum::ToGPU(){



}

void Llum::setTipusLlum(Lights t) {

    this->luces = t;

    if (t == Puntual){
//        this->luces.Puntual = t;
        cout << "Luz Puntual: " << t << endl;
    }else if (t == Direccional){
//        this->luces.Direccional = t;
        cout << "Luz Direccional: " << t << endl;
    }else if (t == SpotLight){
//        this->luces.SpotLight = t;
        cout << "Luz SpotLight: " << t << endl;
    }
}

vec3 Llum::getDiffuseIntensity() {
// A canviar
    return this->difusa;
}

vec4 Llum::getLightPosition() {
    // A canviar
    return this->coordenadas;
}

void Llum::setDiffuseIntensity(vec3 i) {
// el float que es reb ha de multiplicar els tres valors de la intensitat digusa de la llum
    this->difusa = i;
}

void Llum::setLightPosition(vec4 v) {
    this->coordenadas = v;
}

void Llum::switchOnOff() {
    // Si esta en on la posa a off i a l'inreves

}


/* Getterts & Setters extras */

vec3 Llum::getAmbientaIntensity(){
    return this->ambiental;
}

vec3 Llum::getEspecularIntensity(){
    return this->especular;
}

float Llum::getAngle(){
    return this->angulo;
}

int Llum::getType(){
    return this->type;
}

void Llum::setAmbientaIntensity(vec3 i){
    this->ambiental = i;
}

void Llum::setEspecularIntensity(vec3 i){
    this->especular = i;
}

void Llum::setAngle(float a){
    this->angulo = a;
}

void Llum::setType(int i){
    this->type = i;
}
