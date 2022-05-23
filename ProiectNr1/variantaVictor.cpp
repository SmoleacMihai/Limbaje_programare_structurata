#include <iostream>

using namespace std;

int main(){
    int n = 2;
    int populatie1, populatie2;
    int maxim, minim, decalaj;
    float media;
    int PopMedie = 10;
    int mici, mari, egale;
    mici = mari = egale = 0;
    cout << "\nProiect nr. 1 elaborat de Smoleac Mihai\n";
    cout << "Tema: Temperaturile intro luna calindaristica";
    // 0.  Citirea datelor
    cout << "Indicati populatia a 2 tari (in milioane rotungite): ";
    cin >> populatie1;
    cin >> populatie2;
    // 1. De determinat cea mai mica si cea mai mare populatie
    if(populatie1 > populatie2) {
        maxim = populatie1;
        minim = populatie2;
    } else {
        maxim = populatie2;
        minim = populatie1;
    }

    // 2. De determinat decalajul;
    decalaj = maxim - minim;

    // 3. De determinat media
    media = float (populatie1 + populatie2) / 2;

    // 4. De determinat de valori, egale, mai mici sau mai mari ca o valoare indicata
    if (populatie1 > PopMedie) mari++;
    else if(populatie1 < PopMedie) mici++;
    else egale++;

    cout << "1.\tPopulatia maxima este: " << maxim << endl;
    cout << "\tPopulatia minima este: " << minim << endl;
    cout << "2.\tDecalajul de populatie este: " << decalaj << endl;
    cout << "3.\tMedia populatiei este: " << media << endl;
    cout << "4.\tNumarul de tari cu populatia mai mica ca " << PopMedie << ": " << mici << endl;
    cout << "4.\tNumarul de tari cu populatia egala ca " << PopMedie << ": " << egale << endl;
    cout << "4.\tNumarul de tari cu populatia mai mare ca " << PopMedie << ": " << mari << endl;
    return 0;
}