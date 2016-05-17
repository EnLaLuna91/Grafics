#include "Light.h"

Light::Light():
	ambiental(RGB(0.2f, 0.2f, 0.2f)),
	specular(RGB(1.0f, 1.0f, 1.0f)),
	difusa(RGB(0.8f, 0.8f, 0.8f)),
	// coordenadas(glm::vec4(2.0f, 2.0f, 2.0f, 1.0f)),
	coordenadas(glm::vec4(0.0f, 5.0f, -1.0f, 1.0f)),
	direccion(glm::vec4(2.0f, 2.0f, 2.0f, 1.0f)),
	a(0.0f), b(0.0f), c(1.0f)
	{}

Light::Light(RGB _ambiental, RGB _specular, RGB _difusa, glm::vec4 _coord,
	glm::vec4 _direcction, float _a, float _b, float _c):
		ambiental(_ambiental),
		specular(_specular),
		difusa(_difusa),
		coordenadas(_coord),
		direccion(_direcction),
		a(_a), b(_b), c(_c)
		{}
