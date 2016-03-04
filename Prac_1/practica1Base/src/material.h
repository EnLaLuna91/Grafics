#ifndef MATERIAL_H
#define MATERIAL_H
#include <Common.h>
#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <stdio.h>
#include <math.h>

#include <Common.h>

// Classe que representa les propietats optiques d'un objecte
class Material {
private:
    typedef Common::vec3 RGB;
    RGB kd;
    RGB ks;
    RGB ka;

public:
    Material();
    Material(RGB kd, RGB ks, RGB ka);
    ~Material();
    toGPU(QGLShaderProgram *program);
};

#endif // MATERIAL_H
