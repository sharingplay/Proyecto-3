#include "serializador.h"
serializador::serializador()
{

}

string serializador::serializar_meta(QString nombre, QString autor, QString creacion, QString descripcion, QString tamano, QString galeria,string foto_b64, int id)
{
     const char* json = "{\"nombre\":\"\","
                        "\"autor\":\"\","
                        "\"creacion\":\"\","
                        "\"descripcion\":\"\","
                        "\"tamano\":\"\","
                        "\"id\":0,"
                        "\"galeria\":\"\","
                        "\"foto_b64\":\"\"}";

     Document d;
     d.Parse(json);
     d["nombre"].SetString(nombre.toUtf8().constData(), sizeof(char)*nombre.length());
     d["autor"].SetString(autor.toUtf8().constData(), sizeof(char)*autor.length());
     d["creacion"].SetString(creacion.toUtf8().constData(), sizeof(char)*creacion.length());
     d["descripcion"].SetString(descripcion.toUtf8().constData(), sizeof(char)*descripcion.length());
     d["galeria"].SetString(galeria.toUtf8().constData(), sizeof(char)*galeria.length());
     d["tamano"].SetString(tamano.toUtf8().constData(), sizeof(char)*tamano.length());
     d["foto_b64"].SetString(foto_b64.c_str(), sizeof(char)*foto_b64.length());
     d["id"].SetInt(id);

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
string serializador::serializarRaid(int id, QString nombre)
{
     const char* json =
                        "{\"id\":0,"
                        "\"nombre\":\"\"}";

     Document d;
     d.Parse(json);
     d["nombre"].SetString(nombre.toUtf8().constData(), sizeof(char)*nombre.length());
     d["id"].SetInt(id);

     StringBuffer buffer;
     Writer<StringBuffer> writer(buffer);
     d.Accept(writer);

     return buffer.GetString();
}
