#include "Camera.h"

Camera::Camera():
   obs(glm::vec3(-10.0f,10.0f,10.0f)),
    // obs(glm::vec3(0.0f,0.0f,10.0f)),
    // obs(glm::vec3(5.5f,5.5f,18.0f)),
    // obs(glm::vec3(3.0f,3.0f,10.0f)),
    vrp(glm::vec3(0.0f, 0.0f, 0.0f)), // punto donde mira la camara
    vup(glm::vec3(0.0f, 1.0f, 0.0f)), // vector de verticalidad
    angleObertura(45.0f), zNear(1.0f), zFar(1000.0f), // En este caso el obs mira desde el 9 al -990
	// angleObertura(((glm::atan((150/2.0)/glm::length((vrp.x,vrp.y,vrp.z)-obs)))*2)*180/3.14), zNear(1.0f), zFar(1000.0f),
    viewportX(640), viewportY(480), aspect(float(viewportX)/float(viewportY))
{
}

Camera::Camera(const glm::vec3 &_obs,
               const glm::vec3 &_vrp,
               const glm::vec3 &_vup,
               float _angleObertura,
               float _zNear,
               float _zFar,
               int _viewportX,
               int _viewportY):
    obs(_obs), vrp(_vrp), vup(_vup),
    angleObertura(_angleObertura), zNear(_zNear), zFar(_zFar),
    viewportX(_viewportX), viewportY(_viewportY), aspect(float(viewportX)/float(viewportY))
{
}

void Camera::IniViewProjMatrices()
{
	// Inicialització de les matrius viewMatrix i projMatrix
	//	Utilitzeu els metodes de lookAt i perspective
	//  que teniu a  glm.h

	this->viewMatrix = glm::lookAt(this->obs, this->vrp, this->vup);
	this->projMatrix = glm::perspective(this->angleObertura, this->aspect, this->zNear, this->zFar);

}
