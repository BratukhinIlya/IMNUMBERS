#include <iostream>
#define EPS 1e-10

class ImNumber {
private:
    double real;
    double im;
public:
    ImNumber();
    ImNumber(double real, double im);
    double phi() const;
    ImNumber operator+(const ImNumber& num) const;
    ImNumber operator-(const ImNumber& num) const;
    ImNumber operator*(const ImNumber& num) const;
    ImNumber operator/(const ImNumber& num) const;
    ImNumber& operator-=(const ImNumber& num);
    ImNumber& operator+=(const ImNumber& num);
    ImNumber& operator/=(const ImNumber& num);
    ImNumber& operator*=(const ImNumber& num);
    ImNumber operator!() const;
    bool operator==(const ImNumber& num)const;
    bool operator!=(const ImNumber& num)const;
    bool operator<(const ImNumber& num)const;
    double operator()() const;

    friend std::ostream& operator<<(std::ostream& out, const ImNumber& num);
};

ImNumber::ImNumber() : real(0.0), im(0.0) {}
ImNumber::ImNumber(double real, double im) : real(real), im(im) {}
double ImNumber::phi() const
{
    return atan2(im, real);
}

ImNumber ImNumber::operator+(const ImNumber& num) const
{
    return ImNumber(real + num.real, im + num.im);
}

ImNumber ImNumber::operator-(const ImNumber& num) const
{
    return ImNumber(real - num.real, im - num.im);
}

ImNumber ImNumber::operator*(const ImNumber& num) const
{
    return ImNumber(real * num.real - im * num.im, real * num.im + im * num.real);
}
ImNumber ImNumber::operator/(const ImNumber& num) const
{
    double dm = num.real * num.real + num.im * num.im;
    return ImNumber((real * num.real + im * num.im) / dm, (im * num.real - real * num.im) / dm);
}
ImNumber& ImNumber::operator+=(const ImNumber& num)
{
    real += num.real;
    im += num.im;
    return *this;
}

ImNumber& ImNumber::operator-=(const ImNumber& num)
{
    real -= num.real;
    im -= num.im;
    return *this;
}
ImNumber& ImNumber::operator*=(const ImNumber& num)
{
    double new_real = real * num.real - im * num.im;
    double new_im = real * num.im + im * num.real;
    real = new_real;
    im = new_im;
    return *this;
}

ImNumber& ImNumber::operator/=(const ImNumber& num)
{
    double dm = num.real * num.real + num.im * num.im;
    double new_real = (real * num.real + im * num.im) / dm;
    double new_im = (im * num.real - real * num.im) / dm;
    real = new_real;
    im = new_im;
    return *this;
}

bool ImNumber::operator==(const ImNumber& num)const
{
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}

bool ImNumber::operator<(const ImNumber& num) const
{
    return hypot(real, im) < hypot(num.real, num.im);
}

ImNumber ImNumber::operator!() const
{
    return ImNumber(real, -im);
}

double ImNumber::operator()() const
{
    return hypot(real, im);
}
bool ImNumber::operator!=(const ImNumber& num) const
{
    return !(*this == num);
}
std::ostream& operator<<(std::ostream& os, const ImNumber& num)
{
    os << num.real;
    if (num.im >= 0)
    {
        os << "+i" << num.im;
    }
    else
    {
        os << "-i" << -num.im;
    }
    return os;
}

using namespace std;
int main() {
    ImNumber one(2, 3);
    ImNumber two(1, 2);

    ImNumber Summa = one + two;
    std::cout << "" << Summa << std::endl;

    ImNumber Raznost = one - two;
    std::cout << "" << Raznost << std::endl;

    ImNumber Proizved = one * two;
    std::cout << "" << Proizved << std::endl;

    ImNumber Delenie = one / two;
    cout << "" << Delenie << endl;

    cout << "|one|: " << one() << endl;

    ImNumber Sopryzh = !one;
    cout << "Сопряженное num1: " << Sopryzh << endl;

    if (one == two)
        cout << "one = two" << endl;
    else
        cout << "one != two" << endl;

    if (one < two)
        cout << "|one| < |two|" << endl;
    else
        cout << "|one| >= |two|" << endl;

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
