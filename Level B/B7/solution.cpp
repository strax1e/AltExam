//https://codeforces.com/problemset/problem/338/D

#include <iostream>
#include <algorithm>

typedef long long ll;

// Расширенный алгоритм Евклида
ll extendedGCD(ll a, ll b, ll &x, ll &y);

// Двоичный алгоритм Евклида
ll GCD(ll a, ll b);

// Функция выдачи NO и завершения работы
void NO();

int main()
{
    ll n(0), m(0), x(0), y(0), d(0), Xo(0), U0(0), A[10001] = {0};
    int k(0);
    std::cin >> n >> m >> k >> A[1];
    if (k > n)
        NO();
    Xo = A[1];
    for (int h = 2; h <= k; ++h)
    {
        std::cin >> A[h];
        d = extendedGCD(Xo, A[h], x, y);

        // Выйти, если решения нет (с % НОД(A, b) != 0)
        if ((-h + 1 - U0) % d)
            NO();

        // Вычисление нового частного решения и прибавление его к остальным
        U0 += (x * (-h + 1 - U0) / d) % (A[h] / d) * Xo;

        // НОК c новым модулем
        Xo = Xo / d * A[h];

        // Выйти, если НОК > высоты матрицы (НОК = индекс по высоте)
        if (Xo > n)
            NO();

        // Уход от отрицательного значения по модулю Xo однородного
        U0 = (U0 % Xo + Xo) % Xo;
    }

    // Проверка на нуль индекс в строке. Потому что элементы в кольце начинаются с нуля, а таблица начинается с 1
    if (!U0)
        U0 = Xo;

    // Выйти, если последовательность не вместилась в таблицу
    if (U0 + k - 1 > m)
        NO();

    // Проверка на совпадение последовательности по полученной позиции в строке.
    for (int h = 1; h <= k; ++h)
        if (GCD(Xo, U0 + h - 1) != A[h])
            NO();

    printf("YES");
    return 0;
}

ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll tp = extendedGCD(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * x;
    return tp;
}

ll GCD(ll a, ll b)
{
    ll cnt2(1);
    while (a && b)
    {
        while (!(a & 1) && !(b & 1))
        {
            a >>= 1;
            b >>= 1;
            cnt2 *= 2;
        }
        while (!(a & 1))
            a >>= 1;
        while (!(b & 1))
            b >>= 1;
        if (a < b)
            b -= a;
        else
            a -= b;
    }
    if (!a)
        return b * cnt2;
    else
        return a * cnt2;
}

void NO()
{
    printf("NO");
    exit(0);
}