#include <iostream>
#include <conio.h>
#include <cstring>
#define LMAX 121

using namespace std;

int Numar_Cuvinte(char sir[]);
int Cuvinte_Care_Incep_Cu_Litera(char str[], char litera);
void Eliminarea_Cuvinte_Care_Incep_Cu_Litera(char str[], char wordToDelete[]);
int Numar_Cuvinte_Fisier();
void Transfer(char litera);
void Eliminarea(char litera);
int Cel_Mult_Six(char sir[]);
int Cel_Mult_Six_Fisier();
void PreviewFile(char nume[30]);
int main()
{
    int optiune, nr;
    char lit;
    char word[LMAX];
    char fraza[LMAX] = "Dumitru este prieten cu Corina, Mihai Mihai Mihai prieteneste cu Dima rezulta...";
    do
    {
        system("cls");
        cout << "\nProiect nr. 5 elaborat de Smoleac Mihai";
        cout << "\nTema: Temperaturile intro luna calindaristica. Lucrul cu siruri de caractere\n";
        cout << "\n1. Numarul de cuvinte dintro fraza";
        cout << "\n2. Cuvinte care incep cu litera data dintro fraza";
        cout << "\n3. De sters cuvintele care se incep cu litera aleasa";
        cout << "\n4. Numarul de cuvinte dintrun fisier";
        cout << "\n5. Transfer cuvintele cu litera data in alt fisier";
        cout << "\n6. Eliminarea cuvintelor din fisier";
        cout << "\n7. Cuvintele cu cel mult 6 litere dintro fraza";
        cout << "\n8. Cuvintele cu cel mult 6 litere dintrun fisier";
        cout << "\n0. Stop";
        cout << "\n\n\tAlege (de la 0 la 7) -> ";
        cin >> optiune;

        switch (optiune)
        {
        case 1:
            cout << "\n\nFraza initiala:\n";
            // fflush(stdin);
            // gets(fraza);
            nr = Numar_Cuvinte(fraza);
            if (nr > 0)
                printf("\n%s\n Sunt %d cuvinte in fraza data", fraza, nr);
            else
                printf("\nNu sunt cuvinte");
            break;
        case 2:
            cout << "Dati o litera cu care se vor efectua operatiile: ";
            cin >> lit;
            cout << "Fraza initiala:\n";
            // fflush(stdin);
            // gets(fraza);
            nr = Cuvinte_Care_Incep_Cu_Litera(fraza, lit);
            if (nr > 0)
                printf("\t%s\n Sunt %d cuvinte care incep cu litera %c", fraza, nr, lit);
            else
            {
                printf("%s", fraza);
                cout << "\nNu sunt cuvinte care incep cu litera propusa";
            }
            break;
        case 3:
            cout << "Fraza initiala:\n";
            // fflush(stdin);
            // gets(fraza);
            puts(fraza);
            cout << "Dati cuvantul pe care doriti sa il stergeti: ";
            fflush(stdin);
            gets(word);
            Eliminarea_Cuvinte_Care_Incep_Cu_Litera(fraza, word);
            cout << "\nFraza finala:\n";
            printf("%s", fraza);
            break;

        case 4:
            cout << "Fraza initiala din fisier:\n";
            PreviewFile("file.txt");
            nr = Numar_Cuvinte_Fisier();
            if (nr > 0)
                printf("\nIn total %d cuvinte\n", nr);
            else
                cout << "Nu-s cuvinte\n";
            break;
        case 5:
            cout << "Dati o litera cu care se vor efectua operatiile: ";
            cin >> lit;
            Transfer(lit);
            break;
        case 6:
            cout << "Dati o litera cu care se vor efectua operatiile: ";
            cin >> lit;
            Eliminarea(lit);
            break;
        case 7:
            cout << "Fraza initiala:\n";
            // fflush(stdin);
            // gets(fraza);
            nr = Cel_Mult_Six(fraza);
            if (nr > 0)
                printf("\t%s\n Sunt %d cuvinte care au cel mult 6 litere", fraza, nr);
            else
            {
                printf("%s", fraza);
                cout << "\nNu sunt cuvinte care au cel mult 6 litere dintro fraza";
            }
        case 8:
            cout << "Fraza initiala din fisier:\n";
            PreviewFile("file.txt");
            nr = Cel_Mult_Six_Fisier();
            if (nr > 0)
                printf("\nIn total %d cuvinte\n", nr);
            else
                cout << "Nu-s cuvinte\n";
            break;
        }
        _getch();
    } while (optiune);
    return 0;
}

int Numar_Cuvinte(char sir[])
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, ",.!\n\t:? ")) == NULL)
        return 0;
    nr++;
    while ((cuvant = strtok(NULL, ",.!\n\t:? ")) != NULL)
        nr++;
    return nr;
}

int Cuvinte_Care_Incep_Cu_Litera(char str[], char litera)
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, str);
    cuvant = strtok(copia, ",.!\n\t:? ");
    // cout << cuvant;
    if (cuvant == NULL)
        return 0;
    if (cuvant[0] == litera)
        nr++;

    while ((cuvant = strtok(NULL, ",.!\n\t:? ")) != NULL)
    {
        // cout << cuvant << endl;
        if ((cuvant[0] == litera) || (cuvant[0] == litera - 32))
            nr++;
        puts(copia);
        // cout << " " << nr << endl;
    }
    return nr;
}

void Eliminarea_Cuvinte_Care_Incep_Cu_Litera(char str[], char wordToDelete[])
{
    char *cuvant, copia[LMAX], newVersion[LMAX];
    strcpy(copia, str);

    cuvant = strtok(copia, ",.!\n\t:? ");

    if (cuvant == NULL)
        return;

    strcpy(newVersion, cuvant);
    // Am scos ,. deoarece acestea se ignoreaza de strtok shi se primeste ca propozitia nu e acceeash
    // daca de ales Corina, aceasta nu se va sterge intrucat are virgula
    while ((cuvant = strtok(NULL, "\n\t:? ")) != NULL)
    {
        cout << cuvant << endl;
        if (strcmp(cuvant, wordToDelete) != 0)
        {
            // cout << "\nCompararea merge\n";
            strcat(newVersion, " ");
            strcat(newVersion, cuvant);
        }
    }
    // cout << "Fraza finala:\n";
    // puts(newVersion);
    strcpy(str, newVersion);
    return;
}

int Numar_Cuvinte_Fisier()
{
    FILE *f;
    char sir[LMAX];
    int nr = 0;
    f = fopen("file.txt", "r");
    if (f == NULL)
    {
        cout << "Fisierul nu a putut fi deschis\n";
        return 0;
    }

    while (fgets(sir, LMAX, f) != NULL)
    {
        nr += Numar_Cuvinte(sir);
    }
    fclose(f);
    return nr;
}

void Transfer(char litera)
{
    FILE *f1, *f2;
    char sir[LMAX];
    char sir2[LMAX] = "";
    char sir_cuvinte[LMAX];
    char *cuvant;
    f1 = fopen("file.txt", "r");
    f2 = fopen("file2.txt", "w");
    if (f1 == NULL || f2 == NULL)
    {
        cout << "Fisierul nu a putut fi deschis\n";
        return;
    }
    while (fgets(sir, LMAX, f1) != NULL)
    {
        strcat(sir2, sir);
    }
    puts(sir2);

    cuvant = strtok(sir2, ",.!\n\t:? ");
    if (cuvant == NULL)
        return;
    if ((cuvant[0] == litera) || (cuvant[0] == litera - 32))
        strcpy(sir_cuvinte, cuvant);
    while ((cuvant = strtok(NULL, ",.!\n\t:? ")) != NULL)
    {
        if ((cuvant[0] == litera) || (cuvant[0] == litera - 32))
        {
            strcat(sir_cuvinte, " ");
            strcat(sir_cuvinte, cuvant);
        }
    }

    fputs(sir_cuvinte, f2);

    fclose(f1);
    fclose(f2);
    cout << "Fisierul a fost transferat\n";
}

void Eliminarea(char litera)
{
    FILE *f1, *f2;
    char sir[LMAX];
    char sir2[LMAX] = "";
    char sir_Deleted[LMAX] = "";
    char *cuvant;
    f1 = fopen("file.txt", "r");
    f2 = fopen("fileForDelete.txt", "w");
    if (f1 == NULL || f2 == NULL)
    {
        cout << "Fisierul nu a putut fi deschis\n";
        return;
    }
    while (fgets(sir, LMAX, f1) != NULL)
    {
        strcat(sir2, sir);
    }

    cuvant = strtok(sir2, ",.!\n\t:? ");
    if (cuvant == NULL)
        return;

    if (!((cuvant[0] == litera) || (cuvant[0] == litera - 32)))
    {
        cout << cuvant << endl;
        strcpy(sir_Deleted, cuvant);
    }
    while ((cuvant = strtok(NULL, ",.!\n\t:? ")) != NULL)
    {

        if (!((cuvant[0] == litera) || (cuvant[0] == litera - 32)))
        {
            // cout << cuvant << endl;
            strcat(sir_Deleted, " ");
            strcat(sir_Deleted, cuvant);
        }
    }

    fputs(sir_Deleted, f2);

    fclose(f1);
    fclose(f2);
    cout << "Fisierul a fost modificat\n";
}

int Cel_Mult_Six(char sir[])
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    cuvant = strtok(copia, ",.!\n\t:? ");
    if (cuvant == NULL)
        return 0;
    if (strlen(cuvant) <= 6)
        nr++;
    while ((cuvant = strtok(NULL, ",.!\n\t:? ")) != NULL)
    {
        if (strlen(cuvant) <= 6)
            nr++;
        cout << cuvant << " " << nr << endl;
    }
    return nr;
}

int Cel_Mult_Six_Fisier()
{
    FILE *f1;
    char sir[LMAX];
    char sir2[LMAX] = "";
    char *cuvant;
    int nr = 0;
    f1 = fopen("file.txt", "r");

    if (f1 == NULL)
    {
        cout << "Fisierul nu a putut fi deschis\n";
        return 0;
    }
    while (fgets(sir, LMAX, f1) != NULL)
    {
        strcat(sir2, sir);
    }

    cuvant = strtok(sir2, ",.!\n\t:? ");
    if (cuvant == NULL)
        return 0;

    if (strlen(cuvant) <= 6)
    {
        nr++;
    }
    while ((cuvant = strtok(NULL, ",.!\n\t:? ")) != NULL)
    {

        if (strlen(cuvant) <= 6)
        {
            nr++;
        }
        cout << "\n"
             << cuvant << " " << nr << endl;
    }

    fclose(f1);
    return nr;
}

void PreviewFile(char fileName[])
{
    FILE *f;
    char sir[LMAX];
    f = fopen(fileName, "r");
    if (f == NULL)
    {
        cout << "Fisierul nu a putut fi deschis\n";
        return;
    }
    while (fgets(sir, LMAX, f) != NULL)
    {
        cout << sir;
    }
}