#include "llumspotlight.h"

llumSpotlight::llumSpotlight():Llum(SpotLight)
{

    type = SpotLight;

    ambiental = vec3(0.2f);

    especular = vec3(0.2f);

    difusa[0] = 0.9f;
    difusa[1] = 0.9f;
    difusa[2] = 0.9f;

    angulo = 0.45f;

    coordenadas[0] = -1.0f;
    coordenadas[1] = 1.0f;
    coordenadas[2] = -1.0f;
    coordenadas[3] = 0.0f;

    direccion[0] = -1.0f;
    direccion[1] = 1.0f;
    direccion[2] = -1.0f;
    direccion[3] = 0.0f;

    a = 0.0f;
    b = 0.0f;
    c = 1.0f;

    on = 1;
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
    if (on == 0)
        on = 1;
    else
        on = 0;
}

int llumSpotlight::getSwitchOnOff(){
    return on;
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

float llumSpotlight::getA(){
    return Llum::getA();
}

float llumSpotlight::getB(){
    return Llum::getB();
}

float llumSpotlight::getC(){
    return Llum::getC();
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
    gl_LightVector[ i ].a = program->uniformLocation(QString("luz[%1].a").arg( i ));
    gl_LightVector[ i ].b = program->uniformLocation(QString("luz[%1].b").arg( i ));
    gl_LightVector[ i ].c = program->uniformLocation(QString("luz[%1].c").arg( i ));
    gl_LightVector[ i ].on = program->uniformLocation(QString("luz[%1].on").arg( i ));



    // 3. Bind de les zones de memoria que corresponen
    // glUniform4fv(gl_IdVect[ i ].ex1, 1, vectorProva);   // vectorProva és una variable de tipus vec4

    glUniform3fv(gl_LightVector[ i ].ambiental, 1, ambiental);
    glUniform3fv(gl_LightVector[ i ].especular, 1, especular);
    glUniform3fv(gl_LightVector[ i ].difusa, 1, difusa);
    glUniform4fv(gl_LightVector[ i ].coordenadas, 1, coordenadas);
    glUniform4fv(gl_LightVector[ i ].direccion, 1, direccion);
    glUniform1f(gl_LightVector[ i ].tipo, i);
    glUniform1f(gl_LightVector[ i ].angulo, angulo);
    glUniform1f(gl_LightVector[ i ].a, a);
    glUniform1f(gl_LightVector[ i ].b, b);
    glUniform1f(gl_LightVector[ i ].c, c);
    glUniform1f(gl_LightVector[ i ].on, on);


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
