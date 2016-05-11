#include "Scene.h"

Scene::Scene()
{
    // Afegeix la camera a l'escena
    cam = new Camera();
    // TODO: Cal crear els objectes de l'escena (punt 2 de l'enunciat)
    addObject(new Sphere(glm::vec3(0.0f, 0.0f, 0.0f), 0.65f));
	// addObject(new Plane(0.0f, 0.0f, 1.0f, 0.0f));
    // TODO: Cal afegir llums a l'escena (punt 4 de l'enunciat)
    addLight(new Light());
	this->ambientLight = glm::vec3(0.3f, 0.3f, 0.3f);
	phong = new BlinnPhong(cam->obs, getActualLight(), ambientLight);
	
	// cout << "Object_Material: " << getActualObject()->MaterialPtr()->ambient.x << ", " << getActualObject()->MaterialPtr()->ambient.y << ", " << getActualObject()->MaterialPtr()->ambient.z << endl;
	// cout << "Light: " << getActualLight()->getAmbiental().x << ", " << getActualLight()->getAmbiental().y << ", " << getActualLight()->getAmbiental().z << endl;

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
}


/*
** TODO: Metode que testeja la interseccio contra tots els objectes de l'escena
**
** Si un objecte es intersecat pel raig, el parametre  de tipus IntersectInfo conte
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

    bool ret = false;
	IntersectInfo infoMin;
	float lambda = std::numeric_limits<float>::infinity();
    for (int i=0; i<objects.size(); i++){
        if (objects[i]->Intersect(ray,info)){
			if (info.time < lambda) {
				lambda = info.time;
				infoMin.hitPoint = info.hitPoint;
				infoMin.normal = info.normal;
                infoMin.time = info.time;
				infoMin.material = objects[i]->MaterialPtr();
				ret = true;
			}
        }
    }

	if (ret){
		info.hitPoint = infoMin.hitPoint;
		info.normal = infoMin.normal;
		info.time = infoMin.time;
		info.material = info.material;
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

    IntersectInfo info;

    if (CheckIntersection(ray,info)) {
        /* TODO: Canviar aquesta assignacio pel color basat amb la il.luminacio basada amb Phong-Blinn segons
         * el material de l'objecte i les llums per l'apartat 4 de la practica
         * I per l'apartat 5, cal fer que tambe es tinguin en compte els rebots de les reflexions.

           Inicialment s'ha posat la direccio del raig per tenir un color diferents per a cada pixel pero
           payload ha d'anar tenint el color actualitzat segons els rebots.
        */

//        payload.color = glm::vec3(fabs(ray.direction.x),fabs(ray.direction.y),fabs(ray.direction.z)) ;
        // payload.color = glm::vec3(0,1,0);

		glm::vec3 p = glm::vec3( glm::vec3(0.0f, 0.0f, cam->zNear) + (info.hitPoint * ray.direction));
		payload.color = glm::vec3(0,1,0);


        return info.time;
    }
    else{
        payload.color = glm::vec3(0.0f);
        // Si el ray des de la camera no intersecta amb cap objecte
        // no s'ha de veure res, encara que també es podria posar el color de la Intensita ambien global
        return -1.0f;
    }
}
