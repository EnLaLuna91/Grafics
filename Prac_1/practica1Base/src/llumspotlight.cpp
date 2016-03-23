#include "llumspotlight.h"

llumSpotlight::llumSpotlight():Llum(SpotLight)
{

    this->type = SpotLight;

    this->ambiental[0] = 0.0;
    this->ambiental[1] = 0.0;
    this->ambiental[2] = 1.0;

    this->especular[0] = 0.0;
    this->especular[1] = 0.0;
    this->especular[2] = 1.0;

    this->difusa[0] = 0.0;
    this->difusa[1] = 0.0;
    this->difusa[2] = 1.0;

    this->angulo = 5.0;

    coordenadas[0] = 1.0;
    coordenadas[1] = 1.0;
    coordenadas[2] = 1.0;
    coordenadas[3] = 1.0;

    direccion[0] = 0.0;
    direccion[1] = 0.0;
    direccion[2] = 5.0;
    direccion[3] = 0.0;

}

llumSpotlight::~llumSpotlight(){

}

vec3 llumSpotlight::getDiffuseIntensity(){
    return Llum::getDiffuseIntensity();
}

vec4 llumSpotlight::getLightPosition(){
    return Llum::getLightPosition();
}

void llumSpotlight::setDiffuseIntensity(vec3 i){
    Llum::setDiffuseIntensity(i);
}

void llumSpotlight::setLightPosition(vec4 v){
    Llum::setLightPosition(v);
}

void llumSpotlight::switchOnOff(){

}

int llumSpotlight::getType(){
    return Llum::getType();
}

void llumSpotlight::setLightDirecction(vec4 v){
    Llum::setLightDirecction(v);
}

vec4 llumSpotlight::getLightDirecction(){
    return Llum::getLightDirecction();
}

void llumSpotlight::ToGPU(QGLShaderProgram *program){
//    cout << "Entrando a llumSpotlight::ToGPU " << endl;



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
//    cout << "Spotlight->ambiental = " << this->ambiental << endl;
//    cout << "Spotlight->especular = " << this->especular << endl;
//    cout << "Spotlight->difusa = " << this->difusa << endl;
//    cout << "Spotlight->coordenadas = " << this->coordenadas << endl;
//    cout << "Spotlight->tipo = " << i << endl;
//    cout << "Spotlight->angulo = " << this->angulo << endl;
}

void llumSpotlight::setAngle(float f){
    this->angulo = f;
}

float llumSpotlight::getAngle(){
    return this->angulo;
}
