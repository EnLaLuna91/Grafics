#include "BlinnPhong.h"

// BlinnPhong::BlinnPhong(glm::vec3 &_obs, Light *_light, glm::vec3 &_ambientLight):
//     obs(_obs),
//     light(_light),
//     ambient(_ambientLight)
//     {}

BlinnPhong::BlinnPhong(){}

/**
 * [BlinnPhong::obtainBlinnPhong description]
 * Función que calcula el color en base Blinn-Phong, devuevle el color
 * @param  _info [description]
 * @return       [description]
 */
glm::vec3 BlinnPhong::obtainBlinnPhong(IntersectInfo &_info, glm::vec3 &light_coord, glm::vec3 &L){
	this->info = _info;

	// vec3 light_coord = glm::vec3(light->getCoord().x, light->getCoord().y, light->getCoord().z);
	// vec3 L = glm::normalize(light_coord - info.hitPoint);

    vec3 color = /*(ambient * info.material->ambient) +*/ (calculateAtenuation(light_coord) * calculatePhong(L));

	// cout << "color: " << float(color.x) << ", " << float(color.y) << ", " << float(color.z) << endl;

	return color;
}

/**
 * [BlinnPhong::calculatePhong description]
 * Calcula las partes de blinn-phong de d, s y a
 * @param  L [description]
 * @return   [description]
 */
glm::vec3 BlinnPhong::calculatePhong(glm::vec3 L){
	vec3 V = glm::normalize(obs - info.hitPoint);
	vec3 H = glm::normalize(L+V);

	vec3 d = (light->getDifusa() * info.material->diffuse) * max(glm::dot(L, info.normal), 0.0f);
	vec3 s = (light->getSpecular() * info.material->specular) * glm::pow(max(glm::dot(info.normal, H), 0.0f), info.material->shininess);
	vec3 a = (light->getAmbiental() * info.material->ambient);

	return  d+s+a;
}

/**
 * [BlinnPhong::calculateAtenuation description]
 * Calcula la atenuación
 * @param  coord [description]
 * @return       [description]
 */
float BlinnPhong::calculateAtenuation(glm::vec3 coord){
	float d = glm::length(coord - info.hitPoint);
	float dividendo = (light->getA() * glm::pow(d, 2.0f)) + (light->getB() * d) + light->getC();
	return 1.0f/dividendo;
}
