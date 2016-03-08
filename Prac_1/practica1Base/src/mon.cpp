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

    cout << "Entrando a llumsToGPU " << endl;



    // 1. Es declara un vector d'identificadors
    struct gl_Light{
        GLuint ambiental;
        GLuint especular;
        GLuint difusa;
        GLuint coordenadas;
        GLuint tipo;
        GLuint angulo;
    };
    gl_Light gl_LightVector[3];


    // 2. obtencio dels identificadors de la GPU: Suposem i l'index de l'i-èssim element del vector
    // gl_IdVect[ i ].ex1 = program->uniformLocation(QString("conjunt[%1]. exemple1").arg( i ));

    for (int i=0; i<3; i++){
        gl_LightVector[ i ].ambiental = program->uniformLocation(QString("luz[i].ambiental").arg( i ));
        gl_LightVector[ i ].especular = program->uniformLocation(QString("luz[i].especular").arg( i ));
        gl_LightVector[ i ].difusa = program->uniformLocation(QString("luz[i].difusa").arg( i ));
        gl_LightVector[ i ].coordenadas = program->uniformLocation(QString("luz[i].coordenadas").arg( i ));
        gl_LightVector[ i ].tipo = program->uniformLocation(QString("luz[i].tipo").arg( i ));
        gl_LightVector[ i ].angulo = program->uniformLocation(QString("luz[i].angulo").arg( i ));
    }


    // 3. Bind de les zones de memoria que corresponen
    // glUniform4fv(gl_IdVect[ i ].ex1, 1, vectorProva);   // vectorProva és una variable de tipus vec4

    for (int i=0; i<3; i++){
        glUniform3fv(gl_LightVector[ i ].ambiental, 1, llums[i]->getAmbientaIntensity());
        glUniform3fv(gl_LightVector[ i ].especular, 1, llums[i]->getEspecularIntensity());
        glUniform3fv(gl_LightVector[ i ].difusa, 1, llums[i]->getDiffuseIntensity());
        glUniform3fv(gl_LightVector[ i ].coordenadas, 1, llums[i]->getLightPosition());
        glUniform1f(gl_LightVector[ i ].tipo, llums[i]->getType());
        glUniform1f(gl_LightVector[ i ].angulo, llums[i]->getAngle());
    }

    cout << "Saliendo de llumsToGPU " << endl;
    cout << "lums[0]->ambiental = " << llums[0]->getAmbientaIntensity() << endl;
    cout << "lums[0]->especular = " << llums[0]->getEspecularIntensity() << endl;
    cout << "lums[0]->difusa = " << llums[0]->getDiffuseIntensity() << endl;
    cout << "lums[0]->coordenadas = " << llums[0]->getLightPosition() << endl;
    cout << "lums[0]->tipo = " << llums[0]->getType() << endl;
    cout << "lums[0]->angulo = " << llums[0]->getAngle() << endl;

}

void Mon::addLlum(Llum *l) {
    llums.push_back(l);

}
