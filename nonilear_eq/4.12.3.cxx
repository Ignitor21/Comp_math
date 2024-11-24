#include <iostream>
#include <cmath>

// Ищем положительный корень уравнения: x - x*x*x + 0.1 = 0 с помощью метода простой итерации
// Знаем, что положительный корень больше 1. Будем искать его на отрезке [1, 2]

double formula_1(double x)
{
    return x*x*x - 0.1;
    //Производная равна 3x^2. Минимальное значение производной на [1, 2] равно 3 > 1. Следовательно, нельзя утверждать, что этот метод сойдется
}

double formula_2(double x)
{
    return std::pow(x + 0.1, 1.0/3.0);
    //Производная равна 1/(3*((x + 0.1)^2)^(1/3)). Максимальное  значение производной на [1, 2] не больше 1/3. Следовательно, этот метод сойдется

}

double formula_3(double x)
{
    return (-0.1/(1 - x*x));
    //Производная равна -0.2x/(1-x^2)^2. Производная неограничена на отрезке [1, 2]. Следовательно, нельзя утверждать, что этот метод сойдется
}

double simple_iteration_method(double start, double epsilon, int& count, double (*formula)(double))
{
    double curr = start;
    double prev = start + epsilon + 1;
    count = 0;

    while(std::fabs(curr - prev) >= epsilon)
    {
        prev = curr;
        curr = formula(prev);
        ++count;
    }

    return curr;
}

int main()
{
    const double epsilon = 1e-3;
    int count = 0;
    int start = 1.5; // начальное значение
    double x1 = simple_iteration_method(start, epsilon, count, formula_1); // Метод разошелся
    std::cout << "Корень, полученный первым способом:  x = " << x1 << ". Количество итераций: " << count << "\n";

    double x2 = simple_iteration_method(start, epsilon, count, formula_2); // Метод сошелся к положительному корню
    std::cout << "Корень, полученный вторым способом:  x = " << x2 << ". Количество итераций: " << count << "\n";
    // Оценим количество итераций, необходимое этому методу для достижения точность epsilon = 1e-3 по формуле:
    // n = ln(epsilon/x_start - x_sol)/ln(q), x_sol = 1.046681, q = 1/3. Тогда n = 5.57, окргуляем вверх, получаем 6

    double x3 = simple_iteration_method(start, epsilon, count, formula_3); // Метод сошелся к отрицательному корню
    std::cout << "Корень, полученный третьим способом: x = " << x3 << ". Количество итераций: " << count << "\n";

    return 0;
}
