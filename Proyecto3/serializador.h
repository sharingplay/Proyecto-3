#ifndef SERIALIZADOR_H
#define SERIALIZADOR_H
#include "QDebug"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace std;
using namespace rapidjson;

class serializador
{
public:
    static serializador & getInstance(){
        static serializador instance;
        return instance;
    }
    serializador();
    string serializarMetadata(string metadata);
    void deserializarMeta(string json, string *nombre, string *autor, string *creacion, string *ano, string *tamano,string *galeria, string *foto_b64, int* id);
};

#endif // SERIALIZADOR_H
