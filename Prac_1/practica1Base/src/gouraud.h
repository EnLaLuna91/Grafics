#ifndef GOURAUD_H
#define GOURAUD_H

#include <vector>
#include <Common.h>
#include <cara.h>

using namespace std;

typedef vector gouraud;

class Gouraud
{
private:
    gouraud<vec3> normales;
    vector<Cara> caras;
    void calculaNormalGouraud();
public:
    Gouraud();
    Gouraud(vector<Cara> c);
    ~Gouraud();
    void setCaras(vector<Cara> c);
    vec3 getNormalVertex();
};

#endif // GOURAUD_H

