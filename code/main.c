#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include"fonction.h"
#include"affichage.h"




int main()
{
int nb_enr_max=98;
    int n;
 char nom_fichier[20];
 int liredr=0;
 int ecriredr =0;
//______________________________________________________________________________________________________________________________//
  int quitter=1;
  Color(11,16);
     printf("\t\t ******************************                  **********      **          ************\n");Sleep(60);
    printf("\t\t   *******************************             ****************** ***       **************\n");Sleep(60);
    printf("\t\t    ******* ********************           *******       ***********          *********\n");Sleep(60);
    printf("\t\t     ******                 *****         *****              *******           ******\n");Sleep(60);
    printf("\t\t     ******                   ****        ****                 ******          ******\n");Sleep(60);
    printf("\t\t     ******                    ***       *****                  *****          ******\n");Sleep(60);
    printf("\t\t     ******          ***        **       ******                   ***          ******\n");Sleep(60);
    printf("\t\t     ******          ***                  *******                  **          ******\n");Sleep(60);
    printf("\t\t     ******         ****                  ***********                          ******\n");Sleep(60);
    printf("\t\t     ******        *****                    ***************                    ******\n");Sleep(60);
    printf("\t\t     *******************                      *****************                ******\n");Sleep(60);
    printf("\t\t     *******************                         ******************            ******\n");Sleep(60);
    printf("\t\t     ******        *****                               **************          ******\n");Sleep(60);
    printf("\t\t     ******         ****                                     *********         ******\n");Sleep(60);
    printf("\t\t     ******          ***                ****                    *******        ******\n");Sleep(60);
    printf("\t\t     ******          ***         ***    ****                     ******        ******\n");Sleep(60);
    printf("\t\t     ******                     ****     ****                     *****        ******\n");Sleep(60);
    printf("\t\t     ******                    ****      ******                   *****        ******\n");Sleep(60);
    printf("\t\t     *****                  ******       ******                 *****          *****\n");Sleep(60);
    printf("\t\t     ******                *******        *********            ******          ******\n");Sleep(60);
    printf("\t\t ** *****************************         **** *********************       **************\n");Sleep(60);
    printf("\t\t ********************************         ***    ****************          ***************\n\n");
    Color(14,16);
    printf("\t\t\  TP 1 SFSD  2021/2022    \n");
    textcolor(14);
    printf("                                        APPUYER SUR UNE ENTER POUR COMMENCER ");
    getchar() ;
    system("cls");
     hell();
     //getchar() ;
//___________________________________________________________________________________________________________________________//
while(quitter!=0){
 int choix ;

            Color(15,16);
            printf("\n\n");
            textcolor(15);
            textcolor(11);
            printf("\t                         -->  Veuillez faire un choix dans le menu suivant  <--                \n\n") ;
            printf("\n\n\n");
            textcolor(15);
            printf("\t|=======================================================================================================|\n");textcolor(15);
            printf("\t|");textcolor(11);
            printf("\t                                           MENU                                                 ");textcolor(15);
            printf("|\n");
            textcolor(15);
            printf("\t|=======================================================================================================|\n");
           choix=menu2(14,"\t|choix 1  : chargement initiale                                                                         |",
                        "\t|choix 2  : eppuration de fichier                                                                       |",
                        "\t|choix 3  : affichage d'un fichier                                                                      |",
                        "\t|choix 4  : affichage de contune de l'index                                                             | ",
                        "\t|choix 5  : une insertion                                                                               |",
                        "\t|choix 6  : modifie la region milaitaire d'un enregistement                                             |",
                        "\t|choix 7  : supprision logiquement un enregistrement par matricule                                      |",
                        "\t|choix 8  : supprime tous les enregistrement relatifs a une force armee                                 |",
                        "\t|choix 9  : consulte les enregistrement relatifs a une regions militaire et un intervale d'age donne    |",
                        "\t|choix 10 : consulte tous les enregistrement apparteneat a une categorie de grade donne                 |",
                        "\t|choix 11 : fragmentation de fichier en 6 fichier par rapport a les region militaires                   |",
                        "\t|choix 12 : supprision physique des element supprime logiquement avant                                  |",
                        "\t|choix 13 : le cout totale des liredir et ecriredir                                                     |",
                        "\t|choix 14 : quitter                                                                                     |");

        Color(15,16);
       // printf("       -->  Veuillez faire un choix dans le menu suivant :\n\n") ;
      //  decor();

   system("cls");



     switch(choix)
        {
        case 14 :
            quitter= 0 ;
            printf("\n\n\n\n");
            the_end();
            printf("\n\n\n\n");
            system("pause");
        break;
        case 1:
             textcolor(11);
             printf("\n\n\n                                  =============> CREATION DE FICHIER <=============   \n\n ");
             textcolor(15);
             printf("\n   Veuillez introduire le nombre de personnes a charger  dans le fichier  ");
              textcolor(11);
             scanf("%d",&n);
             table_index *tab_ind=(table_index*)malloc((n+30)*sizeof(table_index));
             chargement_initial("PERSONNEL-ANP_DZ.bin",n,tab_ind,&liredr,&ecriredr);
             printf("\n\n\n\n");
                         chargement();
            printf("\n\n\n\n");
            textcolor(15);
            printf("\n\n  Operation terminee avec succes");
            textcolor(11);
            printf(" :)\n\n");
            textcolor(15);
            printf("  A l'issu de l'operation de chargement precedente nous avonz cree un fichier qui a pour  nom : " );
            textcolor(11);
            printf("PERSONNEL-ANP_DZ.bin\n\n");
            textcolor(15);
            printf("   cette creation nous a coute : \n\n\n");
            textcolor(11);
            printf("         ----> LIREDIRE : ");
            textcolor(15);
                   printf("%d \n\n", liredr);
                   textcolor(11);
                   printf("         ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecriredr);
              returnToMenu();
            break;

        case 2:;

            int lir1=0; int ecr1=0; int lir2=0; int ecr2=0;
             textcolor(11);
             printf("\n\n\n                                  =============> EPURATION DE FICHIER <=============   \n\n ");
             textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier a qui on appliquera l'operation de l'eppuration  ");
            textcolor(11);
            scanf("%s",nom_fichier);

             textcolor(15);
                     printf("\n\n\n\n");
                         chargement();
            printf("\n\n\n\n");
            textcolor(15);
            //________________________________________________________//
            suppr_doublons(nom_fichier,tab_ind,n,&lir1,&ecr1);

            //_______________________________________________________//
             char newfile[20];
             L7OF  *F=ouvrir_L7OF(nom_fichier,'A');
             int   d=entete_L7OF(F,2)-entete_L7OF(F,6)+30;
             int taille_index ;
             fermer_L7OF(F);
             table_index* tab_indd=(table_index*)malloc(d*sizeof(table_index));

             printf("\n\n");
             printf("   Veuillez introduire le nom de noveau fichier   ");
             textcolor(11);
             scanf("%s",newfile);
             printf("\n\n\n");
             chargement();
             printf("\n\n\n");
             textcolor(15);

             supprision_physique(nom_fichier,newfile,tab_indd,&taille_index,&lir2,&ecr2);

             n=taille_index;
             tab_ind=tab_indd;
             //____________________________________________________//

                liredr=liredr+lir1+lir2;
                ecriredr=ecriredr+ecr2+ecr1;
                  textcolor(15);
            printf("\n   cette epuration nous a coute : \n\n\n");
            textcolor(11);
                   printf("        ----> LIREDIRE : ");
            textcolor(15);
                   printf("%d \n\n\n",lir1+lir2);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecr2+ecr1);
              returnToMenu();
               break;
        case 3:
             textcolor(11);

             printf("\n\n\n                                  =============> AFFICHAGE DE FICHIER <=============   \n\n ");
             textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier a afficher ");
            textcolor(11);
            int lr1=0 ,lr2=0; int nl=0;
            scanf("%s",nom_fichier);
            int quitt=0 , chois=0 ;

            while(quitt!=1){
                    printf("\n\n\n");
                    chois=menu2(3 , "\t\t => AFFICHAGE AVEC DES NOMBRES ",
                                "\t\t => AFFICHAGE AVEC DES CARACTERES ",

                                "\t\t => RETOURNES AU MUNE PRINCIPALE ");
            switch(chois){
           case 1 :
               textcolor(15);
                printf("\n\n   Veuillez introduire le nombre de bloc a affiche  ");
                textcolor(11);
                scanf("%d",&nl);
            Affichage_fichier(nom_fichier,&lr1,nl);
            returnToMenu();
            break ;
            case 2:
                textcolor(15);
                printf("\n\n   Veuillez introduire le nombre de bloc a affiche  ");
                textcolor(11);
                scanf("%d",&nl);
            Affichage_fichier1(nom_fichier,&lr2,nl);
            returnToMenu();
            break ;
            case 3 :
                quitt=1;
                liredr=liredr+lr1+lr2;

                  textcolor(15);
            printf("\n   cette epuration nous a coute : \n\n\n");
            textcolor(11);
                   printf("        ----> LIREDIRE : ");
            textcolor(15);
                   printf("%d \n\n\n",lr1+lr2);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf(" 0 \n\n");
             returnToMenu();
          break ;
            }
            }
        break;
       case 4:
           textcolor(11);
            printf("\n\n\n                               =============> AFFICHAGE DE CONTUNE DE LA TABLE INDEX <=============   \n\n ");
            textcolor(15);
            affiche_table_index(tab_ind,n);
            returnToMenu();
            break;

       case 5:
              Color(11,16);
             printf("\n\n\n                                  =============> INSERSTION D'UN NOVEAUX MILITANT <=============   \n\n ");
             textcolor(15);
             printf("\n   Veuillez introduire le nom de fichier  ");
              textcolor(11);
            scanf("%s",nom_fichier);
            printf("\n\n");
            int lir=0; int ecr=0;
            textcolor(15);
            insert_novelle_matricule(nom_fichier,tab_ind,n,&lir,&ecr);
            n++;
            printf("\n\n\n");
             chargement();
             printf("\n\n\n");
             textcolor(15);
             printf("             -->  ajout avec succes :) vous povez acceder a votre fichier pour verifier l'jout  <--\n\n");

            printf("\n   cette operation nous a coute : \n\n\n");
            textcolor(11);
                   printf("        ----> LIREDIRE : ");
            textcolor(15);
                   printf("%d \n\n\n",lir);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecr);


            liredr=liredr+lir;
            ecriredr=ecriredr+ecr;



           // affiche_table_index(tab_ind,n);
            returnToMenu();
            break;

    break;
    case 6 :;
            char nom_fichier[20];
            textcolor(11);
             printf("\n\n\n                                  =============> MODIFICATION DE LA REGION MILITAIRE D'UN  MILITANT <=============   \n\n ");
            textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier   ");
            textcolor(11);
            scanf("%s",nom_fichier);
            printf("\n\n\n");

            int cle ; int region ;
             lir=0;
             ecr =0;

                             textcolor(15);
            printf("\n\n   Veuillez introduire la matricule de militant  ");
            textcolor(11);
            scanf("%d",&cle);
            textcolor(15);
            printf("\n\n   Veuillez introduire la nouvelle region  ");
            textcolor(11);
            scanf("%d",&region);
            //---------------------------------------------------------------------------//
                               printf("\n\n\n\n");
                               chargement();
                               printf("\n\n\n\n");
                               textcolor(15);
            //---------------------------------------------------------------------------//
                    modifie_region_militaire(nom_fichier,tab_ind,n,cle,region,&lir,&ecr );
             //----------------------------------------------------------------//
                     liredr=liredr+lir;
                     ecriredr=ecriredr+ecr;
            //-----------------------------------------------------------------//
                   printf("\n   cette operation nous a coute : \n\n\n");
                   textcolor(11);
                   printf("        ----> LIREDIRE : ");
                   textcolor(15);
                   printf("%d \n\n\n",lir);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecr);


            //----------------------------------------------------------------//

            returnToMenu();
        break;
       case 7: ;
            printf("\n\n\n                                  =============> SUPPRISSION D'UN  MILITANT <=============   \n\n ");
                textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier   ");
            textcolor(11);
            scanf("%s",nom_fichier);
            printf("\n\n\n");

                 textcolor(15);
             cle=0;
            printf("\n\n   Veuillez introduire la matricule de militant qu'on supprimera  ");
            textcolor(11);
            scanf("%d",&cle);
            printf("\n\n");
            lir=0;
            ecr =0;
             //---------------------------------------------------------------------------//
                               printf("\n\n\n\n");
                         chargement();
                            printf("\n\n\n\n");
                             textcolor(15);
            //---------------------------------------------------------------------------//
            supprimer_enre_logiquement(nom_fichier,tab_ind,n,cle,&lir,&ecr);


                   liredr=liredr+lir;
                   ecriredr=ecriredr+ecr;
                    //-----------------------------------------------------------------//
                     printf("\n   cette operation nous a coute : \n\n\n");
                    textcolor(11);
                     printf("        ----> LIREDIRE : ");
                     textcolor(15);
                   printf("%d \n\n\n",lir);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecr);


            //----------------------------------------------------------------//

            returnToMenu();
        break;
           case 8:



                 textcolor(11);
             printf("\n\n\n                         =============> SUPPRESSION DES MILITANTS APPARTENAT A UNE FORCE ARMEE DONNE  <=============   \n\n ");
             textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier   ");
            textcolor(11);
            scanf("%s",nom_fichier);
            printf("\n\n\n");
                 int F_Arme ;
                 textcolor(15);
                 printf("   Veuillez introduire la force arme a supprimer ");
                 textcolor(11);
                 scanf("%d",&F_Arme);
                 printf("\n\n\n");
                 lir=0;
                  ecr =0;

                   //---------------------------------------------------------------------------//
                               printf("\n\n\n\n");
                         chargement();
                            printf("\n\n\n\n");
                             textcolor(15);
                //---------------------------------------------------------------------------//
                  textcolor(15);
                 Supprime_Force_Arme(tab_ind,nom_fichier,n,F_Arme,&lir,&ecr);
                //----------------------------------------------------------------//

                   liredr=liredr+lir;
                   ecriredr=ecriredr+ecr;


                        textcolor(15);
                      printf("             -->  suprission faite avec succes :) vous povez acceder a votre fichier pour verifier les resultat  <--\n\n");
                  //-----------------------------------------------------------------//
                     printf("\n   cette operation nous a coute : \n\n\n");
                    textcolor(11);
                     printf("        ----> LIREDIRE : ");
                     textcolor(15);
                   printf("%d \n\n\n",lir);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecr);

                //----------------------------------------------------------------//
                 returnToMenu();

            break;
        case 9:


              textcolor(11);
             printf("\n\n\n                         =============> CONSULTER LES ENREGISTREMENT APPARTENAT A UNE REGION MILITAIRE DONNE <=============   \n\n ");
             textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier   ");
            textcolor(11);
            scanf("%s",nom_fichier);
            printf("\n\n\n");
          int   age1,age2 ,reg;
          textcolor(15);
          printf("   entre l'intervale d'age [ ");
          textcolor(11);
          scanf(" %d",&age1);
          printf("\n\n");;
          textcolor(15);
          printf("   entre l'intervale d'age [ ");
          textcolor(11);
           printf("%d",age1);
           textcolor(15);
           printf(" , ");
          textcolor(11);
                scanf("%d",&age2);
                printf("\n\n\n");
          textcolor(15);
          printf("   entre la region militaire ");
          textcolor(11);
          scanf("%d",&reg);
           printf("\n");
           textcolor(15);
           printf("\n\n\n      NOUS ALLONS AFFECTUER UNE RECHERCHE DES PESONNES AGEES ENTRE [ ");
           textcolor(11);
           printf("%d",age1);
           textcolor(15);
           printf(" , ");
           textcolor(11);
           printf("%d",age2);
           textcolor(15);
           printf("] APPARTENANT A LA REGION " );
           textcolor(11);
           printf("%d \n\n",reg);
           textcolor(15);
          printf("   Veuillez introduire l'annee actuale ");
          int annee ;
          textcolor(11);
          scanf("%d",&annee);
          printf("\n\n");
          textcolor(15);
              lir=0;
               //---------------------------------------------------------------------------//
               printf("\n\n\n\n");
                         chargement();
               printf("\n\n\n\n");
                textcolor(15);
              //---------------------------------------------------------------------------//
            consulte_region_militaire(nom_fichier,n,tab_ind,annee,age1,age2 ,reg ,&lir);

                    liredr=liredr+lir;
                   textcolor(15);
                   printf("   cette creation nous a coute : \n\n\n");
                   textcolor(11);
                   printf("         ----> LIREDIRE : ");
                   textcolor(15);
                   printf("%d \n\n",lir);
                   textcolor(11);
                   printf("         ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("0 \n\n");
            //---------------------------------------------------------------------------//
            textcolor(15);
                returnToMenu();

            break;

        case 10 :

            textcolor(11);
             printf("\n\n\n                         =============> CONSULTER LES ENREGISTREMENT APPARTENAT A UNE CATEGORIE DE GRADE DONNE <=============   \n\n ");
             textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier   ");
            textcolor(11);
            scanf("%s",nom_fichier);

             textcolor(15);
            lir=0;

            consulter_groupe_gra(nom_fichier,&lir);
            printf("\n\n\n\n");
                         chargement();
            printf("\n\n\n\n");
            textcolor(15);
            //---------------------------------------------------------------------------//
                   liredr=liredr+lir;
                    textcolor(15);
            printf("   cette operation nous a coute : \n\n\n");
            textcolor(11);
            printf("         ----> LIREDIRE : ");
            textcolor(15);
                   printf("%d \n\n",lir);
                   textcolor(11);
                   printf("         ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("0 \n\n");
            //---------------------------------------------------------------------------//
                returnToMenu();
           break;
        case 11 :;
          int ldd=0 ;
           textcolor(11);
             printf("\n\n\n                                  =============> FRAGMENTATION DE FICHIER EN 6 FICHIER  <=============   \n\n ");
                textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier   ");
            textcolor(11);
            scanf("%s",nom_fichier);
            printf("\n\n\n");
            //___________________________________________________________________________________//
            char fichier1[30];
            char fichier2[30];
            char fichier3[30];
            char fichier4[30];
            char fichier5[30];
            char fichier6[30];
            textcolor(15);
            printf("   Veuillez introduire le nom du fichier fragmante selon la  region militaire [1] : ");
            textcolor(11);
            scanf("%s",fichier1);
            printf("\n\n");
            textcolor(15);

            printf("   Veuillez introduire le nom du fichier fragmante selon la  region militaire [2] :  ");
            textcolor(11);
            scanf("%s",fichier2);
            printf("\n\n");
            textcolor(15);

            printf("   Veuillez introduire le nom du fichier fragmante selon la  region militaire [3] :  ");
            textcolor(11);
            scanf("%s",fichier3);
            printf("\n\n");
            textcolor(15);

            printf("   Veuillez introduire le nom du fichier fragmante selon la  region militaire [4] :  ");
            textcolor(11);
            scanf("%s",fichier4);
            printf("\n\n");
            textcolor(15);

            printf("   Veuillez introduire le nom du fichier fragmante selon la  region militaire [5] :  ");
            textcolor(11);
            scanf("%s",fichier5);
            printf("\n\n");
            textcolor(15);

            printf("   Veuillez introduire le nom du fichier fragmante selon la  region militaire [6] :  ");
            textcolor(11);
            scanf("%s",fichier6);
            printf("\n\n");
            textcolor(15);
            //___________________________________________________________________________________//
            lir=0;
            ecr =0;
             printf("\n\n\n\n");
                         chargement();
            printf("\n\n\n\n");
            textcolor(15);
            Fragmentation_region_militaire(nom_fichier,fichier1,fichier2,fichier3,fichier4,fichier5,fichier6,&lir,&ecr);
            //---------------------------------------------------------------------------//

                   liredr=liredr+lir;
                   ecriredr=ecriredr+ecr;
                     printf("\n   cette operation nous a coute : \n\n\n");
                    textcolor(11);
                     printf("        ----> LIREDIRE : ");
                     textcolor(15);
                   printf("%d \n\n\n",lir);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecr);

                //----------------------------------------------------------------//
            //_____________________________ affichage des fichier :_____________________________//

             int arr=1;
             char rep[5];
               printf("vouliez vous affiche un fichier  fragmente si oui entre  'o' ");
                   textcolor(11);
                      scanf("%s",rep);
                      textcolor(15);
                   if ( rep[0] == 'O' || rep[0] == 'o' )
                   {
            while(arr==1){

                printf("\n\n\n\n");

            int choix;
            choix=menu2(7,"\t\t | 1-Affichage du fichier fragmente selon la region militaire [1] |"
                         ,"\t\t | 2-Affichage du fichier fragmente selon la region militaire [2] |"
                         ,"\t\t | 3-Affichage du fichier fragmente selon la region militaire [3] |"
                         ,"\t\t | 4-Affichage du fichier fragmente selon la region militaire [4] |"
                         ,"\t\t | 5-Affichage du fichier fragmente selon la region militaire [5] |"
                         ,"\t\t | 6-Affichage du fichier fragmente selon la region militaire [6] |",
                          "\t\t | 7- retourne au mune pricipale                                  |");


            switch (choix)
            {
             case 1:
               printf("          --> Affichage du fichier fragmente selon la region militaire [1] <-- \n");
               aff_fichier(fichier1,&ldd);
               system("PAUSE");
              system("cls");

             break;
             case 2:
                printf("          --> Affichage du fichier fragmente selon la region militaire [2] <-- \n");
                aff_fichier(fichier2,&ldd);
                system("PAUSE");
              system("cls");

             break;
             case 3:
               printf("           --> Affichage du fichier fragmente selon la region militaire [3] <-- \n");
               aff_fichier(fichier3,&ldd);
               system("PAUSE");
              system("cls");

             break;
             case 4:
               printf("           --> Affichage du fichier fragmente selon la region militaire [4] <-- \n");
               aff_fichier(fichier4,&ldd);
               system("PAUSE");
              system("cls");

             break;
             case 5:
               printf("           --> Affichage du fichier fragmente selon la region militaire [5] <-- \n");
               aff_fichier(fichier5,&ldd);
               system("PAUSE");
              system("cls");


             break;
             case 6:
               printf("          --> Affichage du fichier fragmente selon la region militaire [6] <-- \n");
               aff_fichier(fichier6, &ldd);
               system("PAUSE");
              system("cls");

             break;
             case 7 :
                   arr=0;
              returnToMenu();
              break ;
            }
                   }
                   }
            break;

        case 12: ;
            {
             char nom_fichier[20]; char newfile[20];
              textcolor(11);
             printf("\n\n\n                                  =============> SUPPRISSION PHYSIQUE DES  MILITANT <=============   \n\n ");
                textcolor(15);
            printf("\n\n   Veuillez introduire le nom de fichier   ");
            textcolor(11);
            scanf("%s",nom_fichier);
            printf("\n\n\n");

             L7OF  *F=ouvrir_L7OF(nom_fichier,'A');
             int   d=entete_L7OF(F,2)-entete_L7OF(F,6)+30;
             int taille_index ;
             fermer_L7OF(F);
             table_index* tab_indd=(table_index*)malloc(d*sizeof(table_index));
             printf("\n\n");
             textcolor(15);
             printf("   Veuillez introduire le nom de noveau fichier   ");
             textcolor(11);
             scanf("%s",newfile);
             printf("\n\n\n");
             chargement();
             printf("\n\n\n");
            textcolor(15);
             //--------------------------------------------------------------------------//
              int lir2=0 , ecr2=0;
             supprision_physique(nom_fichier,newfile,tab_indd,&taille_index,&lir2,&ecr2);
              textcolor(15);

                liredr=liredr+lir2;
                ecriredr=ecriredr+ecr2;
                printf("\n   cette operation nous a coute : \n\n\n");
            textcolor(11);
                   printf("        ----> LIREDIRE : ");
            textcolor(15);
                   printf("%d \n\n\n",lir2);
                   textcolor(11);
                   printf("        ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecr2);
              returnToMenu();
            //--------------------------------------------------------------------------//

        }

            break;
        case 13: ;
            printf("\n\n\n");
              textcolor(11);

            printf("\n\n\n                                  =============> LE COUT TOTALE DES LIREDIR ET ECRIREDIRE <=============   \n\n ");
            textcolor(11);
            printf("         ----> LIREDIRE : ");
            textcolor(15);
                   printf("%d \n\n", liredr+ldd);
                   textcolor(11);
                   printf("         ----> ECRIREDIRE: ");
                   textcolor(15);
                   printf("%d \n\n",ecriredr);
            returnToMenu();
            break;

}


}

}
