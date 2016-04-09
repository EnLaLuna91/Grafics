#if __VERSION__<130
#define IN varying
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 color;
IN vec2 v_texcoord;

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
 * Uniform para la imagen
 */
uniform sampler2D texMap;

/*
 * Unifor para activar o desactivar la textura de Gouraud
 */
uniform bool vGouraudTex;

/*
 * Devuelve la texura si hay
 */
vec4 returnTextures(){
    return (vGouraudTex == true ? (0.25*color + 0.75*texture2D(texMap, v_texcoord)): color);
}

void main()
{
    gl_FragColor = returnTextures();
}

