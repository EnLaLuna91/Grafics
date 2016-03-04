#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif

struct Intensity
{
    vec3 kd;
    vec3 ks;
    vec3 ka;
    float shininess;
};
uniform Intensity IMaterial;

IN vec4 vPosition;
IN vec4 vColor;


OUT vec4 color;


void main()
{
  gl_Position = vPosition;
//  color = vColor;
  color = vec4(Intensity.kd[0], Intensity.kd[1], Intensity.kd[2], 1.0);
  // Pas de les coordenades de textura al fragment shader
  // El valor del color i les coordenades de textura s'interpolaran automaticament
  // en els fragments interiors a les cares dels polígons
//  v_texcoord = vCoordTexture;
}
