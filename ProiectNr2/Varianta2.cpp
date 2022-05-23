#include <iostream>
#include <math.h>
using namespace std;
int a, b, n;

void PrintMenu()
{
    cout << "Alegeti operatia:\n\n";
    cout << "1 - De verificat daca numarul nr este Fibonacci\n";
    cout << "2 - De indicat toate numerele din intervalul [a; b], care sunt Fibonacci\n";
    cout << "3 - De indicat primele n numere, care sunt Fibonacci\n";
    cout << "4 - De indicat toate numerele din intervalul [a; b], care sunt prime Fibonacci\n";
    cout << "5 - De determinat cel mai mare numar, care este Fibonacci\n";
    cout << "* - Exit\n\n";
}

bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s * s == x);
}

bool isFibonacci(int nr)
{
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or both
    // is a perfect square
    return isPerfectSquare(5 * nr * nr + 4) || isPerfectSquare(5 * nr * nr - 4);
}

bool isPrime(int n)
{
    for (int k = 2; k <= n / 2; k++)
    {
        if (n % k == 0)
        {
            return false;
        }
    }
    return true;
}

void CreateRange()
{
    cout << "Indicati intervalul [a; b]\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
}

void CreateRangeWithN()
{
    cout << "Indicati intervalul [a; b]\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "n = ";
    cin >> n;
    cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
}

void FindFibonacciNumbersInRange(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (isFibonacci(i))
            cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este Fibonacci\n\n";
    }
}

void FindFibonacciAndPrimeNumbersInRange(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (isFibonacci(i) && isPrime(i))
            cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este Fibonacci prim\n\n";
    }
}

void FindFirstNFibonacciNumbersInRange(int a, int b, int n)
{
    int count;
    count = 0;
    for (int i = a; i <= b; i++)
    {
        if (count == n)
            break;

        if (isFibonacci(i) && (n != count))
        {
            cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este Fibbonaci\n\n";
            count = count + 1;
        }
    }
}

void FindMaxFibonacciNumberInRange(int a, int b)
{
    int max;
    max = -2, 147, 483, 648;
    for (int i = a; i <= b; i++)
    {
        if (isFibonacci(i))
        {
            if (i > max)
                max = i;
        }
    }
    cout << "Cel mai mare numar care corespunde conditiei este " << max << "\n\n";
}

int main()
{
    cout << "Proiect nr. 2 elaborat de Smoleac Mihai\n";
    cout << "Tema: Numerele Fibonacci\n";
menu:
    PrintMenu();
    int choice;
    int number;
    cout << "Operatia alesa: ";
    cin >> choice;
    cout << "\n";
    switch (choice)
    {
    case 1:
    {
        // 1. De verificat dacă numărul nr este Fibonacci
        int nr;
        cout << "Dati numarul nr: ";
        cin >> nr;
        if (isFibonacci(nr))
            cout << "Numarul " << nr << " este numar al lui Fibonacci";
        else
            cout << "Numarul " << nr << " nu este numar al lui Fibonacci";
        goto menu;
    }
    case 2:
    {
        // 2. De indicat toate numerele din intervalul [a; b], care sunt Fibonacci
        CreateRange();
        FindFibonacciNumbersInRange(a, b);
        goto menu;
    }
    case 3:
    {
        // 3. De indicat primele n numere, care sunt Fibonacci
        CreateRangeWithN();
        FindFirstNFibonacciNumbersInRange(a, b, n);
        goto menu;
    }
    case 4:
    {
        // 4. De indicat toate numerele din intervalul [a; b], care sunt Fibonacci prime
        CreateRange();
        FindFibonacciAndPrimeNumbersInRange(a, b);
        goto menu;
    }
    case 5:
    {
        // 5. De determinat cel mai mare numar, care este Fibonacci
        CreateRange();
        FindMaxFibonacciNumberInRange(a, b);
        goto menu;
    }
    }
}