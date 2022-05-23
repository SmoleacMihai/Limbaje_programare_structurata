#include <iostream>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

#define LMAX 251
using namespace std;
// interfata
int NrCuvinte(char sir[]);
int Cuvintele(char sir[]);
int CuvinteLungMin5(char sir[]);
int NrCuvinte();
int Cuvintele();
int CuvinteLungMin5();
int TransferCuvinteLungMin5(char sir[]);
int EliminaCuvinteLungMin5(char sir[]);
void ViewFile(char nume[]);
void CopiaRezerva(char nume[]);

int main()
{
    int opt;
    int n = 0;
    char fraza[251] = "Doctorul Varlaamov, fiind un om de stiinta, era pasionat de reexaminarea fiintelor preistorice.";
    cout << "\n\nProiect nr.5 elaborat de Frasiniuc Ilona" << endl;
    cout << "Tema: Sir" << endl;
    do
    {
        // sistem("cls")
        cout << "\n1. Numarul de cuvinte dintr-o fraza";
        cout << "\n2. Cuvintele cu litere duble (aceleasi 2 litere consecutive) dintr-o fraza";
        cout << "\n3. Cuvintele de lungime cel putin 5 litere dintro fraza";
        cout << "\n4. Numarul de cuvinte dintr-un fisier";
        cout << "\n5. Cuvintele cu litere duble (aceleasi 2 litere consecutive) dintr-un fisier";
        cout << "\n6. Cuvinte de lungime cel putin 5 litere dintr-un fisier";
        cout << "\n7. De scris in alt fisier cuvinte de lungime cel putin 5 litere dintr-un fisier";
        cout << "\n8. De sters cuvinte de lungime cel putin 5 litere dintr-un fisier";
        cout << "\n9. Copia de rezerva a fisierului";
        cout << "\n0. Stop";
        cout << "\n\n\t Alege (de la 0 la 8) ->";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "Fraza inintiala\n";
            puts(fraza);
            if (n = NrCuvinte(fraza))
                cout << "in total " << n << " cuvinte\n";
            else
                cout << "Nu-s cuvinte\n";
            break;
        case 2:
            cout << "Fraza inintiala\n";
            puts(fraza);
            if (n = Cuvintele(fraza))
                cout << "in total " << n << " cuvinte cu litere duble\n";
            else
                cout << "Nu-s cuvinte\n";
            break;
        case 3:
            cout << "Fraza inintiala\n";
            puts(fraza);
            // printf("\n%d\n", n);
            n = CuvinteLungMin5(fraza);
            if (n > 0)
                cout << "in total " << n << " \ncuvinte cu cel putin 5 litere\n";
            else
                cout << "Nu-s cuvinte\n";
            break;
        case 4:
            cout << "Continutul fisierului\n";
            ViewFile("file01.txt");
            if (n = NrCuvinte())
                cout << "\nin total " << n << " cuvinte\n";
            else
                cout << "Nu-s cuvinte\n";
            break;
        case 5:
            cout << "Continutul fisierului\n";
            ViewFile("file01.txt");
            if (n = Cuvintele())
                cout << "\nin total " << n << " cuvinte cu litere duble\n";
            else
                cout << "Nu-s cuvinte\n";

            break;
        case 6:
            cout << "Continutul fisierului\n";
            ViewFile("file01.txt");
            if (n = CuvinteLungMin5())
                cout << "\n\nin total " << n << " cuvinte cu litere duble\n";
            else
                cout << "Nu-s cuvinte\n";

            break;
            /* case 7:
                 cout << "Fraza initiala din fisier: \n";
                 ViewFile("file01.txt");
                 TransferCuvinteLungMin5();
                 cout << "\nCuvintele de lungimi > 5 au fost inscrise in alt fisier" << endl;
             break;

             case 8:
             break;
             case 9:
             break;*/
        }
        fflush(stdin); //очистка файла
        cout << "Apasa Enter";
        getchar();
    } while (opt);
    return 0;
}
int NrCuvinte(char sir[])
{
    char copia[251], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t")) == NULL)
        return 0;
    n = 1;
    while ((cuvint = strtok(NULL, " ,.:\n\t")) != NULL)
        n++;
    return n;
}
//подпрограмма которая посчитает количество слов с двойными буквами
int LitereDuble(char ilona[])
{
    for (int i = 1; i < strlen(ilona); i++)
        if (ilona[i] == ilona[i - 1])
            return 1;
    return 0;
}
int Cuvintele(char sir[])
{
    char copia[251], *cuvint;
    int n = 0;
    int i = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t")) == NULL)
        return 0;
    if (LitereDuble(cuvint))
    {
        n++;
        cout << setw(24) << cuvint;
    }
    while ((cuvint = strtok(NULL, " ,.:\n\t")) != NULL)
        if (LitereDuble(cuvint))
        {
            n++;
            cout << setw(24) << cuvint;
        }
    cout << endl;
    return n;
}
int CuvinteLungMin5(char sir[])
{
    char copia1[81], copia2[81], *cuvint;
    int slovo = 0;
    int n;
    // printf("\n1 %d\n", n);
    // printf("\n2 %d\n", n);

    strcpy(copia1, sir);
    n = 0;
    // printf("\n3 %d\n", n);

    puts(copia1);
    // printf("\n4 %d\n", n);

    cout << "Cuvintele cu lungimea cel putin 5 litere dintro fraza: ";
    if ((cuvint = strtok(copia1, " ,.:\n\t-")) == NULL)
        return 0;
    // printf("\n5 %d\n", n);

    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    {
        // printf("\n6 %d\n", n);

        if (strlen(cuvint) >= 5)
        {
            // printf("\n7 %d\n", n);

            n++;
            // printf("\n8 %d\n", n);

            cout << setw(12) << cuvint;
        }
    }
    cout << endl;
    // printf("\n9 %d\n", n);

    return n;
}
void ViewFile(char nume[])
{
    FILE *f;
    char sir[LMAX];
    f = fopen(nume, "r");
    while (fgets(sir, LMAX - 1, f) != NULL)
        cout << sir;
    fclose(f);
}
int NrCuvinte()
{
    FILE *f;
    char sir[LMAX];
    int nr = 0;
    f = fopen("file01.txt", "r");
    while (fgets(sir, LMAX - 1, f) != NULL)
        nr += NrCuvinte(sir);
    fclose(f);
    return nr;
}
int Cuvintele()
{
    FILE *f;
    char sir[LMAX];
    f = fopen("file01.txt", "r");
    while (fgets(sir, LMAX - 1, f) != NULL)

        fclose(f);
    return 1;
}
int CuvinteLungMin5()
{
    FILE *f;
    char sir[LMAX];
    char fraza[LMAX], copia[LMAX], *cuvint;
    int slovo = 0;
    f = fopen("file01.txt", "r");
    slovo = strlen(cuvint);
    while (fgets(fraza, LMAX - 1, f) != NULL)
    {
        if (strlen(cuvint) > 5)
        {
            slovo = strlen(cuvint);
        }
        cout << "\n\tCuvintele cu lungimea cel putin 5 litere dintr-un fisier: ";
        while (fgets(fraza, LMAX - 1, f) != NULL)
        {
            if (strlen(cuvint) <= 5)
                cout << setw(8) << cuvint << "";
        }
        /* if((cuvint = strtok(copia, " ,.:\n\t")) == NULL) return 0;
        if(cuvint[0]== cuvint[strlen(cuvint)-1]){

                cout << setw(12) << cuvint;
            }
        while((cuvint = strtok(NULL, " ,.:\n\t")) != NULL)
            if(cuvint[0]== cuvint[strlen(cuvint)-1]){

                cout << setw(12) << cuvint;*/
    }
    fclose(f);
    return 1;
    /*FILE *f;
   char fraza[LMAX], copia[LMAX], *slovo;
   f = fopen("file01.txt", "r");
   while(fgets(fraza, LMAX-1, f) !=NULL)
   {
   strcpy(copia, fraza);
   if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
   if (strlen(slovo) > 5) cout << setw(8) << slovo << " ";
   while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL)
   if (strlen(slovo) > 5) cout << setw(8) << slovo << " ";
   }
   fclose(f);
   return 0;*/
}
/*
int TransferCuvinteLungMin5()
{
    /*FILE *f;
    FILE *t;
    char fraza[LMAX], copia[LMAX], *cuvint;
    f = fopen("file01.txt", "r");
    t = fopen("file02.txt", "w");
    while (fgets (fraza, LMAX-1, f) != NULL)
    {
        strcpy (copia, fraza);
        if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
        if (strlen(cuvint) < 5) fputs(cuvint, t);
        while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL){
            fputs(" ", t);
            if (strlen(cuvint) < 5) fputs (cuvint, t);

        }
    }
    fclose(f);
    fclose(t);

    return 0;*/
/*FILE *f;
FILE *s;
char fraza[LMAX], copia[LMAX], *slovo;
f = fopen("file01.txt", "r");
s = fopen("file02.txt", "w");
while(fgets(fraza, LMAX-1, f) !=NULL)
{
strcpy(copia, fraza);
if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
if (strlen(slovo) > 5) fputs(slovo, s);
while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL) {
        fputs(" ", s);
    if (strlen(slovo) > 5) fputs(slovo, s);
}
}
fclose(f);
fclose(s);
return 0;
}
int EliminaCuvinteLungMin5(char sir[])
{
return 1;
}*/
void CopiaRezerva(char nume[])
{
}