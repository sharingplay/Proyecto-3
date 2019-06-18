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
    serializador();
    string serializar_meta(QString nombre, QString autor, QString creacion, QString ano, QString tamano, string foto_b64);
    void deserializarMetadata(string json, string *metadata);
    string serializarString(string str);
};

#endif // SERIALIZADOR_H
