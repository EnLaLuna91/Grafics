#include "gouraud.h"

/*
 * Constructor
 */
Gouraud::Gouraud(){

}

/*
 * Constructor sobrecargado
 *
 * Parameters:
 *      vector<Cara> --> Conjunto de caras
 */
Gouraud::Gouraud(vector<Cara> c){
    this->caras = c;
    calculaNormalGouraud();
}

/*
 * Destructor
 */
Gouraud::~Gouraud(){

}

/*
 * Pasar el conjunto de caras
 *
 * Parameters:
 *      vector<Cara> --> Conjunto de caras
 */
void Gouraud::setCaras(vector<Cara> c){
    this->caras = c;
    calculaNormalGouraud();
}

/*
 * Devuelve un vector de floats, que representa la normal de cada vertice.
 * Cada posicion 'i' del vector es el indice del vertice.  Por lo tanto
 * cada poscion del vector corresponde:
 *  - key = vector
 *  - value = Normal del vector
 *
 * Return:
 *      vector<vec3> --> Conjunto de normales de vertice
 */
//vec3 Gouraud::getNormalVertex(){
//    return this->normales;
//}

/*
 * Para cada cara calcula la normal, el resultado lo guarda en la posicion
 * i del vector, donde i = al vertice de la cara. Cada cara tiene 3 vertices.
 * Para calcular su normal suma las normales de todas las caras donde
 * aparece ese vertice.
 */
void Gouraud::calculaNormalGouraud(){
    vec4 verticesCara;
    Cara tmp;
    vec3 norml = 0.0;

    for (int i=0; i < this->caras.size(); i++){
        tmp = this->caras[i];
        norml = tmp.getNormal();
        this->normales[verticesCara[0]] += norml;
        this->normales[verticesCara[1]] += norml;
        this->normales[verticesCara[2]] += norml;
    }
}
