#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 Position;
IN vec3 Normal;
//IN vec2 v_texcoord;

//uniform sampler2D texMap;

/*
 * Structura para pasar los matereiales
 */
struct Intensity
{
    vec3 kd;
    vec3 ks;
    vec3 ka;
    float shininess;
};
uniform Intensity IMaterial;

/*
 * Structura para pasar las luces
 */
struct Light
{
    vec3 ambiental;
    vec3 especular;
    vec3 difusa;
    vec4 coordenadas;
    vec4 direccion;
    int tipo;
    float angulo;
    float a;
    float b;
    float c;
    bool on;
};
uniform Light luz[3];

/*
 * Uniform para la luz ambiente (Global)
 */
uniform vec3 vLuzAmbiente;


/*
 * Devuelve un color dependiendo la intensidad de la dirección de las normales
 */
vec3 returnColor(float intensity){
    vec3 color = vec3(0.0, 0.0, 0.0);

    if (intensity > 0.95)
        color = vec3(IMaterial.kd * 1.0);
    else if (intensity > 0.5)
        color = vec3(IMaterial.kd * 0.6);
    else if (intensity > 0.25)
        color = vec3(IMaterial.kd * 0.4);
    else
        color = vec3(IMaterial.kd * 0.2);

    return color;
}


/*
 * Calcula si la posición esta dentro del angulo de la luz
 */
bool colorSpotLaight(int i){

    vec3 direcc = normalize(luz[i].coordenadas.xyz - Position.xyz);

    float angulo = dot(luz[i].direccion.xyz, direcc);

    if (angulo > luz[i].angulo)
        return true;

    return false;
}

void main()
{
    vec3 toon1 = vec3(0.0, 0.0, 0.0);
    vec3 toon2 = vec3(0.0, 0.0, 0.0);
    vec3 toon3 = vec3(0.0, 0.0, 0.0);

    // Luz Puntual
    if (luz[0].on == true){
        vec3 dir = normalize(luz[0].coordenadas.xyz - Position.xyz);
        float intensity = dot(dir, normalize(Normal));

        toon1 = returnColor(intensity);
    }

    // Luz Direccional
    if (luz[1].on == true){
        vec3 dir = normalize(luz[1].direccion.xyz - Position.xyz);
        float intensity = dot(dir, normalize(Normal));

        toon2 = returnColor(intensity);
    }

    // Luz SpotLight
    if (luz[2].on == true){
//        vec3 dir = normalize(luz[2].coordenadas.xyz - Position.xyz);
        vec3 dir = normalize(luz[2].direccion.xyz - Position.xyz);
        float intensity = dot(dir, normalize(Normal));

        if (colorSpotLaight(2))
            toon3 = returnColor(intensity);
        else
            toon3 = vLuzAmbiente * IMaterial.ka;
    }

    vec3 color = toon1 + toon2 + toon3;

    gl_FragColor = vec4(color, 1.0);
//    gl_FragColor = vec4((0.25*color + 0.75*texture2D(texMap, v_texcoord)),1.0);
}

