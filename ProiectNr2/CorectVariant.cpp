#include <iostream>
#include <iomanip>
#include <conio.h>
#define NMAX -2147483647
using namespace std;

bool Par(int nr)
{
    return (nr % 2 == 0);
}

bool ParOptimizat(int n)
{
    return (!(n & 1));
}

// bool Impar(int nr)
// {
//     return (nr % 2 != 0);
// }

bool ParPrinImpar(int n)
{
    return (!(n % 2 != 0));
}

int main()
{
    int a, b, n, nr, maxim = NMAX, minim;
    int count = 0, optiune;

    do
    {
        system("cls");
        cout << "Proiect nr.2 elaborat de Smoleac Mihai" << endl;
        cout << "Tema: Temperatura" << endl;

        cout << "1. De verificat daca numarul nr satisface proprietatea de baza\n";
        cout << "2. De afisat numerele din intervalul care corespund proprietatii de baza\n";
        cout << "3. De afisat primele n numere care corespund proprietatii de baza\n";
        cout << "4. De afisat numerele din intervalul propus, care corespund proprietatii de baza(varianta optimizata)\n";
        cout << "5. De afisat numarul maxim din interval\n";
        cout << "0. Iesire" << endl;
        cout << "\n\n\t Alege o optiune de la 0 la 5 -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            cout << "nr = ";
            cin >> nr;
            if (Par(nr))
            {
                cout << "nr este par\n\n";
            }
            else
                cout << "nr este impar\n\n";
            break;
        case 2:
            cout << "Indicati intervalul [a; b]\n";
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
            if (b < a)
            {
                for (int i = a; i >= b; i--)
                {
                    if (Par(i))
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                }
            }
            else
            {
                for (int i = a; i <= b; i++)
                {
                    if (Par(i))
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                }
            }
            break;
        case 3:
            cout << "Indicati intervalul [a; b]\n";
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "n = ";
            cin >> n;
            cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
            if (b < a)
            {
                for (int i = a; i >= b; i--)
                {
                    if (Par(i) && (n != count))
                    {
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                        count = count + 1;
                    }
                }
            }
            else
            {
                for (int i = a; i <= b; i++)
                {
                    if (Par(i) && (n != count))
                    {
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                        count = count + 1;
                    }
                }
            }
            break;
        case 4:
            cout << "Indicati intervalul [a; b]\n";
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
            if (b < a)
            {
                if (ParOptimizat(a))
                {
                    for (int i = a; i >= b; i -= 2)
                    {
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                    }
                }
                else
                {
                    for (int i = a - 1; i >= b; i -= 2)
                    {
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                    }
                }
            }
            else
            {
                if (ParOptimizat(a))
                {
                    for (int i = a; i <= b; i += 2)
                    {
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                    }
                }
                else
                {
                    for (int i = a + 1; i <= b; i += 2)
                    {
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                    }
                }
            }
            break;
        case 5:
            int opt;
            cout << "Indicati individual ?\n";
            cout << "1.Da\n2.Nu\nAlege -> ";
            cin >> opt;
            if (opt == 1)
            {
                cout << "Indicati intervalul [a; b]\n";
                cout << "a = ";
                cin >> a;
                cout << "b = ";
                cin >> b;
                cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
                if (b < a)
                {
                    for (int i = a; i >= b; i--)
                    {
                        if (ParOptimizat(i))
                            cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                        if (i > maxim)
                            maxim = i;
                    }
                }
                else
                {
                    for (int i = a; i <= b; i++)
                    {
                        if (ParOptimizat(i))
                            cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                        if (i > maxim)
                            maxim = i;
                    }
                }
                cout << "\n\nCel mai mare numar din intervalul dat este " << maxim;
                break;
            };
            if (opt == 2)
            {
                a = NMAX;
                b = -NMAX;

                for (int i = a; i <= b; i++)
                {
                    if (ParOptimizat(i))
                        cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n";
                    if (i > maxim)
                        maxim = i;
                }
                break;
            }
        }
        _getch();
    } while (optiune);
    return 0;
}

// bool Divizibil(int n, int k)
// {
//     return (n % k == 0);
// }

// bool Prim(int n)
// {
//     for (int k = 2; k <= n / 2; k++)
//     {
//         if (n % k == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// bool Lucas(int n)
// {
//     if ((n = 1) || (n == 3))
//         return true;
//     int a = 1, b = 3, c;
//     c = a + b;
//     while (c < n)
//     {
//         a = b;
//         b = c;
//         c = a + b;
//     }
//     return c == n;
// }

// void CreateRange()
// {
//     cout << "Indicati intervalul [a; b]\n";
//     cout << "a = ";
//     cin >> a;
//     cout << "b = ";
//     cin >> b;
//     cout << "Intervalul propus este [" << a << "; " << b << "]\n\n";
// }

// void FindFirstNEvenNumbersInRange(int a, int b, int n)
// {
//
//     if (b < a)
//     {
//         for (int i = a; i >= b; i--)
//         {
//             if (count == n)
//                 break;

//             if (Par(i) && (n != count))
//             {
//                 cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n\n";
//                 count = count + 1;
//             }
//         }
//     }
//     else
//     {
//         for (int i = a; i <= b; i++)
//         {
//             if (count == n)
//                 break;

//             if (Par(i) && (n != count))
//             {
//                 cout << "Numarul " << i << " din intervalul [" << a << "; " << b << "] este par\n\n";
//                 count = count + 1;
//             }
//         }
//     }
// }

// void FindMaxEvenNumberInRange(int a, int b)
// {
//     int max;
//     max = -NMAX;

//     if (b < a)
//     {
//         for (int i = a; i >= b; i--)
//         {
//             if (ParOptimizat(i))
//             {
//                 if (i > max)
//                     max = i;
//             }
//         }
//     }
//     else
//     {
//         for (int i = a; i <= b; i++)
//         {
//             if (ParOptimizat(i))
//             {
//                 if (i > max)
//                     max = i;
//             }
//         }
//     }

//     cout << "Cel mai mare numar care corespunde conditiei este " << max << "\n\n";
// }

// void FindMinEvenNumberInRange(int a, int b)
// {

//     if (b < a)
//     {
//         for (int i = a; i >= b; i--)
//         {
//             if (Par(i))
//             {
//                 if (i < min)
//                     min = i;
//             }
//         }
//     }
//     else
//     {
//         for (int i = a; i <= b; i++)
//         {
//             if (Par(i))
//             {
//                 if (i < min)
//                     min = i;
//             }
//         }
//     }

//     cout << "Cel mai mic numar care corespunde conditiei este " << min << "\n\n"