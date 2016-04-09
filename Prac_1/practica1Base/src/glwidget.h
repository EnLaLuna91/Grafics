#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <math.h>
#include <mon.h>
#include <QtWidgets>
#include <QGLWidget>
#include <QTime>

#define PROGRAM_VERTEX_ATTRIBUTE 0
#define PROGRAM_COLOR_ATTRIBUTE 1

enum Programs {Gouraud, Phong, Toon};

class QGLShaderProgram;

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void newObj(QString fichero);
public slots:

    // Menus
    void activaToonShader();
    void activaPhongShader();
    void activaGouraudShader();
    void activaPhongTex();
    void activaGouraudTex();
    // Per extensions
    void activaBumpMapping();
    void activaEnvMapping();

    void ensenyaMenuLlum0();
    void changePositionLight();
    void changeDirectionalLight();
    void changeSpotLight();
    void activateLight();
    void updateXPositionLight(int xposition);
    void updateYPositionLight(int yposition);
    void updateZPositionLight(int zposition);
    void updateLightIntensity(int intensity);
    void showAuxWindowPuntualLight(Llum *light);


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    // keyPressEvent
    void keyPressEvent(QKeyEvent *event);

private:
    QWidget* auxWidget; // window for parameters

    // Clase en la q se va llenando de objetos para generar la esfera
    Mon *mon;

//    QGLShaderProgram *program;
    QGLShaderProgram *program[3];

    Programs ultimoProgramCargado;

    void InitShader( const char* vertexShaderFile, const char* fragmentShaderFile);
    void initShadersGPU();

    // Función de soporte para el keyPressEvent
    void calcalateNewPositionX(float num);
    void calcalateNewPositionY(float num);



};

#endif // GLWIDGET_H
