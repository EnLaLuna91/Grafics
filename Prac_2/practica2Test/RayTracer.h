#ifndef RayTracer_h

#define RayTracer_h

#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>

#include <GL/glut.h> //OpenGL Utility Toolkits

#include "Scene.h"

using namespace std;

Scene *scene;

void Render();

#endif
