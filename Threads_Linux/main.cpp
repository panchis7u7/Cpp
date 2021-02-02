#include <iostream>
#include <thread>
#include <immintrin.h>

void prueba2(){
    std::cout << "Hola desde el thread 2!" << std::endl;
}

int main (){
    std::thread prueba(prueba2);
    prueba.join();
    std::cout << "Hola Mundo!" << std::endl;
    return 0;
}