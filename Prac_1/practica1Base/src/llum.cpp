#include "llum.h"

Llum::Llum(Lights t) {
//    this->puntual = {1.0, 1.0, 1.0};
//    this->direccional = {1.0, 1.0, 1.0};
//    this->spotLight = {1.0, 1.0, 1.0};

    this->luces = t;

    this->puntual[0] = 1.0;
    this->puntual[1] = 1.0;
    this->puntual[2] = 1.0;

    this->direccional[0] = 1.0;
    this->direccional[1] = 1.0;
    this->direccional[2] = 1.0;

    this->spotLight[0] = 1.0;
    this->spotLight[1] = 1.0;
    this->spotLight[2] = 1.0;

}

void Llum::setTipusLlum(Lights t) {
    this->luces = t;
}

vec3 Llum::getDiffuseIntensity() {
// A canviar
    return(vec3(0.0, 0.0, 0.0));
}

vec4 Llum::getLightPosition() {
    // A canviar
    return(vec4(0.0, 0.0, 0.0, 0.0));
}

void Llum::setDiffuseIntensity(vec3 i) {
// el float que es reb ha de multiplicar els tres valors de la intensitat digusa de la llum
}

void Llum::setLightPosition(vec4 v) {

}

void Llum::switchOnOff() {
    // Si esta en on la posa a off i a l'inreves

}
