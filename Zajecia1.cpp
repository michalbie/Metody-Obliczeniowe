#include <iostream>
#include <cmath>

int main() {
	int licznik_bitow_d = 0;
	int licznik_bitow_f = 0;
	float zmienna_f;
	double zmienna_d;

	zmienna_f = 1.f;
	while ((0.5f * zmienna_f + 1.f) > 1.f) {
		zmienna_f *= 0.5f;
		licznik_bitow_f++;
	}

	zmienna_d = 1.0;
	while ((0.5 * zmienna_d + 1.0) > 1.0) {
		zmienna_d *= 0.5;
		licznik_bitow_d++;
	}

	std::cout << "Liczba bitow mantysy dla zmiennej typu float: " << licznik_bitow_f << std::endl;
	std::cout << "Epsilon dla floata: " << zmienna_f << std::endl;
	std::cout << "Epsilon biblioteczny: " << FLT_EPSILON << std::endl << std::endl;

	std::cout << "Liczba bitow mantysy dla zmiennej typu double: " << licznik_bitow_d << std::endl;
	std::cout << "Epsilon dla double: " << zmienna_d << std::endl;
	std::cout << "Epsilon biblioteczny: " << DBL_EPSILON << std::endl;
	return 0;
}
