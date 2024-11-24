#include <cmath>
#include <iostream>
#include <iomanip>

double harmonic_series(unsigned long n)
{
    double ret = 0;

    for(unsigned long i = 1; i <= n; ++i)
        ret += 1.0/i;    

    return ret;
}

double ln(double x, unsigned long n) 
{
    const double e = std::exp(1.0);
    int power_adjust = 0;

    while (x > 1.0) 
    {
        x /= e;
        power_adjust++;
    }

    while (x < 0.25)
    {
        x *= e;
        power_adjust--;
    }
    
    x -= 1.0;
    double t = 0.0, s = 1.0, z = x;

    for (unsigned long k = 1; k <= n; ++k)
    {
        t += z * s / k;
        z *= x;
        s = -s;
    }
    
    return t + power_adjust;
}

int main()
{
    const double right_ans = 0.5772156649;
    const double epsilon = 1e-10;
    double ans = harmonic_series(1) - ln(1, 40);
    double prev_ans = 0;

    // Вычисляем постоянную до тех пор, пока разность между предыдущим значением и текущим не станет меньше 10^(-10)
    std::cout << "ans           n\n"; 
    for (unsigned long n = 2; std::fabs(prev_ans - ans) >= epsilon; n *= 2)
    {
        prev_ans = ans;
        ans  = harmonic_series(n) - ln(n, 40);
        std::cout << std::fixed << std::setprecision(10) << ans << " " << n << "\n";
    }
    
    std::cout << "right answer = " << right_ans << std::endl;

    return 0;
}
