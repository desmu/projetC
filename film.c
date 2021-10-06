#include <stdio.h>

int main(void){
    char q1;
    char q2;
    char q3;
    int adulte = 0;
    int vuado = 0;
    int vuenf = 0;
    int Age = get_int("Quelle est ton âge ?\n");

    string catégorie[4][4] = {{"film Categorie Enfant ", "PatPatrol le film","Les Minions","Mon Voisin Totoro"},
                              {"film Categorie Ados","Demon Slayer","Akira","Pokemon le film"},
                              {"film Categorie Adulte","Shining", "La Nonne","Conjuring"}
    };

   do{
   if(Age < 11 || q3 == 'e'){
       if(adulte == 1){
        vuenf = 1;
    }
        printf("Voici les choix de %s\n", catégorie[0][0]);
        for(int i=1;i<4;i++){
            q1 = get_char("Voulez vous voir %s appuie sur [o] ou [n]\n", catégorie [0][i]);
            if(q1 == 'o'){
                printf("%s va commencer", catégorie[0][i]);
                return 0;
            }else if(q1 == 'n'){
                if(i == 3){
                    if(adulte == 1){
                        if(vuado == 1){
                          printf("Renevez plus tard pour d'autres films\n");
                          return 0;
                         }
                        do{
                       q2 = get_char("Voulez-vous voir les %s\n ? Appuiez sur [o] ou [n]\n", catégorie[1][0]);
                    if(q2 == 'o'){
                        q3 = 'a';
                        break;
                    }else if(q2 == 'n'){
                        printf("Renevez plus tard pour d'autres films\n");
                        return 0;
                    }else{
                        printf("Veuillez répondre par [o] ou [n] ! Je vous remercie de votre attention !\n");
                    }
                  }while(1);
                 }else{
                    printf("Renevez plus tard pour d'autres films\n");
                    return 0;
                 }
                }else{
                printf("Proposition suivante\n");
                }
            }else{
                i--;
            }

        }

    }else if((Age>=11 && Age<=17) || q3 == 'a'){
    if(adulte == 1){
        vuado = 1;
    }
    printf("Voici les choix de %s\n", catégorie[1][0]);
    for(int i=1;i<4;i++){
            q1 = get_char("Voulez vous voir %s appuie sur [o] ou [n]\n", catégorie [1][i]);
            if(q1 == 'o'){
                printf("%s va commencer", catégorie[1][i]);
                return 0;
            }else if(q1 == 'n'){
                if(i == 3){
                    if(vuenf == 1){
                          printf("Renevez plus tard pour d'autres films\n");
                          return 0;
                         }
                    do{
                       q2 = get_char("Voulez-vous voir les %s\n ? Appuiez sur [o] ou [n]\n", catégorie[0][0]);
                    if(q2 == 'o'){
                        q3 = 'e';
                        break;
                    }else if(q2 == 'n'){
                        printf("Renevez plus tard pour d'autres films\n");
                        return 0;
                    }else{
                        printf("Veuillez répondre par [o] ou [n] ! Je vous remercie de votre attention !\n");
                    }
                  }while(1);
                }else{
                printf("Proposition suivante\n");
                }
            }else{
                i--;
            }

        }
    }
    else{
        adulte = 1;
        printf("Voici les choix de %s\n", catégorie[2][0]);
        for(int i=1;i<4;i++){
            q1 = get_char("Voulez vous voir %s appuie sur [o] ou [n]\n", catégorie [2][i]);
            if(q1 == 'o'){
                printf("%s va commencer", catégorie[2][i]);
                return 0;
            }else if(q1 == 'n'){
                if(i == 3){
                    do{
                       q2 = get_char("Voulez-vous voir les autres tranches d'âges ? Appuiez sur [o] ou [n]\n");
                    if(q2 == 'o'){
                        q3 = get_char("Il y a :\n %sappuyez sur [e]\n %s appuiez sur [a]\n",catégorie[0][0], catégorie[1][0]);
                        break;
                    }else if(q2 == 'n'){
                        printf("Renevez plus tard pour d'autres films\n");
                        return 0;
                    }else{
                        printf("Veuillez répondre par [o] ou [n] ! Je vous remercie de votre attention!\n");
                    }
                  }while(1);
                }else{
                printf("Proposition suivante\n");
                }
            }else{
                i--;
            }

        }
    }
   }while(1);
}

