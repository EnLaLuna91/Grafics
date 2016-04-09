#ifndef OBJECTE_H
#define OBJECTE_H

#include <QObject>
#include <vector>
#include <Common.h>
#include <cara.h>
#include <QGLShaderProgram>
#include <QOpenGLTexture>
#include <material.h>

using namespace std;

typedef Common::vec4  point4;

// Classe que conte la representacio d'un objecte: geometria, topologia, material i textures
class Objecte : public QObject {

    Q_OBJECT
protected:
    QString nom;
    vector<Cara> cares;
    vector<point4> vertexs;

    GLuint buffer;

    int     numPoints;
    point4 *points;
//    point4 *colors;
    vec3 *normales;

    int Index; // index de control del numero de vertexs a posar a la GPU

    vector<vec3> normalesAcumulada;
//    vector<vec3> normales;

    Material *mat;

    QGLShaderProgram *program;

    QOpenGLTexture *texture;

    vec2 *vertexsTextura;
public:

    Objecte(const int npoints, QObject *parent = 0);
    Objecte(const int npoints, QString n);
    ~Objecte();

    virtual void readObj(QString filename);

    virtual void make();
    virtual void toGPU(QGLShaderProgram *p);
    virtual void draw();

private:
    void textures( int a, int b, int c, int d );
    void construeix_cara ( char **words, int nwords);
    void calculaNormal();
    void initTextura();
    void aplicaTG(mat4 m);
};



#endif // OBJECTE_H
