#ifndef SERIALIZADOR_H
#define SERIALIZADOR_H
#include "QDebug"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "string"
using namespace  std;
using namespace rapidjson;
class serializador
{
public:
    static serializador & getInstance(){
        static serializador instance;
        return instance;
    }
    serializador();
    void deserializarMetadata(string json, string *metadata);
    string serializarString(string str);
    string serializar_meta(QString nombre, QString autor, QString creacion, QString descripcion, QString tamano, QString galeria, string foto_b64, int id);
    string serializarRaid(int id, QString nombre);
};

#endif // SERIALIZADOR_H
