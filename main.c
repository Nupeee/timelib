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

// Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
// und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
// Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.**/
int day_of_the_year(int day, int month, int year)
{
    if (!exists_date(day, month, year)){
        return -1;
    }

    // Variablendeklaration
    int tagDesJahres = 0;

    // Schleife, die die einzelnen Tage der Monate in tagDesJahres speichert. -2, da der aktuelle Monat
    // noch nicht relevant ist.
    for (int i = 0; i <= month-2; i++){
        tagDesJahres += get_days_for_month(i+1);
    }

    // Tage des letzten Monats hinzuaddieren
    tagDesJahres += day;
    return tagDesJahres;
}

// Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
// ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
int is_leapyear(int year)
{
    if (year < 1582){
        return -1;
    }

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

// Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
// wie alle Daten nach dem 31.12.2400.
int exists_date(int day, int month, int year){
    if (year < 1582 || year > 2400){
        return 0;
    }
    if (day > get_days_for_month(month, year) || day < 1){
        return 0;
    }
    if (month > 12 || month < 0){
        return 0;
    }

    return 1;

}


// Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
// Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
int get_days_for_month(int month, int year){

    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    // Prüfe um jahr Schaltjahr ist
    if (is_leapyear(year))
    {
        tage_pro_monat[1] = 29;
    }
    return tage_pro_monat[month-1];

}


// Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
// ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.

void input_date(int* day, int* month, int* year){
    printf("Geben Sie das Jahr ein: ");
    scanf("%d", &*year);
    printf("Geben Sie den Monat ein: ");
    scanf("%d", &*month);
    printf("Geben Sie den Tag ein: ");
    scanf("%d", &*day);

}

int main()
{
    int day, month, year;
    input_date(&day, &month, &year);

    printf("\n--- Datum: %d.%d.%d --- \n", day, month, year);

    int days_count = day_of_the_year(day, month, year);
    if (days_count == -1){
        printf("Das eingegebene Datum ist ungueltig!");
    }
    else
    {
    printf("Tag des Jahres: %i\n", days_count);
    }

}
