#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif

/*
 * Strucrura para pasar los matereiales
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
    int tipo;
    float angulo;
};
uniform Light luz[3];


IN vec4 vPosition;
IN vec4 vColor;

OUT vec4 color;



void main()
{
  gl_Position = vPosition;
//  color = vec4(IMaterial.kd[0], IMaterial.kd[1], IMaterial.kd[2], 1.0);
  color = vec4(luz[2].especular[0], luz[2].especular[1], luz[2].especular[2], 1.0);
//  color = vColor;
}
