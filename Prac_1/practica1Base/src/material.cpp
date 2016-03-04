#include "material.h"

/*
 * Constructor de Material, imponemos el material
 */
Material::Material() {

    cout << "Inicilizo Material" << endl;

    /* Gold Material */
//    this->kd = {0.75164, 0.60648, 0.22648};
//    this->ks = {0.628281, 0.555802, 0.366065};
//    this->ka = {0.24725, 0.1995, 0.0745};
//    this->shininess = 0.4;

    /* Red Color*/
    this->kd = {1.0, 0.0, 0.0};
    this->ks = {0.628281, 0.555802, 0.366065};
    this->ka = {0.24725, 0.1995, 0.0745};
    this->shininess = 1.0;


    /* Silver Material  */
//    this->kd = {0.50754, 0.50754, 0.50754};
//    this->ks = {0.508273, 0.508273, 0.508273};
//    this->ka = {0.19225, 0.19225, 0.19225};
//    this->shininess = 0.4;

    cout << "Saliendo del constructor de Material" << endl;
}

/*
 * Contructor de Material sobrecargado, el materia lo pasamos por referencia
 */
Material::Material(RGB kd, RGB ks, RGB ka, float shininess){

    cout << "Inicilizo Material sobrecargado" << endl;

    this->kd = kd;
    this->ks = ks;
    this->ka = ka;
    this->shininess = shininess;

     cout << "Saliendo del constructor de Material" << endl;
}

/*
 * Destructor de Materia
 */
Material::~Material(){

}

void Material::toGPU(QGLShaderProgram *program){

    cout << "Entrando en toGPU" << endl;

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
    glUniform3fv(GL_Intesity.kd, 1, this->kd);
    glUniform3fv(GL_Intesity.ks, 1, this->ks);
    glUniform3fv(GL_Intesity.ka, 1, this->ka);
    glUniform1f(GL_Intesity.shininess, this->shininess);

    cout << "kd = " << kd[0] << " " << kd[1] << " " << kd[2] << endl;
    cout << "ks = " << ks[0] << " " << ks[1] << " " << ks[2] << endl;
    cout << "ka = " << ka[0] << " " << ka[1] << " " << ka[2] << endl;

    cout << "Saliendo de toGPU" << endl;

}
