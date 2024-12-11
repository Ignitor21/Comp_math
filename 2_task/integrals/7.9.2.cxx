#include <iostream>
#include <vector>
#include <utility>

int main()
{
    std::vector<std::pair<double, double>> data = { 
        {0, 0},
        {0.25, 0.004},
        {0.5, 0.015}, 
        {0.75, 0.034},
        {1.0, 0.059},
        {1.25, 0.089},
        {1.5, 0.123},
        {1.75, 0.3},
        {2, 0.2}
    };
    double h = 0.25;
    double integral = 0;

    //Формула Симпсона:
    for(int i = 0; i < data.size() - 1; i += 2)
    {
        integral += h/3 * (data[i].second + 4 * data[i + 1].second + data[i + 2].second);
    }
    std::cout << "Интеграл, взятый с помощью формулы Симпсона: " << integral << "\n";
    
    //Погрешность, оцененная с помощью правила Рунге  
    double new_integral = 0;
    h = 0.5;

    for(int i = 0; i < data.size() - 1; i += 4)
    {
        new_integral += h/3 * (data[i].second + 4 * data[i + 1].second + data[i + 2].second);
    }

    double epsilon  = (integral - new_integral)/(16 - 1);
    std::cout << "Погрешность вычисление интеграла, оцененная с помощью правила Рунге: " << epsilon << "\n";
    return 0;
}
