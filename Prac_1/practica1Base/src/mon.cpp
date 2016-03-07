#include "mon.h"

Mon::Mon() {    
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

//    // 1. Es declara un vector d'identificadors
//    struct {
//        GLuint ambiental;
//        GLuint especular;
//        GLuint difusa;
//        GLuint coordenadas;
//        GLuint tipo;
//        GLuint angulo;
//    } gl_Light gl_LightVector[3];

//    // 2. obtencio dels identificadors de la GPU: Suposem i l'index de l'i-èssim element del vector
////    gl_IdVect[ i ].ex1 = program->uniformLocation(QString("conjunt[%1]. exemple1").arg( i ));

//    gl_LightVector[ 0 ].ex1 = program->uniformLocation(QString("luz[0].ambiental").arg( 0 ));
//    gl_LightVector[ 1 ].ex1 = program->uniformLocation(QString("luz[1].especular").arg( 1 ));
//    gl_LightVector[ 2 ].ex1 = program->uniformLocation(QString("luz[2].difusa").arg( 2 ));
//    gl_LightVector[ 3 ].ex1 = program->uniformLocation(QString("luz[3].coordenadas").arg( 3 ));
//    gl_LightVector[ 4 ].ex1 = program->uniformLocation(QString("luz[4].tipo").arg( 4 ));
//    gl_LightVector[ 5 ].ex1 = program->uniformLocation(QString("luz[5].angulo").arg( 5 ));


//    // 3. Bind de les zones de memoria que corresponen
////    glUniform4fv(gl_IdVect[ i ].ex1, 1, vectorProva);   // vectorProva és una variable de tipus vec4

//    glUniform3fv(gl_LightVector[ 0 ].ambiental, 1, luz.getAmbientaIntensity());
//    glUniform3fv(gl_LightVector[ 1 ].especular, 1, luz.especular());
//    glUniform3fv(gl_LightVector[ 2 ].difusa, 1, luz.getDiffuseIntensity());
//    glUniform3fv(gl_LightVector[ 3 ].coordenadas, 1, luz.getLightPosition());
//    glUniform1f(gl_LightVector[ 4 ].tipo, luz.getType());
//    glUniform1f(gl_LightVector[ 5 ].angulo, luz.getAngle());

}

void Mon::addLlum(Llum *l) {
    llums.push_back(l);

}
