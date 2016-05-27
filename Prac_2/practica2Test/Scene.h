#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Ray.h"
#include "Object.h"
#include "Light.h"
#include "BlinnPhong.h"

#include <iostream>
#include <stdlib.h>

#include <vector> //Notice that vector in C++ is different from Vector2, Vector3 or similar things in a graphic library.

using namespace std;

class Scene
{
public:
    Scene();
    ~Scene();

    bool  CheckIntersection(const Ray &ray, IntersectInfo &info);
    float CastRay(Ray &ray, Payload &payload);

	int typeObject = 0;

    /*
    ** std::vector d'objectes continguts a l'escena
    */
    std::vector<Object*> objects;
	Object* getActualObject() { return (objects[objects.size()-1]); }
	void addObject(Object* o) { objects.push_back(o); }

    /*
     * camera de l'escena
     */
    Camera *cam;

    /*
     * TODO: Cal afegir el conjunt de llums de l'escena
     */
	std::vector<Light*> luces;
	Light* getActualLight() { return (luces[luces.size()-1]); }
	void addLight(Light* l) { luces.push_back(l); }

	/*
	 * Ambiente Global
	 */
	glm::vec3 ambientLight = glm::vec3(0.3f, 0.3f, 0.3f);

	/*
	 * Clase para calcular el Blinn-Phong
	 */
	BlinnPhong *phong;

private:
	glm::vec3 castRayRecursive(Ray &ray, Payload &payload);
	glm::vec3 sombras(IntersectInfo &info);
	bool intesectLight = false;
	const float epsilon = 0.001;
	const int MAX_REFLECT = 5;
};

#endif // SCENE_H
