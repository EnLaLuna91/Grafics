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

    int type = getLlumActual()->getType();

    getLlumActual()->ToGPU(program);
//    llums[0]->ToGPU(program);
//    llums[1]->ToGPU(program);
//    llums[2]->ToGPU(program);



}

void Mon::addLlum(Llum *l) {
    llums.push_back(l);
}

void Mon::setAmbientToGPU(QGLShaderProgram *program){
    GLuint LuzAmbient = program->uniformLocation("vLuzAmbiente");
    glUniform3fv(LuzAmbient, 1, AmbientLight);
}

void Mon::phongTexOnOff(){
    if (PhongTex == false)
        PhongTex = true;
    else
        PhongTex = false;
}

void Mon::gouraudTexOnOff(){
    if (GouraudTex == false)
        GouraudTex = true;
    else
        GouraudTex = false;
}

void Mon::phongTexToGPU(QGLShaderProgram *program){
    GLuint phongTexture = program->uniformLocation("vPhongTex");
    glUniform1i(phongTexture, PhongTex);
}

void Mon::gouraudTexToGPU(QGLShaderProgram *program){
    GLuint gouraudTexture = program->uniformLocation("vGouraudTex");
    glUniform1i(gouraudTexture, GouraudTex);
}
