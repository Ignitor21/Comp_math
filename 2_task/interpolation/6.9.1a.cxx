#include <iostream>
#include <vector>
#include <utility>

//Имеем уравнение: x^2 + ln(x) - 4 = 0

int main()
{
    std::vector<std::pair<double, double>> data = {{1.5, -1.345}, {1.6, -0.970}, {1.9, 0.252}, {2, 0.693}};
    std::vector<double> polinoms;
    polinoms.reserve(data.size());
    
    //Воспользуемся интерполяционным многочеленом Лагранжа:
    for (int i = 0; i < data.size(); ++i)
    {
        double polinom = 1;
        for (int j = 0; j < data.size(); ++j)
        {
            if (j != i)
                polinom *= (-1 * data[j].second)/(data[i].second - data[j].second);
        }
        polinoms.push_back(polinom);
    }

    double answer = 0;
    for (int i = 0; i < data.size(); ++i)
    {
        answer += data[i].first * polinoms[i];
    }

    std::cout << "Корень уравнения x^2 + ln(x) - 4 = 0: "; 
    std::cout << "x = " << answer << std::endl;
    // Для оценки погрешности интерполяции воспользуемся формулой 2.11 из задачника:
    // epsilon = (max(f(t)) * max((t + 1.345)(t + 0.970)(t - 0.252)(t - 0.693))) / 4! = 2 * 0.387/24 = 0.032 
    // Максимум ищем на отрезке [-1.345, 0.693]

    return 0;
}
