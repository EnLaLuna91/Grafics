#include <objecte.h>
#include <readfile.h>


Objecte::Objecte(int npoints, QObject *parent) : numPoints(npoints) ,QObject(parent){
    points = new point4[numPoints];
//    colors = new point4[numPoints];
    mat = new Material;

}

Objecte::Objecte(int npoints, QString n) : numPoints(npoints){
    points = new point4[numPoints];
//    colors = new point4[numPoints];
    mat = new Material;
    readObj(n);
    normales = new vec3[numPoints];
    vertexsTextura = new vec2[numPoints];
    calculaNormal();
//    for (int i=0;i<normalesAcumulada.size();i++){
//        cout << "normalesAcumulada["<<i<<"]: " << normalesAcumulada[i] <<  endl;
//    }
    make();
    initTextura();
}


Objecte::~Objecte(){
    delete points;
//    delete colors;
    delete normales;
}

/**
 * Calcula la normal para vertices
 * @brief Objecte::calculaNormal
 */
void Objecte::calculaNormal(){
    normalesAcumulada.resize(vertexs.size());
    for (unsigned int i=0; i<normalesAcumulada.size();i++)
        normalesAcumulada[i] = vec3(0.0, 0.0, 0.0);

    for (unsigned int i=0; i<cares.size(); i++){
        cares[i].calculaNormal(vertexs);
        vec3 tmpNormal = cares[i].normal;
        for (unsigned int j=0; j<cares[i].idxVertices.size();j++){
//            cout << "cares["<<i<<"].idxVertices["<<j<<"]: " << cares[i].idxVertices[j] <<  endl;
            normalesAcumulada[cares[i].idxVertices[j]] += tmpNormal;
        }
    }

    for (unsigned int i=0; i<normalesAcumulada.size();i++)
        normalesAcumulada[i] = normalize(normalesAcumulada[i]);
}

/**
 * Carga la textura
 * @brief Objecte::initTextura
 */
void Objecte::initTextura()
 {
     qDebug() << "Initializing textures...";
     // Carregar la textura
     glActiveTexture(GL_TEXTURE0);
     texture = new QOpenGLTexture(QImage("://resources/textures/earth1.png"));
     texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
     texture->setMagnificationFilter(QOpenGLTexture::Linear);
     texture->bind(0);
 }

void Objecte::aplicaTG(mat4 m){
    point4  *transformed_points = new point4[Index];

    for ( int i = 0; i < Index; ++i ) {
        transformed_points[i] = m * points[i];
    }

    transformed_points = &transformed_points[0];

    for (int i = 0; i < Index; ++i){
        points[i] = transformed_points[i];
    }

    // Actualitzacio del vertex array per a preparar per pintar
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(point4) * Index,
                     &points[0] );

    delete transformed_points;
}

void Objecte::aplicaTGNormales(mat4 m){
    point4 *transformed_points = new point4[Index];

    for (int i=0; i<Index; ++i)
        transformed_points[i] = m * points[i];

    transformed_points = &transformed_points[0];

    for (int i=0; i<Index; ++i){
        normales[i].x = transformed_points[i].x;
        normales[i].y = transformed_points[i].y;
        normales[i].z = transformed_points[i].z;
    }

    delete transformed_points;

}


/**
 * @brief Objecte::toGPU
 * @param pr
 */
void Objecte::toGPU(QGLShaderProgram *pr) {

    program = pr;
    program->setUniformValue("texMap", 0);
    texture->bind(0);
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    glBufferData( GL_ARRAY_BUFFER, sizeof(point4)*Index + sizeof(vec3)*Index + sizeof(vec2) * Index, NULL, GL_STATIC_DRAW );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_TEXTURE_2D );

}


/**
 * Pintat en la GPU.
 * @brief Objecte::draw
 */
void Objecte::draw(){

    texture->bind(0);
    //GL_ARRAY_BUFFER -> Nombre del buffer donde vas a passar la info


    // Aqui es torna a repetir el pas de dades a la GPU per si hi ha més d'un objecte
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(point4)*Index,  &points[0] );
    //glBufferSubData (Que buffer guardas los datos, que posicion, tamaño informacion a pasar, donde empieza esa infor)

//    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*Index, sizeof(point4)*Index, &colors[0] );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*Index, sizeof(vec3)*Index, &normales[0] );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*Index + sizeof(vec3)*Index ,sizeof(vec2)*Index, vertexsTextura);
    int vertexLocation = program->attributeLocation("vPosition");
//    int colorLocation = program->attributeLocation("vColor");
    int normalLocation = program->attributeLocation("vNormal");
    int coordTextureLocation = program->attributeLocation("vCoordTexture");

    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer("vPosition", GL_FLOAT, 0, 4);
    //program->setAttributeBuffer (que programa se carga, tipo del dato que pasa como "in", donde empieza, dimension)

//    program->enableAttributeArray(colorLocation);
//    program->setAttributeBuffer("vColor", GL_FLOAT, sizeof(point4)*Index, 4);

    program->enableAttributeArray(normalLocation);
    program->setAttributeBuffer("vNormal", GL_FLOAT, sizeof(point4)*Index, 3);

    program->enableAttributeArray(coordTextureLocation);
    program->setAttributeBuffer("vCoordTexture", GL_FLOAT, sizeof(point4)*Index + sizeof(vec3)*Index, 2);


    mat->toGPU(program);


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays( GL_TRIANGLES, 0, Index );
}

void Objecte::make(){
    static vec3  base_colors[] = {
        vec3( 1.0, 0.0, 0.0 ),
        vec3( 0.0, 1.0, 0.0 ),
        vec3( 0.0, 0.0, 1.0 ),
        vec3( 1.0, 1.0, 0.0 )
    };

    Index = 0;
    for(unsigned int i=0; i<cares.size(); i++){
        for(unsigned int j=0; j<cares[i].idxVertices.size(); j++){
            points[Index] = vertexs[cares[i].idxVertices[j]];
//            colors[Index] = vec4(base_colors[j%4], 1.0);
            normales[Index] =  normalesAcumulada[cares[i].idxVertices[j]];

            Index++;
        }
    }
    textures();
}

// Llegeix un fitxer .obj
//  Si el fitxer referencia fitxers de materials (.mtl), encara no es llegeixen
//  Tots els elements del fitxer es llegeixen com a un unic objecte.
void Objecte::readObj(QString filename){

    FILE *fp = fopen(filename.toLocal8Bit(),"rb");
    if (!fp)
    {
        cout << "No puc obrir el fitxer " << endl;
    }
    else {

        while (true)
        {
            char *comment_ptr = ReadFile::fetch_line (fp);

            if (comment_ptr == (char *) -1)  /* end-of-file */
                break;

            /* did we get a comment? */
            if (comment_ptr) {
                //make_comment (comment_ptr);
                continue;
            }

            /* if we get here, the line was not a comment */
            int nwords = ReadFile::fetch_words();

            /* skip empty lines */
            if (nwords == 0)
                continue;

            char *first_word = ReadFile::words[0];

            if (!strcmp (first_word, "v"))
            {
                if (nwords < 4) {
                    fprintf (stderr, "Too few coordinates: '%s'", ReadFile::str_orig);
                    exit (-1);
                }

                QString sx(ReadFile::words[1]);
                QString sy(ReadFile::words[2]);
                QString sz(ReadFile::words[3]);
                double x = sx.toDouble();
                double y = sy.toDouble();
                double z = sz.toDouble();

                if (nwords == 5) {
                    QString sw(ReadFile::words[4]);
                    double w = sw.toDouble();
                    x/=w;
                    y/=w;
                    z/=w;
                }
                // S'afegeix el vertex a l'objecte
                vertexs.push_back(point4(x, y, z, 1));

            }
            else if (!strcmp (first_word, "vn")) {
            }
            else if (!strcmp (first_word, "vt")) {
            }
            else if (!strcmp (first_word, "f")) {
                // S'afegeix la cara a l'objecte
                // A modificar si es vol carregar mes de un objecte
                construeix_cara (&ReadFile::words[1], nwords-1);
            }
            // added
            else if (!strcmp (first_word, "mtllib")) {
                //read_mtllib (&words[1], nwords-1, matlib, filename);
            }
            else if (!strcmp (first_word, "usemtl")) {
                //int size = strlen(words[1])-1;
                //while (size && (words[1][size]=='\n' || words[1][size]=='\r') ) words[1][size--]=0;
                //currentMaterial = matlib.index(words[1]);
            }
            // fadded
            else {
                //fprintf (stderr, "Do not recognize: '%s'\n", str_orig);
            }
        }
    }

}

void Objecte::textures()
{
    float u , v;
//        for(int i=0; i<sizeof(normales); i++){
//            u = 0.5f + (atan2(normales[i].z, normales[i].x) / (2.0f *3.14));
//            v = 0.5f - ((asin(normales[i].y) / 3.14));
//            if(u > 1.0) u = (float)1.0; else if(u < 0.0) u = (float)0.0;
//            if(v > 1.0) v = (float)1.0; else if(v < 0.0) v = (float)0.0;
//            vertexsTextura[i] = vec2(u,v);
//    }


    for(unsigned int i = 0; i < Index; ++i){
        u = 0.5 + (atan2(normales[i].x,normales[i].z)/ (2.0*M_PI));
        v = (0.5 - ((asin(normales[i].y))/ M_PI));

        vertexsTextura[i] = vec2(u,v);
    }
}



void Objecte::construeix_cara ( char **words, int nwords) {
    Cara face;

    for (int i = 0; i < nwords; i++) {
        int vindex;
        int nindex;
        int tindex;

        if ((words[i][0]>='0')&&(words[i][0]<='9')) {
            ReadFile::get_indices (words[i], &vindex, &tindex, &nindex);

#if 0
            printf ("vtn: %d %d %d\n", vindex, tindex, nindex);
#endif

            /* store the vertex index */

            if (vindex > 0)       /* indices are from one, not zero */
                face.idxVertices.push_back(vindex - 1);
            else if (vindex < 0)  /* negative indices mean count backwards */
                face.idxVertices.push_back(this->vertexs.size() + vindex);
            else {
                fprintf (stderr, "Zero indices not allowed: '%s'\n", ReadFile::str_orig);
                exit (-1);
            }
        }
    }
    face.color = vec4(1.0, 0.0, 0.0, 1.0);
    this->cares.push_back(face);
}



