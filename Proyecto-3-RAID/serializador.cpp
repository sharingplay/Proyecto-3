#include "serializador.h"

serializador::serializador()
{

}
void serializador::deserializarInfo(string json,int *id, string *nombre){
    Document d;
    d.Parse(json.c_str());
    *nombre = d["nombre"].GetString();
    *id = d["id"].GetInt();

}
