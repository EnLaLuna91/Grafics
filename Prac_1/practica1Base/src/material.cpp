#include "material.h"

/*
 * Constructor de Material, imponemos el material
 */
Material::Material() {

    /* Gold Material */
    this->kd = {0.75164, 0.60648, 0.22648};
    this->ks = {0.628281, 0.555802, 0.366065};
    this->ka = {0.24725, 0.1995, 0.0745};


    /* Silver Material  */
//    this->kd = {0.50754, 0.50754, 0.50754};
//    this->ks = {0.508273, 0.508273, 0.508273};
//    this->ka = {0.19225, 0.19225, 0.19225};
}

/*
 * Contructor de Material sobrecargado, el materia lo pasamos por referencia
 */
Material::Material(RGB kd, RGB ks, RGB ka){
    this->kd = kd;
    this->ks = ks;
    this->ka = ka;
}

/*
 * Destructor de Materia
 */
Material::~Material(){

}

Material::toGPU(QGLShaderProgram *program){

}
