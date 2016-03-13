#include "material.h"

/*
 * Constructor de Material, imponemos el material
 */
Material::Material() {

//    cout << "Inicilizo Material" << endl;

    /* Gold Material */
//    this->kd = {0.75164, 0.60648, 0.22648};
//    this->ks = {0.628281, 0.555802, 0.366065};
//    this->ka = {0.24725, 0.1995, 0.0745};
//    this->shininess = 0.4;

    /* Red Color*/
//    kd = {1.0, 0.0, 0.0};
    kd[0] = 1.0;
    kd[1] = 0.0;
    kd[2] = 0.0;

//    ks = {0.628281, 0.555802, 0.366065};

    ks[0] = 0.628281;
    ks[1] = 0.555802;
    ks[2] = 0.366065;


//    ka = {0.24725, 0.1995, 0.0745};

    ka[0] = 0.24725;
    ka[1] = 0.1995;
    ka[2] = 0.0745;

    shininess = 1.0;


    /* Silver Material  */
//    this->kd = {0.50754, 0.50754, 0.50754};
//    this->ks = {0.508273, 0.508273, 0.508273};
//    this->ka = {0.19225, 0.19225, 0.19225};
//    this->shininess = 0.4;

//    cout << "Saliendo del constructor de Material" << endl;
}

/*
 * Contructor de Material sobrecargado, el materia lo pasamos por referencia
 */
Material::Material(RGB _kd, RGB _ks, RGB _ka, float _shininess){

    cout << "Inicilizo Material sobrecargado" << endl;

    kd = _kd;
    ks = _ks;
    ka = _ka;
    shininess = _shininess;

     cout << "Saliendo del constructor de Material" << endl;
}

/*
 * Destructor de Materia
 */
Material::~Material(){

}

void Material::toGPU(QGLShaderProgram *program){

//    cout << "Entrando en toGPU" << endl;

    struct{
        GLuint kd;
        GLuint ks;
        GLuint ka;
        GLuint shininess;
    }GL_Intesity;

    // obtencio dels identificadors de la GPU

    GL_Intesity.kd = program->uniformLocation("IMaterial.kd");
    GL_Intesity.ks = program->uniformLocation("IMaterial.ks");
    GL_Intesity.ka = program->uniformLocation("IMaterial.ka");
    GL_Intesity.shininess = program->uniformLocation("IMaterial.shininess");

    // Bind de les zones de memòria que corresponen a la GPU a valors de les variables de la CPU
    glUniform3fv(GL_Intesity.kd, 1, kd);
    glUniform3fv(GL_Intesity.ks, 1, ks);
    glUniform3fv(GL_Intesity.ka, 1, ka);
    glUniform1f(GL_Intesity.shininess, shininess);

//    cout << "kd = " << kd << endl;
//    cout << "ks = " << ks << endl;
//    cout << "ka = " << ka << endl;
//    cout << "shininess = " << shininess << endl;


//    cout << "Saliendo de toGPU" << endl;

}
