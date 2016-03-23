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

OUT vec4 color;


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
    vec4 direccion;
    int tipo;
    float angulo;    
};
uniform Light luz[3];

uniform vec3 vLuzAmbiente;


void main()
{
  gl_Position = vPosition;
//  color = vec4(IMaterial.kd[0], IMaterial.kd[1], IMaterial.kd[2], 1.0);
//  color = vec4(luz[0].difusa[0], luz[0].difusa[1], luz[0].difusa[2], 1.0);
//  color = vec4(abs(vNormal.x), abs(vNormal.y), abs(vNormal.z), 1.0);



  vec3 V = normalize(vec3(0.0,0.0,10.0) - vPosition.xyz);      // Posicion Camara
  vec3 N = vNormal;                 // Normal de vertice
  vec3 L = normalize(luz[2].coordenadas.xyz - vPosition.xyz);  // Posicion luz
  vec3 H = (V + L)/abs(V + L);      // Vector medio normalizado
  vec3 LN = L*N;                    // Vector resultante de multiplicar L * N
  vec3 NH = N*H;                    // Vector resultante de multiplicar N * H
//  vec3 NH_2 = dot(N*H, IMaterial.shininess);    // Vector resultante de multiplicar (N * H)^shininess

  float Ir = 0.0;
  float Ib = 0.0;
  float Ig = 0.0;

  vec3 phong1 = (IMaterial.kd * luz[0].difusa * LN) + (IMaterial.ka * luz[0].ambiental) + (IMaterial.ks * luz[0].especular * NH);
  vec3 phong2 = (IMaterial.kd * luz[1].difusa * LN) + (IMaterial.ka * luz[1].ambiental) + (IMaterial.ks * luz[1].especular * NH);
  vec3 phong3 = (IMaterial.kd * luz[2].difusa * LN) + (IMaterial.ka * luz[2].ambiental) + (IMaterial.ks * luz[2].especular * NH);

  vec3 ITotal = vLuzAmbiente + phong1 + phong2 + phong3;

//  Ir = (IMaterial.kd[0] * luz[0].difusa[0] * LN) + (IMaterial.ka[0] * luz[0].ambiental[0]) + (IMaterial.ks[0] * luz[0].especular[0] * NH);
//  Ig = (IMaterial.kd[1] * luz[0].difusa[1] * LN) + (IMaterial.ka[1] * luz[0].ambiental[1]) + (IMaterial.ks[1] * luz[0].especular[1] * NH^IMaterial.shininess);
//  Ib = (IMaterial.kd[2] * luz[0].difusa[2] * LN) + (IMaterial.ka[2] * luz[0].ambiental[2]) + (IMaterial.ks[2] * luz[0].especular[2] * NH^IMaterial.shininess);

  color = vec4(ITotal, 1.0);
}
