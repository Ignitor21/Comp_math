#include <iostream>
#include <cmath>
#include <iomanip>

/* 
   С помощью производной можно исселедовать данную функцию и понять, что она имеет три корня, два из которых лежат в окрестности +1 и -1,
   а третий лежит, в окрестности 2. 
*/

double func(double x)
{
    return (0.001*x*x*x*x*x + x*x - 1);
}

double func_derivative(double x)
{
    return (0.005*x*x*x*x + 2*x);
}

double binary_search_solution(double left, double right, double epsilon, bool is_negative_derivative = false)
{
    double curr = (right + left) / 2;
    double ans = is_negative_derivative ? -1 * func(curr) : func(curr);
    // Если отрезок имеет длину меньше 2 * epsilon, то полученный корень будет иметь отклонение не больше epsilon
    while(std::fabs(right - left) >= 2 * epsilon)
    {
        if (ans > 0)
            right = curr;
        else
            left = curr;

        curr = (right + left) / 2;
        ans = is_negative_derivative ? -1 * func(curr) : func(curr);
    }

    return curr;
}

double newton_method_solution(double start, double epsilon)
{
    double curr = start;
    double prev = 0;

    while(std::fabs(curr - prev) >= epsilon)
    {
        prev = curr;
        curr = prev - func(prev)/func_derivative(prev);
    }
    
    return curr;
}


int main()
{
    const double epsilon1 = 0.1;
    double x1 = binary_search_solution(0, 2, epsilon1);
    double x2 = binary_search_solution(-1.5, 0, epsilon1, true);
    double x3 = binary_search_solution(-2, -1.5, epsilon1);
    std::cout << "Корни, полученные  методом бисекции с точностью 0.1:\n";
    std::cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << "\n\n";
    
    const double epsilon2 = 1e-6;
    x1 = newton_method_solution(0.5, epsilon2);
    x2 = newton_method_solution(-1, epsilon2);
    x3 = newton_method_solution(-2, epsilon2);

    std::cout << "Корни, полученные  методом Ньютона с точностью 1e-6:\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "x1 = " << x1 << " x2 = " << x2 << " x3 = " << x3 << "\n\n";
    return 0; 
}

