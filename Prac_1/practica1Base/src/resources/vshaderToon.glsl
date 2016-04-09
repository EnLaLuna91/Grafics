#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif

IN vec4 vPosition;
//IN vec4 vColor;
IN vec3 vNormal;
IN vec2 vCoordTexture;

OUT vec4 color;
OUT vec2 v_texcoord;

void main()
{
    gl_Position = vPosition;
    Position = vPosition;
    Normal = vNormal;
    v_texcoord = vCoordTexture;
}
