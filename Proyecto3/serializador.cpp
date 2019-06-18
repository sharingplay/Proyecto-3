#include "serializador.h"

serializador::serializador()
{

}
string serializador::serializarMetadata(string meta){
    const char* json = "{\"meta\":\"\"}";
     Document d;
     d.Parse(json);
     d["meta"].SetString(meta.c_str(),sizeof(char)*meta.length());
     StringBuffer buffer;
     Writer<StringBuffer> writer(buffer);
     d.Accept(writer);
     return buffer.GetString();
}
void serializador::deserializarMeta(string json, string* nombre, string* autor, string *creacion, string *descripcion, string *tamano,string *galeria,string *foto_b64, int *id){
    Document d;
    d.Parse(json.c_str());
    *nombre = d["nombre"].GetString();
    *autor = d["autor"].GetString();
    *creacion = d["creacion"].GetString();
    *descripcion = d["ano"].GetString();
    *tamano = d["tamano"].GetString();
    *foto_b64 = d["foto_b64"].GetString();
    *id = d["id"].GetInt();
    *galeria = d["galeria"].GetString();
}
