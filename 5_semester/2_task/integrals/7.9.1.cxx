#include <iostream>
#include <vector>
#include <utility>

int main()
{
    std::vector<std::pair<double, double>> data = { 
        {-1, -1},
        {-0.75, -0.14},
        {-0.5, -0.032}, 
        {-0.25, 0.01},
        {0, 0},
        {0.25, 0.002},
        {0.5, 0.003},
        {0.75, 0.0031},
        {1, 0.0029}
    };
    double h = 0.25;
    double integral = 0;

    //Формула Симпсона:
    for(int i = 0; i < data.size() - 1; i += 2)
    {
        integral += h/3 * (data[i].second + 4 * data[i + 1].second + data[i + 2].second);
    }
    std::cout << "Интеграл взятый с помощью формулы Симпсона: " << integral << "\n";


    // Уточняем наш интеграл с помощью экстраполяции Ричардсона
    double new_integral = 0;
    h = 0.5;

    for(int i = 0; i < data.size() - 1; i += 4)
    {
        new_integral += h/3 * (data[i].second + 4 * data[i + 1].second + data[i + 2].second);
    }
    double specified_integral = integral + (integral - new_integral)/(16 - 1);
    std::cout << "Интеграл, уточненный с помощью интерполяции Ричардсона: " << specified_integral << "\n";

    data = { 
        {0, 0},
        {0.25, 0.028},
        {0.5, 0.054}, 
        {0.75, 0.0078},
        {1, 0.1},
        {1.25, 0.2},
        {1.5, 0.133},
        {1.75, 0.145},
        {2, 0.154}
    };
    
    integral = 0;
    h = 0.25;

    //Формула трапеций:
    for(int i = 0; i < data.size() - 1; ++i)
    {
        integral += h/2 * (data[i].second + data[i + 1].second);
    }
    
    std::cout << "Интеграл взятый с помощью формулы трапеций: " << integral << "\n";

    h = 0.5;
    new_integral = 0;

    // Уточняем наш интеграл с помощью экстраполяции Ричардсона
    for(int i = 0; i < data.size() - 1; i += 2)
    {
        new_integral += h/2 * (data[i].second + data[i + 1].second);
    }

    specified_integral = integral + (integral - new_integral)/(4 - 1) ;
    std::cout << "Интеграл, уточненный с помощью интерполяции Ричардсона: " << specified_integral << "\n";

    return 0;
}
