#ifndef LIGHT_H
#define LIGHT_H

#include "Ray.h"
#include <vector>

typedef glm::vec3 RGB;

class Light{
protected:
	/* Declaro los tipos de luz */
    RGB ambiental;
    RGB specular;
    RGB difusa;

    /* Coordenadas de la luz */
    glm::vec4 coordenadas;

    /* Direccion luz */
    glm::vec4 direccion;

    float a, b, c;

public:
    Light();
	Light(RGB _ambiental,
		RGB _specular,
		RGB _difusa,
		glm::vec4 _coord,
		glm::vec4 _direcction,
		float _a,
		float _b,
		float _c);

	// Getters de la luz
	glm::vec3 getAmbiental() { return ambiental; }
    glm::vec3 getSpecular() { return specular; }
	glm::vec3 getDifusa() { return difusa; }
	glm::vec4 getCoord() { return coordenadas; }
	glm::vec4 getDirection() { return direccion; }
	float getA() { return a; }
	float getB() { return b; }
	float getC() { return c; }

};

#endif // LIGHT_H
