#ifndef MATERIAL_H
#define MATERIAL_H
#include <Common.h>
#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <stdio.h>
#include <math.h>

#include <Common.h>

using namespace std;

typedef Common::vec3 RGB;

// Classe que representa les propietats optiques d'un objecte
class Material {
private:

    RGB kd;
    RGB ks;
    RGB ka;
    float shininess;



public:
    Material();
    Material(RGB kd, RGB ks, RGB ka, float shininess);
    ~Material();
    void toGPU(QGLShaderProgram *program);
};

#endif // MATERIAL_H
