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
//    cout << "Luz actual: " << llums[llums.size()-1] << endl;
//    cout << "Total Luces: " << llums.size() << endl;


//    for (int i=0; i < llums.size(); i++)
//        cout << "Luz: " << llums[i] << endl;
    return (llums[llums.size()-1]);
}

void Mon::llumsToGPU(QGLShaderProgram *program){

    cout << "Entrando a llumsToGPU " << endl;

    getLlumActual();


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

//    for (int i=0; i<3; i++){
        gl_LightVector[ 0 ].ambiental = program->uniformLocation(QString("luz[0].ambiental").arg( 0 ));
        gl_LightVector[ 0 ].especular = program->uniformLocation(QString("luz[0].especular").arg( 0 ));
        gl_LightVector[ 0 ].difusa = program->uniformLocation(QString("luz[0].difusa").arg( 0 ));
        gl_LightVector[ 0 ].coordenadas = program->uniformLocation(QString("luz[0].coordenadas").arg( 0 ));
        gl_LightVector[ 0 ].tipo = program->uniformLocation(QString("luz[0].tipo").arg( 0 ));
        gl_LightVector[ 0 ].angulo = program->uniformLocation(QString("luz[0].angulo").arg( 0 ));
//    }


    // 3. Bind de les zones de memoria que corresponen
    // glUniform4fv(gl_IdVect[ i ].ex1, 1, vectorProva);   // vectorProva és una variable de tipus vec4

//    for (int i=0; i<3; i++){
        glUniform3fv(gl_LightVector[ 0 ].ambiental, 1, llums[0]->getAmbientaIntensity());
        glUniform3fv(gl_LightVector[ 0 ].especular, 1, llums[0]->getEspecularIntensity());
        glUniform3fv(gl_LightVector[ 0 ].difusa, 1, llums[0]->getDiffuseIntensity());
        glUniform3fv(gl_LightVector[ 0 ].coordenadas, 1, llums[0]->getLightPosition());
        glUniform1f(gl_LightVector[ 0 ].tipo, llums[0]->getType());
        glUniform1f(gl_LightVector[ 0 ].angulo, llums[0]->getAngle());
//    }

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
void Mon::setAmbientToGPU(QGLShaderProgram *program){
    cout << "Void de moment " << endl;

}
