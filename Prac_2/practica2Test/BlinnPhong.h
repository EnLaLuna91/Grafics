#ifndef BLINNPHONG_H
#define BLINNPHONG_H

#include "Camera.h"
#include "Object.h"
#include "Light.h"
#include "Ray.h"
#include <vector>

typedef glm::vec3 vec3;
typedef glm::vec4 vec4;

class BlinnPhong{
private:
	float calculateAtenuation(glm::vec3 coord);
	glm::vec3 calculatePhong(glm::vec3 L);
	Ray ray;
	IntersectInfo info;
	Light light;
	vec3 obs;
	glm::vec3 ambient;
public:
    BlinnPhong(const glm::vec3 &_obs,
		const Light &_light,
		const glm::vec3 &_ambientLight);
	glm::vec3 obtainBlinnPhong(const IntersectInfo &_info);
};

#endif // BLINNPHONG_H
