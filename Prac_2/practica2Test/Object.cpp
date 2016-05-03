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

/**
 * @brief Sphere::Sphere
 * Constructor Sphere
 * @param coor
 * @param rad
 */
Sphere::Sphere(glm::vec3 coor, float rad){
    centerSphere = coor;
    radio = rad;
}

/* TODO: Implementar en el punt 2 */
bool Sphere::Intersect(const Ray &ray, IntersectInfo &info) const {

    float dirOrigCenter = glm::dot( ray.direction, (ray.origin - centerSphere) );
    float module = pow( glm::length(ray.origin - centerSphere) , 2.0f );
    float radCuadratic = pow( radio, 2.0f );
    float intCuadratic = pow( dirOrigCenter, 2.0f ) - module + radCuadratic;

    if (intCuadratic < 0) return false;

    float cuadratic = glm::sqrt( intCuadratic );
    float distPos = -dirOrigCenter + cuadratic;
    float distNeg = -dirOrigCenter - cuadratic;

    bool ret = false;

//    cout << "distPos: " << distPos << "\tdistNeg: " << distNeg << endl;

    if ((distPos && distNeg) > 0){
        info.time = glm::min(distPos, distNeg);
        ret = true;
    } else {
        if (distPos < 0){
            info.time = distNeg;
            ret = true;
        } else if (distNeg < 0) {
            info.time = distPos;
            ret = true;
        }
    }

    if (ret){
        info.hitPoint = glm::vec3(ray.origin + (info.time * ray.direction));
        info.normal = glm::vec3((info.hitPoint - centerSphere) / radio);
    }


    return ret;
}
// Function glm::dot(x,y) will return the dot product of parameters. (It's the inner product of vectors)

/**
 * @brief Plane::Plane
 * Constructor Plane
 * @param vX
 * @param vY
 * @param p
 */
Plane::Plane(glm::vec3 vX, glm::vec3 vY, glm::vec3 p){
	vecX = vX;
	vecY = vY;
	point = p;
}

/* TODO: Implementar en el punt 2 */
bool Plane::Intersect(const Ray &ray, IntersectInfo &info) const {

	return -1.0f;
}

/* TODO: Implementar com a extensio */
bool Triangle::Intersect(const Ray &ray, IntersectInfo &info) const { return -1.0f; }
