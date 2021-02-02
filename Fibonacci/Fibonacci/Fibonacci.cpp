#include <iostream>
#include <immintrin.h>
#include <thread>
#include <future>
#include <chrono>

void fibonacciNaive(int);
int fibonacciRecursivo(int);

class Timer {
public:
	Timer()
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop() {
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
		auto duracion = end - start;
		double ms = duracion * 0.001;
		std::cout << duracion << "us ( " << ms << "ms )\n";
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
protected:

};

int main()
{
	//1.- naive method:
	fibonacciNaive(20);
	//2.- recursive method:
	{
		Timer temp;
		fibonacciRecursivo(20);
	}
	return 0;
}

void fibonacciNaive(int iteraciones) {
	//0 1 1 2 3 5 8
	{
		Timer temporizador;
		int a = 0, b = 1;
		int suma = 0;
		for (int i = 0; i < iteraciones; i++)
		{
			suma = a;
			a = b;
			b = suma + a;
			std::cout << suma << " ";
		}
		printf("\n");
	}
}

int fibonacciRecursivo(int iteraciones) {
	if (iteraciones == 0) {
		std::cout << "0 ";
		return 0;https://stackoverflow.com/questions/tagged/fibonacci
	}
	
	fibonacciRecursivo(iteraciones - 1) + fibonacciRecursivo(iteraciones - 2);
	return fibo;
}