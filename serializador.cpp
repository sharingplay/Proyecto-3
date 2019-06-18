#include "serializador.h"
serializador::serializador()
{

}

string serializador::serializar_meta(QString nombre, QString autor, QString creacion, QString ano, QString tamano, string foto_b64)
{
     const char* json = "{\"nombre\":\"\","
                        "\"autor\":\"\","
                        "\"creacion\":\"\","
                        "\"ano\":\"\","
                        "\"tamano\":\"\","
                        "\"foto_b64\":\"\"}";

     Document d;
     d.Parse(json);
     d["nombre"].SetString(nombre.toUtf8().constData(), sizeof(char)*nombre.length());
     d["autor"].SetString(autor.toUtf8().constData(), sizeof(char)*autor.length());
     d["creacion"].SetString(creacion.toUtf8().constData(), sizeof(char)*creacion.length());
     d["ano"].SetString(ano.toUtf8().constData(), sizeof(char)*ano.length());
     d["tamano"].SetString(tamano.toUtf8().constData(), sizeof(char)*tamano.length());
     d["foto_b64"].SetString(foto_b64.c_str(), sizeof(char)*foto_b64.length());

     StringBuffer buffer;
     Writer<StringBuffer> writer(buffer);
     d.Accept(writer);

     return buffer.GetString();
}
void serializador::deserializarMetadata(string json, string *metadata){
    Document d;
    d.Parse(json.c_str());
    *metadata =d["metadata"].GetString();
}

string serializador::serializarString(string str){
    const char* json = "{\"str\":\"\"}";
    Document d;
    d.Parse(json);
    d["str"].SetString(str.c_str(),sizeof(char)*str.length());
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    return buffer.GetString();
}
