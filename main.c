/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    // Variablendeklaration
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int tagDesJahres = 0;


    // Prüfe um jahr Schaltjahr ist
    if (isSchaltjahr(year))
    {
        tage_pro_monat[1] = 29;
    }


    // Schleife, die die einzelnen Tage der Monate in tagDesJahres speichert. -2, da der letzte Monat
    // noch nicht relevant ist.
    for (int i = 0; i <= month-2; i++){
        tagDesJahres += tage_pro_monat[i];
    }

    // Tage des letzten Monats hinzuaddieren
    tagDesJahres += day;
    return tagDesJahres;
}

int isSchaltjahr(int year)
{

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;


            }
            else
                return 0; // else-Block von (jahr % 400 == 0)
        }
        else
            return 1; // else-Block von (Jahr % 100 == 0)
    }
    else
        return 0;  // else-Block von (Jahr % 4 == 0)
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));

}
