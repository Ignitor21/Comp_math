#include <iostream>
#include <cmath>

long double calculateEulerConstant(long double precision, size_t max_iterations = 1e10) {
    long double sum = 0.0;
    long double gamma = 0.0;
    long double prev_gamma = -1.0;
    size_t n = 1;

    while (std::fabs(gamma - prev_gamma) > precision && n < max_iterations) {
        sum += 1.0 / n;
        prev_gamma = gamma;
        gamma = sum - std::log(static_cast<long double>(n));

        n++;
    }
    std::cout << n << "\n";
    std::cout << std::log(static_cast<long double>(n)) << "\n";
  
    return gamma;
}

int main() {
    const long double precision = 1e-10;

    long double gamma = calculateEulerConstant(precision);

    std::cout.precision(12);
    std::cout << gamma << std::endl;

    return 0;
}

