#include <fstream>
#include <string>
#include "funciones_cripto.h"
#include <iostream>

int main(int argc, char* argv[]) {
    
    if(argc == 1) {
        Empty();
        exit(EXIT_SUCCESS);
    }

    std::string fichero_entrada{argv[1]};
   
    if(fichero_entrada == "--help") {
        Help();
        exit(EXIT_SUCCESS);
    }

    std::string fichero_salida{argv[2]};
    std::string parameter3{argv[3]};
    std::string password{argv[4]};
    std::string operacion{argv[5]};
    int metodo{stoi(parameter3)};
    std::string filename_entrada{fichero_entrada + ".txt"};
    std::string filename_salida{fichero_salida + ".txt"};

    if(metodo == 1){
        Xor(filename_entrada, filename_salida, password, operacion);
    }
    if(metodo == 2){
        Cesar(filename_entrada, filename_salida, password, operacion);
    }
}