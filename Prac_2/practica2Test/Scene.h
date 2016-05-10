#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Ray.h"
#include "Object.h"

#include <llum.h>
#include <llumdireccional.h>
#include <llumpuntual.h>
#include <llumspotlight.h>

#include <vector> //Notice that vector in C++ is different from Vector2, Vector3 or similar things in a graphic library.


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

    /*
     * camera de l'escena
     */
    Camera *cam;
    /*
     * TODO: Cal afegir el conjunt de llums de l'escena
     */
    // glm:::vector<Llum*> llums;
	std::vector<Lum*> llums;

};

#endif // SCENE_H
