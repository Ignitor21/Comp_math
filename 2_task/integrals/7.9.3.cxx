#include <iostream>
#include <vector>
#include <utility>

int main()
{
    std::vector<std::pair<double, double>> data = { 
        {-1, -0.333},
        {-0.75, 0},
        {-0.5, -0.125}, 
        {-0.25, -0.056},
        {0, 0},
        {0.25, 0.046},
        {0.5, 0.083},
        {0.75, 0.115},
        {1, 0.143}
    };
    double h = 0.25;
    double integral = 0;

    //Формула трапеции:
    for(int i = 0; i < data.size() - 1; ++i)
    {
        integral += h/2 * (data[i].second + data[i + 1].second);
    }

    std::cout << "Интеграл, взятый с помощью формулы трапеций: " << integral << "\n";

    h = 0.5;
    double new_integral = 0;

    //Погрешность, оцененная с помощью правила Рунге
    for(int i = 0; i < data.size() - 1; i += 2)
    {
        new_integral += h/2 * (data[i].second + data[i + 1].second);
    }

    double epsilon  = (integral - new_integral)/(4 - 1);
    std::cout << "Погрешность вычисление интеграла, оцененная с помощью правила Рунге: " << epsilon << "\n";
    return 0;

}
