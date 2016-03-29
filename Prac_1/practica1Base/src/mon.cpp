#include "mon.h"

Mon::Mon() {    
//     cout << "Entrando en MON " << endl;
    AmbientLight[0] = 0.3;
    AmbientLight[1] = 0.3;
    AmbientLight[2] = 0.3;
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

//        if (LuzPunt->getSwitchOnOff() == 1 ){
            LuzPunt->ToGPU(program);
//        }
//        if (LuzDirec->getSwitchOnOff() == 1 ){
            LuzDirec->ToGPU(program);
//        }
//        if (LuzSpot->getSwitchOnOff() == 1 ){
            LuzSpot->ToGPU(program);
//        }


}

void Mon::addLlum(Llum *l) {
    llums.push_back(l);

    int type = getLlumActual()->getType();


    LuzPunt = new llumPuntual;
    LuzDirec = new llumDireccional;
    LuzSpot = new llumSpotlight;

}
void Mon::setAmbientToGPU(QGLShaderProgram *program){
    GLuint LuzAmbient = program->uniformLocation("vLuzAmbiente");
    glUniform3fv(LuzAmbient, 1, AmbientLight);
}
