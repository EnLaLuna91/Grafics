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
uniform Intensity test;

IN vec4 vPosition;
IN vec4 vColor;

OUT vec4 color;



void main()
{
  gl_Position = vPosition;
  color = vec4(test.kd[0], test.kd[1], test.kd[2], 1.0);
//  color = vColor;
}
