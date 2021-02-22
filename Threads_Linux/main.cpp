#include <iostream>
#include <thread>
#include <immintrin.h>
#include <curl/curl.h>

auto Color(int n, const std::string& s) { 
    return "\33[38;5;"+std::to_string(n)+'m'+s+"\33[m"; 
    }

void prueba2(){
    std::cout << "Hola desde el thread 2!" << std::endl;
}

int main (){
    std::thread prueba(prueba2);
    prueba.join();
    std::cout << Color(0, "Hola Mundo!") << std::endl;
    return 0;
}