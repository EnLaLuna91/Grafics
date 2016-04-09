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
 * Uniform para la imagen
 */
uniform sampler2D texMap;

/*
 * Unifor para activar o desactivar la textura de Gouraud
 */
uniform bool vGouraudTex;

void main()
{
//    gl_FragColor = color;

    vec4 texturas = vec4(0.0, 0.0, 0.0, 0.0);

    if (vGouraudTex)
        texturas = 0.25*color + 0.75*texture2D(texMap, v_texcoord);
    else
        texturas = color;


    gl_FragColor = texturas;
}

