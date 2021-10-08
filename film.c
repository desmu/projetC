#include <stdio.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

int cmp(char a[], char *b) //comparaison de chaînes de caractères les arguments sont les chaînes à comparer
{
    int i=0;//initialisation à 0
    while(a[i] != '\0' || *b != '\0') //tant que l'on atteint pas le caractère nul ni pour a ni pour b
    {
        if(a[i]>=65 && a[i]<=90) //si a de i est en majuscule
        {
            a[i]+=32;//lepasser en minuscule
        }
        if(a[i] == *b) //si valeurs aux adresses de a de i et b identiques...
        {
            b++;//caractère suivant
        }
        else
        {
            return 1;//retourne 1 si chaînes différentes
        }
        i++;//caractère a de i suivant
    }
    return 0;//retourne 0 si chaînes identiques
}
int main(void)
{
    int on=1;//boucle principale activée
    char *tranche[2]= {"enfants","ado"}; //stocké pour le string compare
    //création des variables de choix pour l'utilisateur
    char voir;
    char switchCat;
    char cat[50];
    //création de variables visant à déterminer si l'utilisateur : est majeur/a déja checké les films ado/enfant
    int maj;
    int checkTeen;
    int checkKid;
    int age;//stock l'age de l'utilisateur
    //tableau à double entrée pour stocker les films par tranche d'âge
    char *mediatheque[3][4] = {{"films Enfants","Mickey","Tintin","Gloups je suis un poisson"},{"films Ados","Fast and furious","Mission impossible","Harry Potter"},{"films pour majeurs","Les langoliers", "ca","Sixieme sens"}};
    //demande l'âge de l'utilisateur(stocké à l'adresse de "age")
    printf("Age de l'utilisateur : \n");
    scanf("%i", &age);
    //boucle principale visant à revenir aux choix de départ si l'utilisateur veut une autre tranche d'âge
    do
    {
        //on vérifie l'âge de l'utilisateur ou si majeur veut voir les films enfant
        if(age < 11 || cmp(cat,tranche[0])==0)
        {
            if(maj == 1) //on détermine si un majeur a vu la catégorie enfant pour qu'elle ne soit pas reproposée après avoir vu la catégorie ado
            {
                checkKid = 1;
            }
            printf("\n\nCategorie %s : \n\n", mediatheque[0][0]);//tableau 00 = films enfants
            for(int i=1; i<4; i++) //boucle visant à afficher toute la médiathèque de la ligne une un par un
            {
                printf("Souhaitez vous visionner les %s [o] ou [n] : \n",mediatheque[0][i]);//suggestion
                scanf(" %c",&voir);//réponsee à la suggestion stockée dans une variable
                if(voir == 'o') //si oui
                {
                    printf("%s commence...", mediatheque[0][i]);//tel film pour enfant choisi commence
                    sleep(1);//wait a second !
                    on=0;//fin
                    break;
                }
                else if(voir == 'n')  //si non
                {
                    if(i == 3) //toutes les suggestions sont déja passées
                    {
                        if(maj == 1) //majeur ?
                        {
                            if(checkTeen == 1) //a déja vu les suggestions ado
                            {
                                printf("A bientot\n");
                                sleep(1);//chotto matte !
                                on=0;//fin
                            }
                            int subon4=1;
                            do //pour reposer la question si la répose est incorecte
                            {
                                printf("Souhaitez vous visionner les %s\n [o] ou [n] : \n",mediatheque[1][0]);
                                scanf(" %c",&switchCat);//demande a la personne majeure s'il veut voir les choix ado après avoir vu enfants
                                if(switchCat == 'o') //si oui
                                {
                                    for(int j=0; j<sizeof(tranche[1]); j++) //assignation de "ado" dans la variable catégories(cat)
                                    {
                                        cat[i]=tranche[1][i];
                                    }
                                    break;
                                }
                                else if(switchCat == 'n')  //si non
                                {
                                    printf("A bientot\n");
                                    sleep(1);//stop !
                                    on=0;//fin
                                    subon4=0;
                                }
                                else  //gestion d'erreur
                                {
                                    printf("Mauvaise requete : [o] ou [n]\n");
                                }
                            }
                            while(subon4==1);
                        }
                        else  //pas majeure + a refusé tous les films enfants
                        {
                            printf("A bientot\n");
                            sleep(1);//deng yixia !
                            on=0;//fin
                        }
                    }
                    else  //a juste dit non mais il reste des suggestions
                    {
                        printf("\n");
                    }
                }
                else  //si mauvaise requête
                {
                    i--;//réitération de l'itération
                }
            }
        }
        else if((age>=11 && age<=17) || cmp(cat,tranche[1])==0)  //on vérifie l'âge de l'utilisateur ou si un majeur veut voir les films ado
        {
            if(maj == 1) //on détermine si un majeur a vu la catégorie ado pour qu'elle ne soit pas reproposée après avoir vu la catégorie enfant
            {
                checkTeen = 1;
            }
            printf("\n\nCategorie %s : \n\n", mediatheque[1][0]);//tableau 10 = films ado
            for(int i=1; i<4; i++) //boucle visant à afficher toute la médiathèque de la ligne deux un par un
            {
                printf("Souhaitez vous visionner les %s [o] ou [n]\n",mediatheque[1][i]);//suggestion
                scanf(" %c",&voir);//réponsee à la suggestion stockée dans une variable
                if(voir == 'o') //si oui
                {
                    printf("%s commence...", mediatheque[1][i]);//film ado commence
                    sleep(1);//attendre
                    on=0;//fin
                    i=3;//fin
                }
                else if(voir == 'n')  //si non
                {
                    if(i==3) //déja dit non à toutes suggestions ado
                    {
                        if(checkKid==1) //déja vu catégorie enfant
                        {
                            printf("A bientot\n");
                            sleep(1);//attendre !
                            on=0;//fin
                            break;
                        }
                        int subon3=1;
                        do //pour gérer une erreur
                        {
                            printf("Souhaitez vous connaitre les suggestions de %s [o] ou [n]\n",mediatheque[0][0]);//voir un film enfant ?
                            scanf(" %c",&switchCat);//stocker la réponse
                            if(switchCat == 'o') //si oui
                            {
                                for(int j=0; j<sizeof(tranche[0]); j++) //assignation de "enfants" dans la variable catégories(cat)
                                {
                                    cat[i]=tranche[0][i];
                                }
                                subon3=0;
                            }
                            else if(switchCat == 'n')  //si non
                            {
                                printf("A bientot\n");
                                sleep(1);//warte !
                                on=0;
                                subon3=0;//fin
                            }
                            else  //erreur
                            {
                                printf("Mauvaise requete : [o] ou [n]\n");
                            }
                        }
                        while(subon3==1);
                    }
                    else  //s'il reste des films ado à suggérer
                    {
                        printf("\n");
                    }
                }
                else  //si mauvaise requête
                {
                    i--;//réitération de l'itération
                }
            }
        }
        else
        {
            maj = 1;//l'utilisateur est majeur
            printf("\n\nCategorie %s : \n\n", mediatheque[2][0]);//introduit la tranche d'âge majeur
            for(int i=1; i<4; i++) //pour chaque film...
            {
                printf("Souhaitez vous visionner les %s [o] ou [n]\n",mediatheque[2][i]);//suggestion d'un film colone "i" de la 3eme ligne du tableau
                scanf(" %c",&voir);//stock la réponse dans une variable
                if(voir == 'o') //si oui
                {
                    printf("%s commence...", mediatheque[2][i]);//le film commence
                    sleep(1);//wait
                    on=0;//fin
                    break;
                }
                else if(voir == 'n')  //si non
                {
                    if(i == 3) //si tous films déja suggérés
                    {
                        int subon1=1;
                        do //boucle pour reposer la question en cas d'erreur
                        {
                            printf("Suggestion de films pour tranches d'ages inferieures :\n[o] ou [n]\n");//autres tranches d'ages suggérées
                            scanf(" %c", &switchCat);//réponse dans variable
                            if(switchCat == 'o') //si oui
                            {
                                int subon2=1;
                                do
                                {
                                    printf("\n\nTranches d'ages : \n\nenfants\n\nou\n\nado\n\n : ");//d'abord enfant ou ado ?
                                    scanf(" %s", cat);//stocker réponse dans variable
                                    if(cmp(cat,tranche[0])==0 || cmp(cat,tranche[1])==0)
                                    {
                                        subon1=0;
                                        subon2=0;
                                    }
                                    else
                                    {
                                        printf("je n'ai pas compris, orthographiez comme ci dessous svp !");
                                    }
                                }
                                while(subon2==1);
                            }
                            else if(switchCat == 'n')  //si non
                            {
                                printf("A bientot\n");//bye !
                                sleep(1);//zzZzzZzZZZzzZZzZZzZZZZzZZzZZzz
                                on=0;//fin
                                break;
                            }
                            else  //mauvaise reqête
                            {
                                printf("Mauvaise requete : [o] ou [n]\n");//sermon
                            }
                        }
                        while(subon1==1);
                    }
                    else  //il reste des films à suggérer
                    {
                        printf("\n");//next
                    }
                }
                else  //mauvaise requête
                {
                    i--;//réitération de l'itération
                }
            }
        }
    }
    while(on==1); //boucle active si sur on
}

