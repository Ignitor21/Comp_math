#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>

float naive_exp(float arg)
{
    float sum = 1;
    float term = 1;

    for(int i = 1; sum + term != sum; ++i)
    {
        term *= arg/i;
        sum += term;
    }

    return sum;
}

/*
    Как можно заметить, экспонента от отрицательного аргумента тоже становится отрицательной, чего быть не должно,
    так как эксопнента всегда > 0. Это происходит из-за того, что в ряде Тейлора появляются отрицательные члены, 
    которые спустя некоторе количество итераций начинают становится по модулю больше, чем положительные члены.
    Чтобы такого эффекта не наблюдалось, можно представить экспоненту отрицательного аргумента следующим образом:
    exp(-a) = 1/exp(a) и сначала вычислить exp(a) и найти обратное число.
*/

int main()
{
    std::vector<float> exp_arg = {1, 5, 10, 15, 20, 25, -1, -5, -10, -15, -20, -25};
    
    std::cout << std::setw(4) << "x" << std::setw(21) << "naive exp(x)" << std::setw(21) << "cmath exp(x)" << "\n";

    for(const auto& x : exp_arg)
    {
        float naive_ans = naive_exp(x);
        float cmath_ans = exp(x);
        std::cout << std::setw(4) << std::fixed << std::setprecision(0) << x << " " << std::setw(20) << std::setprecision(8) 
            << naive_ans << " " << std::setw(20) << cmath_ans << "\n";
    }

    return 0;
}



