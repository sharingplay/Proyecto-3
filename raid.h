#ifndef RAIDTRIAL_H
#define RAIDTRIAL_H
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sys/stat.h>

using namespace std;
class RAID {


public:
    static RAID & getInstance(){
        static RAID instance;
        return instance;
    }
static void createDisks(){
    for(int i=1; i<5; i++){
       string diskname = "Disk Number"+to_string(i);
       const char* setter = diskname.c_str();
       if (mkdir(setter, 0777) == -1)
            cout << "Disks already created";
        else
            cout << "Directory created";
    }
}


/**
 * Busca los trozos de un archivo y los une para generar el archivo original que fue almacenado, si esto no es
 * posible por la perdida de un trozo del archivo entonces lo reconstruye y se llama a si misma para completar el
 * proceso. Si se pierde la paridad la recalcula.
 * @param chunkName nombre del archivo que se quiere generar (leer)
 */
static pair<int, char*> read(char *chunkName) {
    string disksPath = "/home/mario/Desktop/proyecto3/proyecto3/build-proyecto3-Desktop_Qt_5_13_0_GCC_64bit-Debug/";
    string fileName;
    char *fileOutput = "tmp";
    // Create our output file
    ofstream outputfile;
    outputfile.open("../" + (string) fileOutput, ios::out | ios::binary);
    if (outputfile.is_open()) {
        bool filefound = true;
        int counter = 1;
        int fileSize = 0;
        int aux = 1;
        vector<char *> parts;
        vector<int> folders = {1, 2, 3, 4};
        vector<int> filef = {1, 2, 3, 4};
        while (filefound) {
            fileName.clear();
            fileName.append(chunkName);
            fileName.append("-");
            char intBuf[10];
            itoa(counter, intBuf, 10);
            fileName.append(intBuf);
            ifstream fileInput;
            if (counter == 4) {
                fileInput.open(disksPath+"Disk Number" + to_string(folders[0]) + "/" + (string) chunkName +".paridad", ios::in | ios::binary);
                cout << "RAID Disk Number" + to_string(folders[0]) + "/" + (string) chunkName +".paridad" << endl;
                if (fileInput.is_open()) {\
                    cout << "Opened RAID Disk Number " + to_string(folders[0]) + "/" + (string) chunkName +".paridad" << endl;
                    folders.pop_back();
                    filef.erase(std::find(filef.begin(), filef.end(), counter));
                    fileSize = getFileSize(&fileInput);
                    cout << "Chunk search finished." << endl;
                    outputfile.close();
                    fileInput.close();
                    if (filef.size() > 1) {
                        cout << "Two disks have failed unexpected." << endl;
                        break;
                    }else if(filef.size() == 1){
                        cout << "Unable to find all chunks of data. RAID Disk Number "<< folders[0] << "has failed." << endl;
                        reconstruir_archivo(to_string(filef[0]), folders[0], chunkName, fileSize,parts);
                        read(chunkName);
                        break;
                    }else{
                        cout << filef.size() << " files left to find." << endl << " Process completed." << endl;
                        outputfile.close();
                        break;
                    }
                }else{
                    if (filef.size() > 1) {
                        cout << "Two disks have failed unexpected." << endl;
                        break;
                    }else{
                       cout << "Unable to find all chunks of data. RAID Disk Number "<< folders[0] << "has failed." << endl;
                        reconstruir_archivo("paridad", folders[0], chunkName, fileSize,parts);
                        cout << "Recalculating paridad." << endl;
                        read(chunkName);
                        break;
                    }
                }
            } else {
                fileInput.open(disksPath+"Disk Number" + to_string(aux) + "/" + (string) fileName.c_str(),
                               ios::in | ios::binary);
                            cout << "Trying to open RAID Disk Number " + to_string(aux) + "/" + (string) fileName.c_str() << endl;
                if (fileInput.is_open()) {
                    cout << "Opened RAID Disk Number " + to_string(aux) + "/" + (string) fileName.c_str() << endl;
                    folders.erase(std::find(folders.begin(), folders.end(), aux));
                    filef.erase(std::find(filef.begin(), filef.end(), counter));
                    filefound = true;
                    fileSize = getFileSize(&fileInput);
                    char *inputBuffer = new char[fileSize];
                    fileInput.read(inputBuffer, fileSize);
                    outputfile.write(inputBuffer, fileSize);
                    parts.push_back(inputBuffer);
                    delete (inputBuffer);
                    fileInput.close();
                    counter++;
                    cout << "Size of folders left to find: " << folders.size() << " and size of parts left: " << parts.size() << endl;
                    aux = 1;
                } else {
                    filefound = true;
                    if (aux == 4) {
                        cout << "Error: File Not Found. " << counter << endl;
                        counter++;
                        aux = 1;
                    } else {
                        aux++;
                    }
                }
            }
        }
        cout << "Success: File Assembly Complete. " << endl;
        ifstream retornable;
        retornable.open("../tmp", ios::in | ios::binary);
        cout << "Opening file: "+(string)chunkName << endl;
        if (retornable.is_open()) {
            int size = getFileSize(&retornable);
            string fullChunkName;
            cout << "File size: " << size << endl;

            // Create a buffer to hold each chunk
            char* retorno = new char[size];

            // Keep reading until end of file
                if (retornable.is_open()) {
                    retornable.read(retorno, size);
                    retornable.close();
                    int pp = 0;
                    pair<int, char*> salida;
                    salida.first = size;

                    salida.second = retorno;
                    return salida;
                }else{
                    cout << "Error: File Not Found." << endl;
                }
        }

    }else { cout << "Error: Unable to open file." << endl; }
}

/**
 * Parte un archivo en tres partes y los almacena en los discos del RAID (carpetas), calcula la paridad basada
 * en las tres parts y el disco restante se utiliza para almacenar el archivo de paridad generado
 * @param imagePath ruta de la imagen que se quiere almacenar
 * @param chunkName nombre del archivo con el que se almacenara
 */
static void write(const char *imagePath, const char *chunkName) {
    string disksPath = "/home/mario/Desktop/proyecto3/proyecto3/build-proyecto3-Desktop_Qt_5_13_0_GCC_64bit-Debug/";
    ifstream fileStream;
    fileStream.open(imagePath, ios::in | ios::binary);
    if (fileStream.is_open()) {
        int chunk_size = (getFileSize(&fileStream) / 3) + 1;
        vector<char *> parts;
        vector<int> diskvec = {1, 2, 3};
        int x=0;
        int chunk = 4;
        ofstream output;
        int counter = 1;
        string fullChunkName;
        char *buffer = new char[chunk_size];
       while (!fileStream.eof()){
            srand(time(NULL) * time(NULL) * time(NULL) * 10);
            fullChunkName.clear();
            fullChunkName.append(chunkName);
            fullChunkName.append("-");
            char intBuf[10];
            itoa(counter, intBuf, 10);
            fullChunkName.append(intBuf);
            // Open new chunk file name for output
            output.open(disksPath+"Disk Number" + to_string(diskvec[x]) +"/" + fullChunkName.c_str(),ios::out | ios::trunc | ios::binary);

           cout << "Random: " << diskvec[x] << ". Chunk number " << counter << " will be saved in"
                << " Disk Number" + to_string(diskvec[x]) + "/" +(string) fullChunkName.c_str() << endl;

           // If chunk file opened successfully, read from input and
            // write to output chunk. Then close.
            x++;
            if (output.is_open()) {
                fileStream.read(buffer, chunk_size);
                parts.push_back(buffer);
                output.write(buffer, fileStream.gcount());
                output.close();
                counter++;
                chunk--;
            }
        }
        delete (buffer);
        fileStream.close();
        cout << "Chunking completed. " << counter - 1 << " files created." << endl;

        char *paridad = new char[chunk_size];
        for (int i = 0; i <= chunk_size; i++) {
            paridad[i] = XOR(parts[0][i], parts[1][i], parts[2][i]);
        }
        ofstream archivo_paridad;
        archivo_paridad.open(disksPath+"Disk Number4/" + (string) chunkName +
                             ".paridad", ios::out | ios::trunc | ios::binary);
        if (archivo_paridad.is_open()) {
            archivo_paridad.write(paridad, chunk_size);
        } else {
            cout << "Couldnt create paridad file" << endl;
        }
        archivo_paridad.close();
        delete (paridad);
    } else {
        cout << "Error opening file" << endl;
    }
}

/**
 *
 * @param chunkName
 */
static void seek(char *chunkName) {
   string disksPath = "/home/mario/Desktop/proyecto3/proyecto3/build-proyecto3-Desktop_Qt_5_13_0_GCC_64bit-Debug/";
   string fileName;
    bool filefound = true;
    int counter = 1;
    int fileSize = 0;
    int counter_aux = 1;
    vector<char *> parts;
    vector<int> folders = {1, 2, 3, 4};
    vector<int> filef = {1, 2, 3, 4};
    while (filefound) {
        fileName.clear();
        fileName.append(chunkName);
        fileName.append("-");
        char intBuf[10];
        itoa(counter, intBuf, 10);
        fileName.append(intBuf);
        ifstream fileInput;
        if (counter == 4) {
            fileInput.open(disksPath+"Disk Number" + to_string(folders[0]) + "/" + (string) chunkName + ".paridad", ios::in | ios::binary);
            if (fileInput.is_open()) {
                folders.pop_back();
                filef.erase(std::find(filef.begin(), filef.end(), counter));
                fileSize = getFileSize(&fileInput);
                char *inputBuffer = new char[fileSize];
                fileInput.read(inputBuffer, fileSize);
                parts.push_back(inputBuffer);
                delete (inputBuffer);
                cout << "Chunk search finished. " << endl;
                fileInput.close();
                if (filef.size() > 1) {
                    cout << "Two disks have failed. "
                         << endl;
                    break;
                } else if (filef.size() == 1) {
                    cout << "Unable to found chunks of data. Disk Number " << folders[0] << " is presenting troubles. Lost file: " << filef[0] << endl;
                    reconstruir_archivo(to_string(filef[0]), folders[0], chunkName,
                                        fileSize, parts);
                    break;
                } else {
                    cout << filef.size() << " files left to find. " << endl;
                    cout << "Success. " << endl;
                    break;
                }
            } else {
                if (filef.size() > 1) {
                    cout << "Two disks have failed. ";
                    break;
                } else {
                     cout << "Unable to found chunks of data. Disk Number " << folders[0] << " is presenting troubles. Lost file is paridad" << endl;
                    reconstruir_archivo("paridad", folders[0], chunkName, fileSize, parts);
                    break;
                }
            }
        } else {
            fileInput.open(disksPath+"Disk Number" + to_string(counter_aux) + "/" + (string) fileName.c_str(),ios::in | ios::binary);
            if (fileInput.is_open()) {
               folders.erase(std::find(folders.begin(), folders.end(), counter_aux));
                filef.erase(std::find(filef.begin(), filef.end(), counter));
                filefound = true;
                fileSize = getFileSize(&fileInput);
                char *inputBuffer = new char[fileSize];
                fileInput.read(inputBuffer, fileSize);
                parts.push_back(inputBuffer);
                delete (inputBuffer);
                fileInput.close();
                counter++;
                counter_aux = 1;
            } else {
                filefound = true;
                if (counter_aux == 4) {
                    cout << "File not found." << endl;
                    counter++;
                    counter_aux = 1;
                } else {
                    counter_aux++;
                }
            }
        }
    }
    cout << "Success. " << endl;

}


/* A utility function to reverse a string  */
/**
*
* @param str
* @param length
*/
static void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        swap(*(str + start), *(str + end));
        start++;
        end--;
    }
}

// converts integer into null-terminated string. It can convert negative numbers too.
/**
*
* @param num
* @param str
* @param base
* @return
*/
static char *itoa(int num, char *str, int base) {
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}


// Simply gets the file size of file.
/**
*
* @param file
* @return
*/
static int getFileSize(ifstream *file) {
    file->seekg(0,ios::end);
    int filesize = file->tellg();
    file->seekg(ios::beg);
    return filesize;
}
/**
*
* @param a
* @param b
* @param c
* @return
*/
static char XOR(char a, char b, char c){
char d = a ^ b ^ c;
return d;
}
/**
*
* @param trozo
* @param carpeta
* @param chunkName
* @param chunk_size
* @param parts
*/
static void reconstruir_archivo(string trozo, int carpeta, char* chunkName, int chunk_size, vector<char*> parts){
    cout << "Se llamo a reconstruir_archivo para el trozo: "+(string)trozo+" en la carpeta (disco): "<< carpeta << "; parts tiene un tamano de: " << parts.size() << endl;
    char* paridad = new char[chunk_size];
    ofstream archivo;
    for(int i = 0; i <= chunk_size; i++){
        paridad[i] = XOR(parts[0][i],parts[1][i],parts[2][i]);
    }
    archivo.open((string)"../RAID/"+to_string(carpeta)+"/"+(string)chunkName+"."+trozo,ios::out | ios::trunc | ios::binary);
    cout << "Estoy guardando archivo reconstruido en: " << (string)"../RAID/"+to_string(carpeta)+"/"+(string)chunkName+"."+trozo << endl;
    if(archivo.is_open()) {
        archivo.write(paridad, chunk_size);
        cout << "Reconstruccion completada" << endl;
    }else{
        cout << "No se logro abrir archivo para la reconstruccion" << endl;
    }
    archivo.close();
    delete(paridad);
}

static void crear_archivo(string nombre, char* buffer, int tam){
    ofstream prueba;
    prueba.open("../tmp", ios::out | ios::trunc | ios::binary);
    prueba.write(buffer,tam);
    char* a = (char*)nombre.c_str();
    write("../tmp",a);
    prueba.close();
}
};


#endif // RAIDTRIAL_H
