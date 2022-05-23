#include <iostream>

using namespace std;

int main()
{
    cout << "\nProiect nr. 1 elaborat de Smoleac Mihai\n";
    cout << "Tema: Numere pare\n";
    // De determinat cea mai mică și cea mai mare valoare (valorile minimă și maximă)
    int a, b, max, min;
    int populatie1, populatie2;
    int mici, mari, egale;
    mici = mari = egale = 0;
    cout << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    if (a > b)
    {
        cout << "Cea mai mare valoare este " << a << "\n";
        cout << "Cea mai mica valoare este " << b << "\n";
        max = a;
        min = b;
    }
    else if (a == b)
    {
        cout << "Numerele sunt egale\n";
        max = a;
        min = a;
    }
    else if (a < b)
    {
        cout << "Cea mai mare valoare este " << b << "\n";
        cout << "Cea mai mica valoare este " << a << "\n";
        max = b;
        min = a;
    }

    // De determinat decalajul (diferenta intre valorile minima si maxima)
    cout << "Decalajul este " << max - min << endl;

    // De determinat media valorilor
    float medie = float(a + b) / 2;
    cout << "Media valorilor este " << medie << endl;

    // De determinat numărul de valori, egale, mai mici sau mai mari ca o valoare indicată
    if (populatie1 > 14)
        mari++;
    else if (populatie1 < 14)
        mici++;
    else
        egale++;
    cout << "4.\tNumarul de tari cu populatia mai mica ca " << 14 << ": " << mici << endl;
    cout << "\tNumarul de tari cu populatia egala ca " << 14 << ": " << egale << endl;
    cout << "\tNumarul de tari cu populatia mai mare ca " << 14 << ": " << mari << endl;

    // int n;
    // wrongN:
    // cout << "\nn = "; cin >> n;
    // if((n > 20) || (n < 1))
    // {
    //     cout << "Variabila indicata n nu corepunde conditiilor!";
    //     goto wrongN;
    // }
    return 0;
}