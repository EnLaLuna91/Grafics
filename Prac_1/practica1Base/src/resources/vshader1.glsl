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
    float a;
    float b;
    float c;
};
uniform Light luz[3];

uniform vec3 vLuzAmbiente;

float calculateAtenuation(int i){

    if (luz[i].tipo == 1){
        return 1.0;
    }

    float a = luz[i].a;
    float b = luz[i].b;
    float c = luz[i].c;
    float d = length(luz[i].coordenadas.xyz - vPosition.xyz);

    return (1.0)/( (a * pow(d,2.0)) + b*d + c );
}

vec3 calculatePhong(int i){
    vec3 V = normalize(vec3(0.0,0.0,10.0) - vPosition.xyz);      // Posicion Camara
    vec3 N = vNormal;                       // Normal de vertice
    vec3 L = normalize(luz[i].coordenadas.xyz - vPosition.xyz);  // Posicion luz
    vec3 H = (V + L)/abs(V + L);            // Vector medio normalizado
    float LN = dot(L,N);                    // Vector resultante de multiplicar L * N
    float NH = dot(N,H);                    // Vector resultante de multiplicar N * H

    return (IMaterial.kd * luz[i].difusa * max(LN,0)) + (IMaterial.ka * luz[i].ambiental) + (IMaterial.ks * luz[i].especular * pow(max(NH,0),IMaterial.shininess));
}

void main()
{
  gl_Position = vPosition;
//  color = vec4(IMaterial.kd[0], IMaterial.kd[1], IMaterial.kd[2], 1.0);
//  color = vec4(luz[0].difusa[0], luz[0].difusa[1], luz[0].difusa[2], 1.0);
//  color = vec4(abs(vNormal.x), abs(vNormal.y), abs(vNormal.z), 1.0);

  vec3 phong1 = calculateAtenuation(0) * calculatePhong(0);
  vec3 phong2 = calculateAtenuation(1) * calculatePhong(1);
  vec3 phong3 = calculateAtenuation(2) * calculatePhong(2);

  vec3 ITotal = (vLuzAmbiente * IMaterial.ka) + phong1 + phong2 + phong3;

  color = vec4(ITotal, 1.0);
}
