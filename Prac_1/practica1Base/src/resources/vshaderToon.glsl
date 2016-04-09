#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif


IN vec4 vPosition;
IN vec3 vNormal;

OUT vec4 Position;
OUT vec3 Normal;

void main()
{
    gl_Position = vPosition;
    Position = vPosition;
    Normal = vNormal;
}
