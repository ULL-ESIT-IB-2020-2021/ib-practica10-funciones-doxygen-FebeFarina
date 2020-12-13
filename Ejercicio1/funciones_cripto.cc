#include <iostream>
#include <fstream>

void Empty() {
    std::cout << "./cripto -- Cifrado de ficheros" << std::endl;
    std::cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl;
    std::cout << "Pruebe ./cripto --help para más información" << std::endl;
}

void Help() {
    std::cout << "./cripto -- Cifrado de ficheros"<< std::endl;
    std::cout << "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl << std::endl;
    std::cout << "fichero_entrada: Fichero a codificar" << std::endl; 
    std::cout << "fichero_salida: Fichero codificado" << std::endl; 
    std::cout << "método: Indica el método de encriptado" << std::endl;
    std::cout << "    1: Cifrado xor" << std::endl << "    2: Cifrado de César" << std::endl;
    std::cout << "password: Palabra secreta en el caso de método 1, Valor de k en el método 2" << std::endl;
    std::cout << "operación: Operación a realizar en el fichero" << std::endl;
    std::cout << "    +: encriptar el fichero" << std::endl << "    -:desenctiptar el fichero" << std::endl;
}

void Cesar(std::string fichero_entrada, std::string fichero_salida, std::string password, std::string operador){
    std::ifstream input_file (fichero_entrada, std::ifstream::in);
    std::ofstream output_file (fichero_salida, std::ofstream::out);
    int cesar_number{stoi(password)};
    while(cesar_number > 25) {
        cesar_number -= 25;
    }

    if (operador == "+") {
        std::string line;
        while(getline(input_file,line)) {
            for(size_t i = 0; i < line.size(); ++i) {
                if (line[i] != ' ') {
                    line[i] += cesar_number;
                }
            }
            output_file << line << "\n";
        }
    }
    if (operador == "-") {
        std::string line;
        while(getline(input_file,line)) {
            for(size_t i = 0; i < line.size(); ++i) {
                if (line[i] != ' ') {
                    line [i] -= cesar_number;
                }
               
            }
            output_file << line << "\n";
        }
    }
}

void Xor(std::string fichero_entrada, std::string fichero_salida, std::string password, std::string operador){
    std::cout << "Estamos trabajando en ello" << std::endl;
}
