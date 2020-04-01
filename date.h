#ifndef DATE_H
#define DATE_H

#include <time.h>

typedef struct{
    int annee;
    int mois;
    int jour;
}Date;

Date * CreerDate(int annee, int mois, int jour);
Date * DateCourante();
void FreeDate(Date * d);
Date * AjoutMoisDateCourante(int nb_mois);

#endif
