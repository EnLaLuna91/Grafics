#pragma once

#include <iostream>
#include <stdlib.h>
#include "Ray.h"

using namespace std;

class Material {
  public:
    Material();
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;

};

// Es la classe pare de tots els objectes que s'han de visualitzar.
class Object {
  public:
    Object(const glm::mat4 &transform = glm::mat4(1.0f), const Material &material = Material());

    virtual bool Intersect(const Ray &ray, IntersectInfo &info) const { return true; }
    glm::vec3 Position() const { return glm::vec3(transform[3][0], transform[3][1], transform[3][2]); }
    const Material *MaterialPtr() const { return &material; }

  protected:
    glm::mat4 transform;  // Matriu de transformacio de coordenades locals a globals
    Material material;
};

// TODO: Cal definir els diferents tipus d'objectes de l'escena com a fills d'Object.
// Cal definir-lis els atributs propis i implementar la funció
// tots els objectes de l'escena, cal definir el metode Intersect()

/* TODO: Implementar en el punt 2 de l'enunciat*/
class Sphere : public Object {
  public:
    glm::vec3 centerSphere;
    float radio;
    Sphere(glm::vec3 coord, float rad);
    bool Intersect(const Ray &ray, IntersectInfo &info) const;  //  To figure out if the Ray hit this object.

};

/* TODO: Implementar en el punt 2 de l'enunciat*/
class Plane : public Object {
  public:
	Plane(glm::vec3 vX, glm::vec3 vY, glm::vec3 p);
     virtual bool Intersect(const Ray &ray, IntersectInfo &info) const;
	glm::vec3 vecX, vecY, point;
};

/* TODO: Implementar com a extensio*/
class Triangle : public Object {
  public:
    virtual bool Intersect(const Ray &ray, IntersectInfo &info) const;
};
