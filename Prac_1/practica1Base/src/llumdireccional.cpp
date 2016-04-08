#include "llumdireccional.h"

llumDireccional::llumDireccional():Llum(Direccional)
{

    type = Direccional;

    ambiental = vec3(0.2f, 0.2f, 0.2f);

    especular = vec3(1.0f, 1.0f, 1.0f);

    difusa = vec3(0.8f, 0.0f, 0.0f);

    coordenadas[0] = 0.0;
    coordenadas[1] = 0.0;
    coordenadas[2] = 0.0;
    coordenadas[3] = 0.0;

    direccion[0] = 5.0f;
    direccion[1] = 10.0f;
    direccion[2] = -1.0f;
    direccion[3] = 1.0f;

    a = 0.0f;
    b = 0.0f;
    c = 1.0f;

    on = false;

}

llumDireccional::~llumDireccional(){

}

vec3 llumDireccional::getDiffuseIntensity(){
    return Llum::getDiffuseIntensity();
}

vec4 llumDireccional::getLightPosition(){
    return Llum::getLightPosition();
}

void llumDireccional::setDiffuseIntensity(vec3 i){
    Llum::setDiffuseIntensity(i);
}

void llumDireccional::setLightPosition(vec4 v){
    Llum::setLightPosition(v);
}

void llumDireccional::switchOnOff(){
    if (on == false)
        on = true;
    else
        on = false;
}

int llumDireccional::getSwitchOnOff(){
    return on;
}

int llumDireccional::getType(){
    return Llum::getType();
}

void llumDireccional::setLightDirecction(vec4 v){
    Llum::setLightDirecction(v);
}

vec4 llumDireccional::getLightDirecction(){
    return Llum::getLightDirecction();
}

float llumDireccional::getA(){
    return Llum::getA();
}

float llumDireccional::getB(){
    return Llum::getB();
}

float llumDireccional::getC(){
    return Llum::getC();
}

void llumDireccional::ToGPU(QGLShaderProgram *program){

//    cout << "Entrando a llumDireccional::ToGPU " << endl;



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
    glUniform1f(gl_LightVector[ i ].angulo, 0.0);
    glUniform1f(gl_LightVector[ i ].a, a);
    glUniform1f(gl_LightVector[ i ].b, b);
    glUniform1f(gl_LightVector[ i ].c, c);
    glUniform1i(gl_LightVector[ i ].on, on);


//    cout << "Saliendo de llumsToGPU " << endl;
//    cout << "Direccional->ambiental = " << this->ambiental << endl;
//    cout << "Direccional->especular = " << this->especular << endl;
//    cout << "Direccional->difusa = " << this->difusa << endl;
//    cout << "Direccional->coordenadas = " << this->coordenadas << endl;
//    cout << "Direccional->tipo = " << i << endl;
//    cout << "Direccional->angulo = " << 0.0 << endl;

}
