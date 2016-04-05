#include "llumpuntual.h"

llumPuntual::llumPuntual():Llum(Puntual)
{

    this->type = Puntual;

    this->ambiental = vec3(0.2f, 0.2f, 0.2f);

    this->especular = vec3(1.0f, 1.0f, 1.0f);

    this->difusa = vec3(0.8f, 0.8f, 0.8f);

    this->coordenadas = vec4(2.0f, 2.0f, 2.0f, 1.0f);

    direccion[0] = 0.0;
    direccion[1] = 0.0;
    direccion[2] = 0.0;
    direccion[3] = 0.0;

    a = 0.0f;
    b = 0.0f;
    c = 1.0f;

    on = 1;
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
    if (on == 0)
        on = 1;
    else
        on = 0;
}

int llumPuntual::getSwitchOnOff(){
    return on;
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

float llumPuntual::getA(){
    return Llum::getA();
}

float llumPuntual::getB(){
    return Llum::getB();
}

float llumPuntual::getC(){
    return Llum::getC();
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
    gl_LightVector[ i ].a = program->uniformLocation(QString("luz[%1].a").arg( i ));
    gl_LightVector[ i ].b = program->uniformLocation(QString("luz[%1].b").arg( i ));
    gl_LightVector[ i ].c = program->uniformLocation(QString("luz[%1].c").arg( i ));



    // 3. Bind de les zones de memoria que corresponen
    // glUniform4fv(gl_IdVect[ i ].ex1, 1, vectorProva);   // vectorProva és una variable de tipus vec4

    glUniform3fv(gl_LightVector[ i ].ambiental, 1, ambiental);
    glUniform3fv(gl_LightVector[ i ].especular, 1, especular);
    glUniform3fv(gl_LightVector[ i ].difusa, 1, difusa);
    glUniform3fv(gl_LightVector[ i ].coordenadas, 1, coordenadas);
    glUniform3fv(gl_LightVector[ i ].direccion, 1, direccion);
    glUniform1f(gl_LightVector[ i ].tipo, i);
    glUniform1f(gl_LightVector[ i ].angulo, 0.0);
    glUniform1f(gl_LightVector[ i ].a, a);
    glUniform1f(gl_LightVector[ i ].b, b);
    glUniform1f(gl_LightVector[ i ].c, c);


//    cout << "Saliendo de llumsToGPU " << endl;
//    cout << "Puntual->ambiental = " << this->ambiental << endl;
//    cout << "Puntual->especular = " << this->especular << endl;
//    cout << "Puntual->difusa = " << this->difusa << endl;
//    cout << "Puntual->coordenadas = " << this->coordenadas << endl;
//    cout << "Puntual->tipo = " << i << endl;
//    cout << "Puntual->angulo = " << 0.0 << endl;
}
