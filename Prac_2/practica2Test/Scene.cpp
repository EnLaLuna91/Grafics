#include "Scene.h"

Scene::Scene()
{
    // Afegeix la camera a l'escena
    cam = new Camera();
	inicialiceObjects();
    inicialiceLights();
	phong = new BlinnPhong();
	phong->setObs(cam->obs);
	phong->setAmbient(ambientLight);
}

Scene::~Scene()
{
    delete cam;
    for(unsigned int i = 0; i < objects.size(); ++i){
        if(objects[i]){
            delete objects[i];
        }
    }

	for (int i = 0; i < luces.size(); ++i){
		if(luces[i]) delete luces[i];
	}

	if (phong) delete phong;
}

/**
 * [Scene::inicialiceObjects description]
 * Inicializa los objetos con sus materiales
 */
void Scene::inicialiceObjects(){
	// TODO: Cal crear els objectes de l'escena (punt 2 de l'enunciat)
    // Verde
	Material green(glm::vec3(0.2f, 0.2f, 0.2f), // ambiente
		glm::vec3(0.0f, 1.0f, 0.0f),	// diffusse
		glm::vec3(0.2f, 0.2f, 0.2f),	// specular
		float(20.0f));	// shininess
	// Rojo
	Material red(glm::vec3(0.2f,0.2f,0.2f), // ambiente
		glm::vec3(0.8f,0.0f,0.0f),  // diffusse
		glm::vec3(0.2f,0.2f,0.2f),  // specular
		3.0f); // shininess
	// Azul
	Material blue(glm::vec3(0.2f,0.2f,0.2f), // ambiente
		glm::vec3(0.0f,0.0f,0.8f),  // diffusse
		glm::vec3(0.2f,0.2f,0.2f),	// specular
		3.0f); // shininess
	// Gris Espejo
	Material grayMirror(glm::vec3(0.4f, 0.4f, 0.4f), // ambiente
		glm::vec3(0.4, 0.4f, 0.4f),		// diffusse
		glm::vec3(0.4f, 0.4f, 0.4f),	// specular
		float(20.0f));	 // shininess
	// Negro Espejo
	Material blackMirror(glm::vec3(0.01f, 0.01f, 0.01f), // ambiente
		glm::vec3(0.01f, 0.01f, 0.01f),	// diffusse
		glm::vec3(0.6f, 0.6f, 0.6f),	// specular
		float(20.0f));	// shininess
	// Rosa
	Material pink(glm::vec3(0.2f,0.2f,0.2f),	// ambiente
			glm::vec3(0.98f, 0.04f, 0.7f),  	// diffusse
			glm::vec3(0.2f,0.2f,0.2f), 			// specular
			3.0f);  // shininess
	addObject(new Sphere(glm::vec3(0.0f, 0.0f, -1.0f), 1.5f, green));
	addObject(new Sphere(glm::vec3(0.0f, 5.0f, 1.0f), 0.75f, blue));
	addObject(new Sphere(glm::vec3(3.0f, 4.0f, 1.0f), 1.5f, red));
	addObject(new Plane(0.0f, 1.0f, 0.0f, 4.0f, grayMirror));
	addObject(new Plane(0.0f, 0.0f, 1.0f, 8.0f, blackMirror));
	addObject(new Plane(-1.0f, 0.0f, 0.0f, 8.0f, blackMirror));
	addObject(new Triangle( glm::vec3(3.0f, 2.0f, 0.0f),
		glm::vec3(3.0f, 1.0f, 2.0f),
		glm::vec3(4.0f, 3.0f, 3.0f), pink));
}

/**
 * [Scene::inicialiceLights description]
 * Inicializa las luces
 */
void Scene::inicialiceLights(){
	// TODO: Cal afegir llums a l'escena (punt 4 de l'enunciat)
    addLight(new Light(glm::vec3(0.2f, 0.2f, 0.2f), 	// ambiental
		glm::vec3(0.7f, 0.7f, 0.7f), glm::vec3(0.4f, 0.4f, 0.4f),	// specular, difusa
		glm::vec4(-9.0f, 10.0f, 11.0f, 1.0f), glm::vec4(2.0f, 2.0f, 2.0f, 1.0f), // coord, dir
		0.0f, 0.0f, 1.0f)); // a, b, c
    addLight(new Light(glm::vec3(0.2f, 0.2f, 0.2f),	// ambiental
		glm::vec3(0.65f, 0.65f, 0.65f), glm::vec3(0.5f, 0.5f, 0.5f),	// specular, difusa
		glm::vec4(-25.0f, 9.0f, 11.0f, 1.0f), glm::vec4(2.0f, 2.0f, 2.0f, 1.0f), // coord, dir
		0.0f, 0.0f, 1.0f)); // a, b, c
}

/*
** TODO: Metode que testeja la interseccio contra tots els objectes de l'escena
** la informació sobre la interesccio.
** El metode retorna true si algun objecte es intersecat o false en cas contrari.
**
*/

bool Scene::CheckIntersection(const Ray &ray, IntersectInfo &info) {
	// TODO: Heu de codificar la vostra solucio per aquest metode substituint el 'return true'
    // Una possible solucio es cridar Intersect per a tots els objectes i quedar-se amb la interseccio
    // mes propera a l'observador, en el cas que n'hi hagi més d'una.
    // Cada vegada que s'intersecta un objecte s'ha d'actualitzar el PayLoad del raig,
    // pero no en aquesta funcio. Per això es posa const en el paràmetre ray, per a
    // que no es canvïi aqui.

	// if (intesectLight) cout << "intesectLight: True"  << endl;
	// else cout << "intesectLight: False" << endl;

    bool ret = false;
	IntersectInfo infoMin;
	float lambda = std::numeric_limits<float>::infinity();
    for (int i=0; i<objects.size(); i++){
        if (objects[i]->Intersect(ray,info)){
			if (intesectLight == true && ((info.time >=0.000001f) && (info.time <=1.000001f) ) ) return true;
			if (info.time < lambda) {
				lambda = info.time;
				infoMin.hitPoint = info.hitPoint;
				infoMin.normal = info.normal;
                infoMin.time = info.time;
				infoMin.material = objects[i]->MaterialPtr();
				// cout << "Object_Material: " << infoMin.material->diffuse.x << ", " << infoMin.material->diffuse.y << ", " << infoMin.material->diffuse.z << endl;
				ret = true;
			}
        }
    }

	if (ret){
		info.hitPoint = infoMin.hitPoint;
		info.normal = infoMin.normal;
		info.time = infoMin.time;
		info.material = infoMin.material;
		// cout << "Object_Material: " << info.material->diffuse.x << ", " << info.material->diffuse.y << ", " << info.material->diffuse.z << endl;

	}

    return ret;
}

/*
** TODO: Funcio recursiva del RayTracing.
** A modificar en el punt 4 de l'enunciat per incloure Blinn-Phong  i ombres
** A modificar en el punt 5 per a tractar reflexions
**
** Aquest metode es crida per a cada pixel, i cada cop que es calculen ombres o reflexions
** El paràmetre PayLoad es pot usar per a guardar informacio de sobre el quin es color actual del raig i el nombre de
** rebots que s'han fet.
** Aquest metode retorna el delta del raig (o t) en el cas que hi hagi interseccio o
** -1 si no hi ha interseccio amb cap objecte.
*/
//	La funcio CastRay ha de calcular la il·luminacio,
//  les ombres i les reflexions.

float Scene::CastRay(Ray &ray, Payload &payload) {
	payload.color = castRayRecursive(ray, payload);
	return (payload.color == glm::vec3(0.0f) ? -1.0f : 1.0f);
}

glm::vec3 Scene::castRayRecursive(Ray &ray, Payload &payload){

	glm::vec3 ret = glm::vec3(0.0f);

	if (payload.numBounces <= this->MAX_REFLECT){
		IntersectInfo info;

	    if (CheckIntersection(ray,info)) {
	        /* TODO: Canviar aquesta assignacio pel color basat amb la il.luminacio basada amb Phong-Blinn segons
	         * el material de l'objecte i les llums per l'apartat 4 de la practica
	         * I per l'apartat 5, cal fer que tambe es tinguin en compte els rebots de les reflexions.

	           Inicialment s'ha posat la direccio del raig per tenir un color diferents per a cada pixel pero
	           payload ha d'anar tenint el color actualitzat segons els rebots.
	        */
			glm::vec3 color = sombras(info);

			float c1 = -glm::dot(info.normal, ray.direction);

			glm::vec3 R = glm::vec3((2.0f * c1 * info.normal) + ray.direction);

			Ray rayObject(info.hitPoint + epsilon * R, R);
			IntersectInfo infoReflect;

			// int tmp = payload.numBounces;

			payload.numBounces += 1;
			color = color + info.material->specular * castRayRecursive(rayObject, payload);

			// cout << "Vuelta: " << tmp << "\tColor: [" << color.x << ", " << color.y << ", " << color.z << "]" << endl;

	        ret = color;
	    }
	    else{
	        // Si el ray des de la camera no intersecta amb cap objecte
	        // no s'ha de veure res, encara que també es podria posar el color de la Intensita ambien global
	        ret = glm::vec3(0.0f);
	    }
	}
	return ret;
}

/**
 * [Scene::sombras description]
 * Función que calcula las sombras para cada luz
 * @param  info [description]
 * @return      [description]
 */
glm::vec3 Scene::sombras(IntersectInfo &info){
	glm::vec3 color = (this->ambientLight * info.material->ambient);

	for (int i = 0; i < luces.size(); i++){
		phong->setLight(luces[i]);
		glm::vec3 light_coord = glm::vec3(luces[i]->getCoord().x, luces[i]->getCoord().y, luces[i]->getCoord().z);
		glm::vec3 L = glm::normalize(light_coord - info.hitPoint);
		Ray objectlight(info.hitPoint + epsilon * L, L);
		IntersectInfo infoLight;

		intesectLight = true;
		bool intesecta = CheckIntersection(objectlight, infoLight);
		intesectLight = false;

		if (!intesecta) color += phong->obtainBlinnPhong(info, light_coord, L);
	}
	return color;
}
