#include "Display_Complex.h"

void print_complex(const std::complex<double>& z) {
    std::cout << z.real();
    if (z.imag() < 0) {
        std::cout << " - " << -z.imag() << "j";
    }
    else if (z.imag() > 0) {
        std::cout << " + " << z.imag() << "j";
    }
}