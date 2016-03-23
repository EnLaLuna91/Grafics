#include "llumpuntual.h"

llumPuntual::llumPuntual():Llum(Puntual)
{

    this->type = Puntual;

    this->ambiental[0] = 0.0;
    this->ambiental[1] = 1.0;
    this->ambiental[2] = 0.0;

    this->especular[0] = 0.0;
    this->especular[1] = 1.0;
    this->especular[2] = 0.0;

    this->difusa[0] = 0.0;
    this->difusa[1] = 1.0;
    this->difusa[2] = 0.0;

    coordenadas[0] = 1.0;
    coordenadas[1] = 1.0;
    coordenadas[2] = 1.0;
    coordenadas[3] = 1.0;

    direccion[0] = 0.0;
    direccion[1] = 0.0;
    direccion[2] = 0.0;
    direccion[3] = 0.0;

}

llumPuntual::~llumPuntual(){

}

vec3 llumPuntual::getDiffuseIntensity(){
    return Llum::getDiffuseIntensity();
}

vec4 llumPuntual::getLightPosition(){
    return Llum::getLightPosition();
}

void llumPuntual::setDiffuseIntensity(vec3 i){
    Llum::setDiffuseIntensity(i);
}

void llumPuntual::setLightPosition(vec4 v){
    Llum::setLightPosition(v);
}

void llumPuntual::switchOnOff(){

}

int llumPuntual::getType(){
    return Llum::getType();
}

void llumPuntual::setLightDirecction(vec4 v){
    Llum::setLightDirecction(v);
}

vec4 llumPuntual::getLightDirecction(){
    return Llum::getLightDirecction();
}

void llumPuntual::ToGPU(QGLShaderProgram *program){

//    cout << "Entrando a llumPuntual::ToGPU " << endl;



    int i = this->type;


    // 2. obtencio dels identificadors de la GPU: Suposem i l'index de l'i-èssim element del vector
    // gl_IdVect[ i ].ex1 = program->uniformLocation(QString("conjunt[%1]. exemple1").arg( i ));

    gl_LightVector[ i ].ambiental = program->uniformLocation(QString("luz[%1].ambiental").arg( i ));
    gl_LightVector[ i ].especular = program->uniformLocation(QString("luz[%1].especular").arg( i ));
    gl_LightVector[ i ].difusa = program->uniformLocation(QString("luz[%1].difusa").arg( i ));
    gl_LightVector[ i ].coordenadas = program->uniformLocation(QString("luz[%1].coordenadas").arg( i ));
    gl_LightVector[ i ].direccion = program->uniformLocation(QString("luz[%1].direccion").arg( i ));
    gl_LightVector[ i ].tipo = program->uniformLocation(QString("luz[%1].tipo").arg( i ));
    gl_LightVector[ i ].angulo = program->uniformLocation(QString("luz[%1].angulo").arg( i ));



    // 3. Bind de les zones de memoria que corresponen
    // glUniform4fv(gl_IdVect[ i ].ex1, 1, vectorProva);   // vectorProva és una variable de tipus vec4

    glUniform3fv(gl_LightVector[ i ].ambiental, 1, this->ambiental);
    glUniform3fv(gl_LightVector[ i ].especular, 1, this->especular);
    glUniform3fv(gl_LightVector[ i ].difusa, 1, this->difusa);
    glUniform3fv(gl_LightVector[ i ].coordenadas, 1, this->coordenadas);
    glUniform3fv(gl_LightVector[ i ].direccion, 1, this->direccion);
    glUniform1f(gl_LightVector[ i ].tipo, i);
    glUniform1f(gl_LightVector[ i ].angulo, 0.0);


//    cout << "Saliendo de llumsToGPU " << endl;
//    cout << "Puntual->ambiental = " << this->ambiental << endl;
//    cout << "Puntual->especular = " << this->especular << endl;
//    cout << "Puntual->difusa = " << this->difusa << endl;
//    cout << "Puntual->coordenadas = " << this->coordenadas << endl;
//    cout << "Puntual->tipo = " << i << endl;
//    cout << "Puntual->angulo = " << 0.0 << endl;
}
