#include "mon.h"

Mon::Mon() {    
//     cout << "Entrando en MON " << endl;
    AmbientLight[0] = 0.3;
    AmbientLight[1] = 0.3;
    AmbientLight[2] = 0.3;
    PhongTex = false;
    GouraudTex = false;
}

Mon::~Mon() {
    elements.clear();
}

void Mon::addObjecte(Objecte *obj) {
    elements.push_back(obj);
}

void Mon::draw() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->draw();
    }
}

Llum* Mon::getLlumActual() {
    // Ara per ara dona com a llum actual la darrera que s'ha inserit, però es podria canviar segons el
    // que es vulgui fer en la GUI
    return (llums[llums.size()-1]);
}

void Mon::llumsToGPU(QGLShaderProgram *program){
    getLlumActual()->ToGPU(program);
}

void Mon::addLlum(Llum *l) {
    llums.push_back(l);
}

/**
 * Función que envia la luz ambient a la GPU
 * @brief Mon::setAmbientToGPU
 * @param program
 */
void Mon::setAmbientToGPU(QGLShaderProgram *program){
    GLuint LuzAmbient = program->uniformLocation("vLuzAmbiente");
    glUniform3fv(LuzAmbient, 1, AmbientLight);
}

/**
 * Enciende o apaga las texturas de Phong
 * @brief Mon::phongTexOnOff
 */
void Mon::phongTexOnOff(){
    if (PhongTex == false)
        PhongTex = true;
    else
        PhongTex = false;
}

/**
 * Enciende o apaga las texturas de Gouraud
 * @brief Mon::gouraudTexOnOff
 */
void Mon::gouraudTexOnOff(){
    if (GouraudTex == false)
        GouraudTex = true;
    else
        GouraudTex = false;
}

/**
 * Envia el estado de encedido o apagado de las texturas de Phong a la GPU
 * @brief Mon::phongTexToGPU
 * @param program
 */
void Mon::phongTexToGPU(QGLShaderProgram *program){
    GLuint phongTexture = program->uniformLocation("vPhongTex");
    glUniform1i(phongTexture, PhongTex);
}

/**
 * Envia el estado de encedido o apagado de las texturas de Gouraud a la GPU
 * @brief Mon::gouraudTexToGPU
 * @param program
 */
void Mon::gouraudTexToGPU(QGLShaderProgram *program){
    GLuint gouraudTexture = program->uniformLocation("vGouraudTex");
    glUniform1i(gouraudTexture, GouraudTex);
}
