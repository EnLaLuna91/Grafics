#include "mon.h"

Mon::Mon() {    
     cout << "Entrando en MON " << endl;
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

    //    if (type == Puntual){
    //        cout << "LuzPuntual: " << getLlumActual() << endl;
    //        LuzPunt->setType(Puntual);
    //        LuzDirec->setType(-1);
    //        LuzSpot->setType(-1);
            LuzPunt->ToGPU(program);
    //    }else if (type == Direccional){
    //        cout << "LuzDireccional: " << getLlumActual() << endl;
    //        LuzPunt->setType(-1);
    //        LuzDirec->setType(Direccional);
    //        LuzSpot->setType(-1);
            LuzDirec->ToGPU(program);
    //    }else if (type == SpotLight){
    //        cout << "LuzSpotLight: " << getLlumActual() << endl;
    //        LuzPunt->setType(-1);
    //        LuzDirec->setType(-1);
    //        LuzSpot->setType(SpotLight);
            LuzSpot->ToGPU(program);
    //    }


}

void Mon::addLlum(Llum *l) {
    llums.push_back(l);

    int type = getLlumActual()->getType();


    LuzPunt = new llumPuntual;
    LuzDirec = new llumDireccional;
    LuzSpot = new llumSpotlight;

}
void Mon::setAmbientToGPU(QGLShaderProgram *program){
    cout << "Void de moment " << endl;

}
