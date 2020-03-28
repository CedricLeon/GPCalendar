#ifndef ORDONNANCE_H
#define ORDONNANCE_H

#include "date.h"
#include "medecin.h"
#include "patient.h"

typedef struct{
    Patient * patient;
    Medecin * medecin;
    Date date_edition;
    Date date_expiration;
    char * description;
}Ordonnance;

Ordonnance * CreerOrdonnance(Patient * p, Medecin * m, char * description);
int ModifierOrdonnance(Ordonnance * ordo, Patient * p, Medecin * m, Date * date_edit, Date * date_expi, char * description);
void AfficherOrdonnanc(Ordonnance * ordo);


#endif // ORDONNANCE_H