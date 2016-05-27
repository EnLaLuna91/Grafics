#ifndef BLINNPHONG_H
#define BLINNPHONG_H

#include "Object.h"
#include "Light.h"
#include "Ray.h"
#include <vector>

#include <iostream>
#include <stdlib.h>

typedef glm::vec3 vec3;
typedef glm::vec4 vec4;

using namespace std;

class BlinnPhong{
private:
	float calculateAtenuation(glm::vec3 coord);
	glm::vec3 calculatePhong(glm::vec3 L);
protected:
	IntersectInfo info;
	Light *light;
	vec3 obs;
	vec3 ambient;
public:
	BlinnPhong();
	glm::vec3 obtainBlinnPhong(IntersectInfo &_info, glm::vec3 &light_coord, glm::vec3 &L);
	void setObs(glm::vec3 vObs) { obs = vObs; }
	void setLight(Light* luz) { light = luz; }
	void setAmbient(glm::vec3 ambientLight) { ambient = ambientLight; }
};

#endif // BLINNPHONG_H
