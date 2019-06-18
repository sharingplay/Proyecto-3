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
    string serializar_meta(QString nombre, QString autor, QString creacion, QString ano, QString tamano, string foto_b64);
    void deserializarInfo(string json, int *id, string *nombre);
};

#endif // SERIALIZADOR_H
