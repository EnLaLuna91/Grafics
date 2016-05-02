#include "Object.h"

Material::Material():
    ambient(1.0f),
    diffuse(1.0f),
    specular(1.0f),
    shininess(10.0f)
  {}

Object::Object(const glm::mat4 &transform, const Material &material):
    transform(transform),
    material(material)
  {}

Sphere::Sphere(glm::vec3 coor, float rad){
    centerSphere = coor;
    radio = rad;
}

/* TODO: Implementar en el punt 2 */
bool Sphere::Intersect(const Ray &ray, IntersectInfo &info) const {


    float dirOrigCenter = glm::dot( ray.direction, (ray.origin - centerSphere) );
    float module = glm::pow( glm::length(ray.origin - centerSphere) , 2.0f );
    float radCuadratic = glm::pow( radio, 2.0f );
    float cuadratic = glm::sqrt( glm::pow( dirOrigCenter, 2.0f ) - module + radCuadratic );
    float distPos = -dirOrigCenter + cuadratic;
    float distNeg = -dirOrigCenter - cuadratic;

    bool ret;

    if (distPos < 0 || distNeg < 0){
        if (distPos > 0){
            info.time = distPos;
            ret =  true;
        } else if (distNeg > 0){
            info.time =  distNeg;
            ret = true;
        }
    } else {
        if (distPos < distNeg){
            info.time = distPos;
            ret = true;
        }
        else if (distNeg > distPos){
            info.time = distNeg;
            ret = true;
        }
    }

    return ret;
}
// Function glm::dot(x,y) will return the dot product of parameters. (It's the inner product of vectors)

/* TODO: Implementar en el punt 2 */
bool Plane::Intersect(const Ray &ray, IntersectInfo &info) const { return -1.0f; }

/* TODO: Implementar com a extensio */
bool Triangle::Intersect(const Ray &ray, IntersectInfo &info) const { return -1.0f; }
