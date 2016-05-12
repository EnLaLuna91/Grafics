#include "BlinnPhong.h"

// BlinnPhong::BlinnPhong(glm::vec3 &_obs, Light *_light, glm::vec3 &_ambientLight):
//     obs(_obs),
//     light(_light),
//     ambient(_ambientLight)
//     {}

BlinnPhong::BlinnPhong(){}

glm::vec3 BlinnPhong::obtainBlinnPhong(IntersectInfo &_info){
	this->info = _info;

	vec3 light_coord = glm::vec3(light->getCoord().x, light->getCoord().y, light->getCoord().z);
	vec3 L = glm::normalize(light_coord - info.hitPoint);

    vec3 color = (ambient * info.material->ambient) + (calculateAtenuation(light_coord) * calculatePhong(L));

	// cout << "color: " << float(color.x) << ", " << float(color.y) << ", " << float(color.z) << endl;

	return color;
}

glm::vec3 BlinnPhong::calculatePhong(glm::vec3 L){
	vec3 V = glm::normalize(obs - info.hitPoint);
	vec3 H = glm::normalize(L+V);

	vec3 d = (light->getDifusa() * info.material->diffuse) * max(glm::dot(L, info.normal), 0.0f);
	vec3 s = (light->getSpecular() * info.material->specular) * glm::pow(max(glm::dot(info.normal, H), 0.0f), info.material->shininess);
	vec3 a = (light->getAmbiental() * info.material->ambient);

	return  d+s+a;
}

float BlinnPhong::calculateAtenuation(glm::vec3 coord){
	float d = glm::length(coord - info.hitPoint);
	float dividendo = (light->getA() * glm::pow(d, 2.0f)) + (light->getB() * d) + light->getC();
	return 1.0f/dividendo;
}
