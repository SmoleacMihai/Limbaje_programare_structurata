#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int persoana;
    int maxim = 0, minim = 0, decalaj;
    int val, maimic = 0, maimare = 0, egal = 0;
    int limj, lims, res = 0;
    int i = 1;
    int n;
    bool info;
    float media = 0;
    cout << "Proiect Nr.1 elaborat de Adam Denis" << endl;
    cout << "Tema: Vârstele persoanelor dintr-o familie (echipa)" << endl;
    // 0. citirea datelor

    do
    {
        cout << "indica cite persoane doriti sa introduceti: ";
        cin >> n;
    } while ((n < 1) || (n > 20));
    cout << "introduceti valoarea pentru comparatie: ";
    cin >> val;
    cout << "introduceti limitele " << endl;
    cout << "limita de jos: ";
    cin >> limj;
    cout << "limita de sus: ";
    cin >> lims;
    cout << "introduceti virstele persoanelor: " << endl;
    cout << "1 persoana = ";
    cin >> persoana;
    minim = maxim = persoana;
    media += persoana;
    if (persoana < val)
        maimic++;
    else if (persoana > val)
        maimare++;
    else
        egal++;
    if ((persoana >= limj) && (persoana <= lims))
        res++;
    for (i = 2; i <= n; i++)
    {
        cout << i << " persoana = ";
        cin >> persoana;
        if (minim < persoana)
            minim = minim;
        else
            minim = persoana;
        if (maxim > persoana)
            maxim = maxim;
        else
            maxim = persoana;

        media += persoana;
        if (persoana < val)
            maimic++;
        else if (persoana > val)
            maimare++;
        else
            egal++;
        if ((persoana >= limj) && (persoana <= lims))
            res++;
    }

    // 1.	De determinat cea mai mică și cea mai mare valoare (valorile minimă și maximă).
    /*if (persoana1 < persoana2)
    {
        minim = persoana1;
        maxim = persoana2;
    }
    else
    {
        minim = persoana2;
        maxim = persoana1;
    }*/

    // 2.	De determinat decalajul (diferența între valorile minimă și maximă).
    decalaj = maxim - minim;
    // 3.    de determinat media valorilor.
    // media =  (float)(persoana1 + persoana2)/2;
    media = (float)(media / n);
    // 4.	De determinat numărul de valori, egale, mai mici sau mai mari ca o valoare indicată.
    /*if (persoana1 < val ) maimic++;
    else
        if (persoana1 > val) maimare++;
            else egal++;
    if (persoana2 < val ) maimic++;
    else
        if (persoana2 > val) maimare++;
            else egal++; */
    // 5.	De determinat o caracteristică, specifică problemei rezolvate. (nr. de persoane cu vârsta în limitele indicate)
    /*if ((persoana1 >= limj)&&(persoana1 <= lims)) res++;
    if ((persoana2 >= limj)&&(persoana2 <= lims)) res++;*/
    cout << "1.\t virsta maxima este: " << maxim << endl;
    cout << "\t virsta minima este: " << minim << endl;
    cout << "2.\t Decalaju este egal cu: " << decalaj << endl;
    cout << "3.\t Media este egala cu: " << media << endl;
    cout << "4.\t numarul de virste mai mari de cit " << val << " = " << maimare << endl;
    cout << "\t numarul de virste mai mici de cit " << val << " = " << maimic << endl;
    cout << "\t numarul de virste egali cu " << val << " = " << egal << endl;
    cout << "5. \t numarul de virste care apartin limetei [ " << limj << " ; " << lims << " ] = " << res;
    return 0;
}
