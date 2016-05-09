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
Plane::Plane(float a0, float b0, float c0, float d0){
   a=a0;
   b=b0;
   c=c0;
   d=d0;
}

/* TODO: Implementar en el punt 2 */
bool Plane::Intersect(const Ray &ray, IntersectInfo &info) const {
    /*float lambda = -(d + a*ray.origin.x+b*ray.origin.y+c*ray.origin.z)/(a*ray.direction.x+b*ray.direction.y+c*ray.direction.z);
    cout << "lambda: " << lambda << endl;
    if (lambda < 0){
        return false;}
    else {return true;}*/

    glm::vec3 normal = glm::vec3(a,b,c);
    float angulo = glm::dot(ray.direction, normal);
	cout << "angulo: " << angulo << endl;
    if(angulo != 0.f) return true;
    else return false;
}

/* TODO: Implementar com a extensio */
bool Triangle::Intersect(const Ray &ray, IntersectInfo &info) const { return -1.0f; }
