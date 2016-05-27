#include "Object.h"

Material::Material():
    ambient(0.2f, 0.2f, 0.2f), // Rojo de la practica anterior
    diffuse(0.8f, 0.0f, 0.0f),
    specular(1.0f, 1.0f, 1.0f),
    shininess(20.0f)
  {}

Material::Material(glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 _specular, float _shininess):
	ambient(_ambient),
	diffuse(_diffuse),
	specular(_specular),
	shininess(_shininess)
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
Sphere::Sphere(glm::vec3 coor, float rad, const Material &material) : Object(glm::mat4(1.0f), material){
	this->centerSphere = coor;
	this->radio = rad;
}

/* TODO: Implementar en el punt 2 */
bool Sphere::Intersect(const Ray &ray, IntersectInfo &info) const {
	//https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection

    float dirOrigCenter = glm::dot( ray.direction, (ray.origin - centerSphere) );
    float module = pow( glm::length(ray.origin - centerSphere) , 2.0f );
    float radCuadratic = pow( radio, 2.0f );
    float intCuadratic = pow( dirOrigCenter, 2.0f ) - module + radCuadratic;

    if (intCuadratic < 0) return false;

    float cuadratic = glm::sqrt( intCuadratic );
    float distPos = -dirOrigCenter + cuadratic;
    float distNeg = -dirOrigCenter - cuadratic;

    bool ret = false;

    // cout << "distPos: " << distPos << "\tdistNeg: " << distNeg << endl;

    if (distPos > 0.0f && distNeg > 0.0f){
        info.time = glm::min(distPos, distNeg);
        ret = true;
    } else if (distPos < 0.0f && distNeg < 0.0f){
		info.time = glm::min(distPos, distNeg);
        ret = false;
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
        info.normal = glm::vec3((info.hitPoint - centerSphere) / float(radio));
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
Plane::Plane(float a0, float b0, float c0, float d0, const Material &material) : Object(glm::mat4(1.0f), material){
	this->a = a0;
	this->b = b0;
	this->c = c0;
	this->d = d0;
}


/* TODO: Implementar en el punt 2 */
bool Plane::Intersect(const Ray &ray, IntersectInfo &info) const {
    glm::vec3 normal = glm::vec3(a,b,c);

    float lambda = -((d + glm::dot(normal,ray.origin))/glm::dot(normal,ray.direction));

    float angulo = glm::dot( ray.direction,normal);
    if(abs(angulo) < EPSILON ) return false;

    if (lambda < 0) return false; // Si el objeto esta por detras, aunque intersecte no nos interesa porque no lo vamos a ver

    info.time = lambda;
    info.hitPoint = glm::vec3(ray.origin + (lambda * ray.direction));
    info.normal = normal;
    return true;
}

Triangle::Triangle(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c, const Material &material) : Object(glm::mat4(1.0f), material){
	this->a = _a;
	this->b = _b;
	this->c = _c;
	generatePlane();
}

Triangle::~Triangle(){
	if (p) delete p;
}

/**
 * [Triangle::generatePlane description]
 * Calcula la normal y genera un nuevo plano para poder usar su intersect,
 * ya que le triangulo vive dentro del plano
 */
void Triangle::generatePlane(){
	// vec3(AB = B-A), vec3(AC = C-A), vec3(normal = AB x AC)
	glm::vec3 normal = glm::normalize(glm::cross((this->b - this->a), (this->c - this->a)));
	// cout << "normal: [" << normal.x << ", " << normal.y << ", " << normal.z << "] "  << endl;
	
	// Calcular la d a partir de un punto del triangulo
	float d = (normal.x * this->a.x) + (normal.y * this->a.y) + (normal.z * this->a.z);

	// Ya que el triangulo es una parte del plano, reutilizamos la formula
	p = new Plane(normal.x, normal.y, normal.z, d);
}

/* TODO: Implementar com a extensio */
bool Triangle::Intersect(const Ray &ray, IntersectInfo &info) const {

	bool ret = false;

	// Si el rayo intersecta con el plano, no quiere decir que
	// intesercte con el triangulo, porque el punto puede estar
	// fuera del triangulo
	if (p->Intersect(ray, info))
		ret = pointExistInTriangle(info);

	return ret;
}

/**
 * [Triangle::pointExistInTriangle description]
 * Comprueba que el punto que estamos comprobando es parte del triangulo
 * @param  info [description]
 * @return      [description]
 */
bool Triangle::pointExistInTriangle(IntersectInfo &info) const{


	glm::vec3 ab = this->b - this->a;
	glm::vec3 bc = this->c - this->b;
	glm::vec3 ca = this->a - this->c;

	glm::vec3 u = info.hitPoint - this->a;
	glm::vec3 w = info.hitPoint - this->b;
	glm::vec3 v = info.hitPoint - this->c;

	return (glm::dot(info.hitPoint, glm::cross(ab, u)) > EPSILON &&
		glm::dot(info.hitPoint, glm::cross(bc,w)) > EPSILON &&
		glm::dot(info.hitPoint, glm::cross(ca,v)) > EPSILON ? true : false);

}
