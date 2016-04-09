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
    float a;
    float b;
    float c;
    int on;
};
uniform Light luz[3];

uniform vec3 vLuzAmbiente;

float calculateAtenuation(int i){

    if (luz[i].tipo == 1){
        return 1.0f;
    }

    float a = luz[i].a;
    float b = luz[i].b;
    float c = luz[i].c;
    float d = length(luz[i].coordenadas.xyz - vPosition.xyz);
    float powD = pow(d, 2.0f);
    float dividendo = (a * powD) + (b * d) + c;

    return 1.0f/dividendo;
}

vec3 calculatePhong(int i){
    vec3 vObs = vec3(0.0f,0.0f,10.0f);
    vec3 V = normalize(vObs - vPosition.xyz);  // Posicion Camara
    vec3 N = vNormal;                   // Normal de vertice
    vec3 L = (luz[i].coordenadas.xyz - vPosition.xyz); // Posicion luz

//    vec3 H = (L+V/length(L+V));                // Vector medio normalizado
    vec3 H = normalize(V+L);
    float LN = dot(L,N);                    // Vector resultante de multiplicar L * N
    float NH = dot(N,H);                    // Vector resultante de multiplicar N * H

    float maxNH = max(NH,0.0);
    float powMax_Shininess = pow(maxNH, IMaterial.shininess);

    vec3 d = (luz[i].difusa * IMaterial.kd) * max(LN,0.0);
    vec3 s = (luz[i].especular * IMaterial.ks) * pow(max(NH,0.0), IMaterial.shininess);
    vec3 a = (luz[i].ambiental * IMaterial.ka);

    return d+s+a;
}

vec3 calculateAmbient(int i){
    vec3 a = (luz[i].ambiental * IMaterial.ka);
    return a;
}

void main()
{
  gl_Position = vPosition;
//  color = vec4(IMaterial.kd[0], IMaterial.kd[1], IMaterial.kd[2], 1.0);
//  color = vec4(luz[0].difusa[0], luz[0].difusa[1], luz[0].difusa[2], 1.0);
//  color = vec4(abs(vNormal.x), abs(vNormal.y), abs(vNormal.z), 1.0);
//  vec3 L = normalize(luz[0].coordenadas.xyz - vPosition.xyz);
//  color = vec4(abs(L.x), abs(L.y), abs(L.z), 1.0);

//  vec3 phong1 = calculatePhong(0);
  vec3 phong1 = calculateAtenuation(0) * calculatePhong(0);
//  vec3 phong2 = calculateAtenuation(1) * calculatePhong(1);
//  vec3 phong3 = calculateAtenuation(2) * calculatePhong(2);

//  vec3 ITotal = calculateAmbient(0) + phong1;
//  vec3 ITotal = (vLuzAmbiente * IMaterial.ka) + phong1 + phong2 + phong3;
  vec3 ITotal = (vLuzAmbiente * IMaterial.ka) + phong1 ;
//  if (ITotal.x > 1.0){
//      ITotal.x = 1.0;
//  }
//  if (ITotal.y > 1.0){
//      ITotal.y = 1.0;
//  }
//  if (ITotal.z > 1.0){
//      ITotal.y = 1.0;
//  }
  v_texcoord = vCoordTexture;
  color = vec4(ITotal, 1.0f);
//  color = vec4(phong1, 1.0f);
}
