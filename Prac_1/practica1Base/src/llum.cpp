#include "llum.h"

Llum::Llum(Lights t) {


    this->luces = t;

}

Llum::~Llum(){

}

void Llum::ToGPU(QGLShaderProgram *program){



}

void Llum::setTipusLlum(Lights t) {

    this->luces = t;
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

int Llum::getSwitchOnOff(){
}

void Llum::setLightDirecction(vec4 v){
    this->direccion = v;
}

vec4 Llum::getLightDirecction(){
    return this->direccion;
}

float Llum::getA(){
    return this->a;
}

float Llum::getB(){
    return this->b;
}

float Llum::getC(){
    return this->c;
}


/* Getterts & Setters extras */

vec3 Llum::getAmbientaIntensity(){
    return this->ambiental;
}

vec3 Llum::getEspecularIntensity(){
    return this->especular;
}

int Llum::getType(){
    return this->luces;
}

void Llum::setAmbientaIntensity(vec3 i){
    this->ambiental = i;
}

void Llum::setEspecularIntensity(vec3 i){
    this->especular = i;
}

void Llum::setType(int i){
    this->type = i;
}
