#include "date.h"

/**
 * CreerDate : Creer dynamiquement un objet Date
 * @param annee : l'annee de cette date
 * @param mois : le mois
 * @param jour : le jour
 * @return la date créée
 */
Date * CreerDate(int annee, int mois, int jour){
    Date * d = (Date *) malloc(sizeof(Date));
    d->annee = annee;
    d->mois = mois;
    d->jour = jour;
    return d;
}
/**
 * FreeDate : Libère la mémoire d'une instance Date
 * @param d
 */
void FreeDate(Date * d){
    free((void *) d);
}
/**
 * DateCourante : Créer une date correspondant à la date courante
 * @return la date courante
 */
Date * DateCourante(){
    int day, mois, an;
    time_t now;

  time(&now);

  struct tm *local = localtime(&now);
  day = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;

  Date * d = CreerDate(an,mois,day);
  return d;
}

/**
 * AjoutMoisDateCourante : Permet d'ajouter nb_mois mois � la date courante (utile notamment pour les ordonnances)
 * @param nb_mois
 * @return la date courante + nb_mois
 */
Date * AjoutMoisDateCourante(int nb_mois){
    int day, mois, an;
    time_t now;
    time(&now);
    struct tm now_tm = *localtime( &now);
    time_t futurNMois = now + 30*86400*nb_mois;
    struct tm *nbMoisPlusTard_tm = localtime(&futurNMois);

    day = nbMoisPlusTard_tm->tm_mday;
    mois = nbMoisPlusTard_tm->tm_mon + 1;
    an = nbMoisPlusTard_tm->tm_year + 1900;

    Date * d = CreerDate(an,mois,day);

    return d;
}

/**
 * getJourChar : Retourne le jour sous forme de char*
 * @param d
 * @return le jour
 */
char * getJourDate(Date *d){
    char * jour = "";
    sprintf(jour,"%d",d->jour);
    return jour;
}
/**
 * getMoisChar : Retourne le mois sous forme de char*
 * @param d
 * @return le mois
 */
char * getMoisDate(Date *d){
    char * mois = "";
    sprintf(mois,"%d",d->mois);
    return mois;
}
/**
 * getAnneeChar : Retourne l'annee sous forme de char*
 * @param d
 * @return l'annee
 */
char * getAnneeDate(Date *d){
    char * annee = "";
    sprintf(annee,"%d",d->annee);
    return annee;
}
/**
 * getInfosDate : Permet d'obtenir une chaine de caractere avec toutes les infos de la date
 * @param d : la date en question
 * @return un char * sous la forme jour/mois/annee : XX/XX/XXXX
 */
char * getInfosDate(Date * d){
    char * result = "";
    strcpy(result, getJourDate(d));
    strcat(result, "/");
    strcat(result, getMoisDate(d));
    strcat(result, "/");
    strcat(result, getAnneeDate(d));
    strcat(result, "/");
    return result;
}
