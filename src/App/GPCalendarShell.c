#include "GPCalendarShell.h"



void printPossibleAction(){
    printf("\t- 1 : Créer un Patient\n");
    printf("\t- 2 : Créer un Médecin\n");
    printf("\t- 3 : Créer un Rendez-vous entre un Patient et un Médecin\n");
    printf("\t- 4 : Consulter les informations de l'Hôpital\n");
    printf("\t- 5 : Annuler un Rendez-vous\n");
    printf("\t- 6 : Supprimer un Patient de la liste de l'Hôpital\n");
    printf("\t- 7 : Supprimer un Médecin de la liste de l'Hôpital\n");
    printf("\t- 8 : Sauvegarder un Projet (Liste des Patients consultants, des Médecins travaillants et le calendrier de l'hôpital\n");
}

/**********************************************************************************************************************/
                                            /*Fonctions d'actions*/
/**********************************************************************************************************************/

void Shell_creerPatient(){

}
void Shell_creerMedecin(){

}
void Shell_creerRendezVous(){

}
void Shell_consulterInformations(){

}
void Shell_annulerRendezVous(){

}
void Shell_supprimerPatient(){

}
void Shell_supprimerMedecin(){

}
void Shell_saveProject(){

}
void Shell_loadProject(){

}

int main(int argc, char *argv[]){

    /**
     * Idées d'amélioration :
     *  - mettre de la couleur (pour les questions ou autres pour différencier les print de ce main ou les print des fonctions appellées)
     *  - implémenter un "help"
     *  -
     */

    //Initialisation des variables

    //Variables nécessaires au load ou à la création d'un projet par l'utilisateur
    char GPCalendar_project_path[200];
    Project* current_project = NULL;
    char project_name[200];

    //Variables nécessaires au choix de l'action par l'utilisateur
    long GPCalendar_action = -1;
    char GPCalendar_ask[100];
    char* GPCalendar_ask_tmp;

    //Variables nécessaires au choix de quitter ou non l'application par l'utilisateur
    long GPCalendar_exit = -1;
    char GPCalendar_exit_ask[100];
    char* GPCalendar_exit_ask_tmp;

    char project_save_file_name[100];


    //Ouverture de l'appli
    printf("************************** GPCalendar_Shell ******************************\n");

    printf("\nBienvenue dans la version console de GPCalendar, souhaitez vous travailler avec un projet déjà existant ou souhaitez vous en créer un nouveau ?\n");
    printf("Entrez \"new\" pour créer un nouveau projet ou entrez directement le chemin absolu du fichier JSON correspondant à un projet précédemment suavegardé.\n");
    printf("Exemple : \"C:\\Documents\\YourProject.json\"\n");

    do{
        scanf("%s", GPCalendar_project_path);
        /* /home/cleonard/dev/C_Project/C_Project/cmake-build-debug/CefichierEstUnTestdeSaveGPCalendarJson.json */

        if(strcmp(GPCalendar_project_path, "new") == 0)
        {

            printf("Vous avez choisi de créer un nouveau projet, comment souhaitez vous l'appeller ? : ");
            scanf("%s", project_name);

            ListMedecin* project_workingMedecins = CreerListMedecin();
            ListPatient* project_consultingPatients = CreerListPatient();
            Calendrier project_calendrier = CreerCalendrier();

            current_project = CreerProject(project_name, project_workingMedecins, project_consultingPatients, project_calendrier);
            printf("Vous avez créé un nouveau projet \"%s\", vous allez maintenant pouvoir le manipuler.\n", project_name);
            printf("Si vous souhaitez travailler sur un autre projet, vous devrez fermer l'application et la réouvrir avec un autre projet.\n");
            break;
        }
        else
        {
            current_project = GPCalendar_loadProject(GPCalendar_project_path);
            if (current_project != NULL){
                printf("\nVous avez choisi de load le projet \"%s\", le voici :\n", current_project->nom);
                printProject(current_project);
            }else {
                printf("Le fichier est introuvable, veuillez entrez un chemin valide ou \"new\" pour créer un nouveau projet.\n");
            }
        }
    } while (current_project == NULL);

    printf("\nPour utiliser l'application vous devrez entrer "
           "des chiffres correspondants chacun à une action particulière :\n");
    printPossibleAction();

    //gestion de l'aide : [NOT IMPLEMENTED]
    printf("\nSi vous avez besoin d'aide à propos des commandes vous pouvez taper \"help\" à n'importe quel moment.[NOT IMPLEMENTED]\n\n");

    do
    {
        /**
         * Demande de l'action à l'utilisateur (utilisation de fgets et strtol)
         */
        printf("Que voulez-vous faire ? ");
        while (fgets(GPCalendar_ask, sizeof(GPCalendar_ask), stdin)) {
            GPCalendar_action = strtol(GPCalendar_ask, &GPCalendar_ask_tmp, 10);
            if (GPCalendar_ask_tmp == GPCalendar_ask || *GPCalendar_ask_tmp != '\n')
            {
                printf("Veuillez entrer un chiffre : ");
            }
            else if (GPCalendar_action < 1 || GPCalendar_action > 8)
            {
                printf("Veuillez entrer un chiffre correspondant aux actions possibles : \n");
                printPossibleAction();
            }
            else break;
        }
        /**
         * Switch case pour appeller la fonction correspondant à l'action demandée
         */
        switch (GPCalendar_action)
        {
            case 1:
                printf("Vous avez choisi de créer un Patient.\n");

                break;
            case 2:
                printf("Vous avez choisi de créer un Médecin.\n");
                break;
            case 3:
                printf("Vous avez choisi de créer un Rendez-vous.\n");
                break;
            case 4:
                printf("Vous avez choisi de consulter des informations.\n");
                break;
            case 5:
                printf("Vous avez choisi de annuler un Rendez-vous.\n");
                break;
            case 6:
                printf("Vous avez choisi de supprimer un Patient.\n");
                break;
            case 7:
                printf("Vous avez choisi de supprimer un Médecin.\n");
                break;
            case 8:
                printf("Vous avez choisi de sauvegarder le Projet actuel.\n");
                break;
            default :
                //Normalement on n'arrivera jamais ici puisque tout est déjà vérifier plus haut
                printf("Le chiffre que vous avez tapé ne fait pas parti des choix, que voulez-vous faire ?\n");
                break;
        }

        /**
         * On demande à l'utilisateur si il veut continuer à utiliser l'appli :
         *  - "yes" pour continuer
         *   - "no" pour arreter
         */
        printf("Voulez-vous continuez ? Entrez '1' si oui, '0' si non : ");
        while (fgets(GPCalendar_exit_ask, sizeof(GPCalendar_exit_ask), stdin)) {
            GPCalendar_exit = strtol(GPCalendar_exit_ask, &GPCalendar_exit_ask_tmp, 10);
            if (GPCalendar_exit_ask_tmp == GPCalendar_exit_ask || *GPCalendar_exit_ask_tmp != '\n')
            {
                printf("Veuillez entrer un chiffre : ");
            }
            else if (GPCalendar_exit < 0 || GPCalendar_exit > 1)
            {
                printf("Veuillez entrer un chiffre correspondant aux actions possibles : \n");
                printf("Entrez '1' si vous voulez continuer, '0' si vous souhaitez quitter l'application : ");
            }
            else
                break;
        }
    } while (GPCalendar_exit);

    printf("\nAvant de partir, souhaitez-vous enregistrer votre projet ? Si oui, entrez directement le chemin absolu avec le nom du fichier de sauvegarde JSON que vous souhaitez créer.\n");
    printf("Exemple : \"C:\\Documents\\NomDeMonFichierDeSauvegarde.json\".\n");
    printf("Et si vous ne souhaitez pas sauvegarder votre projet tapez simplement \"no\".\n");
    scanf("%s", project_save_file_name);
    /* /home/cleonard/dev/C_Project/C_Project/CefichierEstUnTestdeSaveGPCalendarJson.json */
    if(strcmp(project_save_file_name, "no") == 0)
    {
        freeProject(current_project);
    }
    else{
        if(GPCalendar_saveProject(project_save_file_name, current_project) == 1){
            printf("Votre projet \"%s\" a bien été sauvegardé ici : \"%s\".\n", current_project->nom, project_save_file_name);
            freeProject(current_project);
        }else{
            printf("La sauvegarde du projet a échouée, le projet est tout de même supprimé pour des raisons de fuites mémoire.\n");
            freeProject(current_project);
        }
    }
    printf("Merci d'avoir utilisé notre application ;).\n");
    printf("\n************************** GPCalendar_Shell ******************************\n");
}