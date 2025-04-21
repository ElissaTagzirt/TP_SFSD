#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include"fonction.h"

 void aff_fichier(char nom_fichier[20],int *lirdire )
 {
      int quitt=0 , chois=0 ; int n ;
          int ld=0;
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
              scanf("%d",&n);
              Affichage_fichier(nom_fichier ,&ld ,n);
              returnToMenu();
            break ;
            case 2:
                textcolor(15);
                printf("\n\n   Veuillez introduire le nombre de bloc a affiche  ");
                textcolor(11);
                scanf("%d",&n);
                Affichage_fichier1(nom_fichier, &ld ,n);
                returnToMenu();
            break ;
            case 3 :
                quitt=1;
                (*lirdire)=ld;
             returnToMenu();
 }
 }
 }

   void affiche_nom_nombre(Tenreg enreg)

   {

       for (int i=0 ; i<=enreg.Nom_prenom.taillenom;i++ )
       {
           printf(" %2d",enreg.Nom_prenom.Nom[i]);

       }

       for(int i=enreg.Nom_prenom.taillenom ; i<=15 ;i++)printf("   ");
       printf("|");

   }
//_____________________________________ affichage d'un forma nom nombre ___________________________________________________
  void affiche_prenom_nombre(Tenreg enreg)
   {

      int  x=enreg.Nom_prenom.tailleprenom;

       for (int i=0 ; i<=x;i++ )
       {
           printf(" %2d",enreg.Nom_prenom.Prenom[i]);
       }

          for(int i=enreg.Nom_prenom.tailleprenom ; i<=15 ;i++)printf("   ");
       printf("|");
   }
   //_______________________________________________________________________________________________________________________
 void conversion_caracter(int car)

 {
     if (car==1) printf("A");
     if (car==2) printf("B");
     if (car==3) printf("C");
     if (car==4) printf("D");
     if (car==5) printf("E");
     if (car==6) printf("F");
     if (car==7) printf("G");
     if (car==8) printf("H");
     if (car==9) printf("I");
     if (car==10) printf("J");
     if (car==11) printf("K");
     if (car==12) printf("L");
     if (car==13) printf("M");
     if (car==14) printf("N");
     if (car==15) printf("O");
     if (car==16) printf("P");
     if (car==17) printf("Q");
     if (car==18) printf("R");
     if (car==19) printf("S");
     if (car==20) printf("T");
     if (car==21) printf("U");
     if (car==22) printf("V");
     if (car==23) printf("W");
     if (car==24) printf("X");
     if (car==25) printf("y");
     if (car==26) printf("Z");

 }


 //_____________________________________ affichage d'un nom forma prenom ___________________________________________________
  void affiche_nom_caractere(Tenreg enreg)
   {
     // int  x=enreg.Nom_prenom.tailleprenom;
     textcolor(11);
       for (int i=0 ; i<=enreg.Nom_prenom.taillenom;i++ )
       {
           conversion_caracter(enreg.Nom_prenom.Nom[i]);

       }
       textcolor(15);
       for(int i=enreg.Nom_prenom.taillenom ; i<=15 ;i++)printf(" ");


   }
//_____________________________________ affichage d'un prenom forma prenom ___________________________________________________
  void affiche_prenom_caractere(Tenreg enreg)
   {
     // int  x=enreg.Nom_prenom.tailleprenom;

          textcolor(11);
       for (int i=0 ; i<=enreg.Nom_prenom.tailleprenom;i++ )
       {
           conversion_caracter(enreg.Nom_prenom.Prenom[i]);

       }
       textcolor(15);
       for(int i=enreg.Nom_prenom.tailleprenom ; i<=15 ;i++)printf(" ");

   }
//______________________________________________________________________________________________________



void groupe_sanguin(int num){
    textcolor(11);
  if (num==1)printf("O+ ");
  if (num==2)printf("A+ ");
  if (num==3)printf("B+ ");
  if (num==4)printf("O- ");
  if (num==5)printf("A- ");
  if (num==6)printf("AB+");
  if (num==7)printf("B- ");
  if (num==8)printf("AB-");
  textcolor(15);
}
//_____________________________________________________________________________________________

void wilaya(int num){
  //  type g;
   struct wilaya{
      char nom[20];
      int num;
    }g;
    FILE *f;
    f=fopen("wilaya.bin","rb+");
      while ((!feof(f))){
         fread(&g,sizeof(g),1,f);
         if (g.num==num){
                textcolor(11);
           printf(" %20s",g.nom);
              textcolor(15);
         }
      }
      fclose(f);
}
//____________________________________________________________________________________

void grade(int num){
    textcolor(11);
  if (num==1) printf("GENRAL CORPS ARMEE");
  if (num==2) printf("GENERAL MAJOR     ");
  if (num==3) printf("GENERAL           ");
  if (num==4) printf("COLONEL           ");
  if (num==5) printf("LIEUTENANT-COLONEL");
  if (num==6) printf("COMMANDANT        ");
  if (num==7) printf("CAPITAINE         ");
  if (num==8) printf("LIEUTENANT        ");
  if (num==9) printf("SOUS-LIEUTENANT   ");
  if (num==10)printf("ASPIRANT          ");
  if (num==11)printf("ADJUDANT-CHEF     ");
  if (num==12)printf("ADJUDANT          ");
  if (num==13)printf("SERGENT-CHEF      ");
  if (num==14)printf("SERGENT           ");
  if (num==15)printf("CAPORALE-CHEF     ");
  if (num==16)printf("CAPORALE          ");
  if (num==17)printf("DJOUNDI           ");
  textcolor(15);


}
//_____________________________________________________________________________________________


void force_armee(int num){
    textcolor(11);
  if (num==1)printf("ARMEE TERRE              ");
  if (num==2)printf("ARMEE AIR                ");
  if (num==3)printf("MARINE NAT               ");
  if (num==4)printf("DEF AERI TERRITOIRE      ");
  if (num==5)printf("GENDARMERIE NATIONALE    ");
  if (num==6)printf("GARDE REPUBLICAINE       ");
  if (num==7)printf("DEP RESEIGNEMENT SECURITE");
  if (num==8)printf("SANTE MILITAIRE          ");
  textcolor(15);
}
//_______________________________________________________________________________________________

void region_militaire(int num){
    textcolor(11);
  if (num==1)printf("1RM-BLIDA      ");
  if (num==2)printf("2RM-ORAN       ");
  if (num==3)printf("3RM-BECHAR     ");
  if (num==4)printf("4RM-OUARGLA    ");
  if (num==5)printf("5RM-CONSTANTINE");
  if (num==6)printf("6RM-TAMANRASSET");
  textcolor(15);
}

//___________________________________________________________________________________________________

void Affichage_fichier1(char fichier[20], int *lirdire , int nb) {
                Buffer buf ;
                type w,r,f,g,gs;
             L7OF *F=ouvrir_L7OF(fichier,'A');
              textcolor(15);
             printf("  __________________________________________________________________________________________________________________________________________________________________ \n");
             textcolor(11);
             printf("||============================================================== affichage de l'entete ==============================================================================|| \n");                                                                                                          //4octet
             textcolor(15);
             printf("||___________________________________________________________________________________________________________________________________________________________________||\n");
             printf("||\tNB BLOC %3d\t" ,entete_L7OF(F,1));
             printf("|| \t\tNB Enregistrement %6d\t" ,entete_L7OF(F,2));
             printf("|| \t La tete %1d\t " ,entete_L7OF(F,3));
             printf("||\t Queue %3d " ,entete_L7OF(F,4));
             printf("||\t Indice_libre%2d " ,entete_L7OF(F,5));
             printf("|| \t\tNBsup %6d ||" ,entete_L7OF(F,6));
             printf("\n  ==================================================================================================================================================================== \n\n\n");


       if (entete_L7OF(F,1)>=nb){
        for (int k =1 ;k<=nb;k++){
            liredir_L7OF(F,k,&buf);
            (*lirdire)++;
                        textcolor(15);
        printf("  ________________________________________________________________");
        textcolor(11);
        printf("BLOC %d",k);
         textcolor(15);
          printf(" ______________________________________________________________________________________________\n");
           printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");

              textcolor(15);
             printf("|                                                                                                                         |                                           |\n|");
          //   printf("|                                                                                                                         |                 ");
             textcolor(11);
             printf("                               NB ELEMENT %d                       ",buf.nb);
             textcolor(15);
             printf("                                                      |");textcolor(11);
             printf("                 NB SUPPRIME  %d          ",buf.nbSup);
             textcolor(15);
             printf("  |\n|_________________________________________________________________________________________________________________________|___________________________________________|\n");

        printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");

             printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
             printf("| N  |       NOM         |      PRENOM       |MATRICULE|DATE NAISSANCE|  WILAYA DE NAISSANCE  |Gr-Sn| \t     Grade     \t  |    \tForce Armee\t     |region militaire|\n");
             printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
            for(int i =0; i<buf.nb; i++) {
                        printf("|");
                        textcolor(11);
                        printf("%3d",i+1);
                        textcolor(15);
                        printf(" | ");
                        affiche_nom_caractere(buf.tab[i]);
                        printf(" | ");
                        affiche_prenom_caractere(buf.tab[i]);
                        printf(" | ");
                        textcolor(11);
                        printf(" %6d",buf.tab[i].Matricule);
                        textcolor(15);
                        printf(" |  ");
                        textcolor(11);
                        printf("%4d/%2d/%2d ", buf.tab[i].Date_Nai.annee,buf.tab[i].Date_Nai.mois,buf.tab[i].Date_Nai.jour);
                        textcolor(15);
                        printf(" | ");
                        wilaya(buf.tab[i].wilaya_Nai);
                        printf(" | ");
                        groupe_sanguin(buf.tab[i].Groupe_S);
                        printf(" | ");
                        grade(buf.tab[i].Grade);
                        printf(" | ");
                        force_armee(buf.tab[i].Force_Ar);
                        printf(" | ");
                        region_militaire(buf.tab[i].Region_Mi);
                        printf("|\n");

                printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");

            }
            printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");

              textcolor(15);
             printf("|                                                                                                                         |                                           |\n|");

             textcolor(11);
             printf("                                                                   ");
             textcolor(15);
             printf("                                                      |");textcolor(11);
             printf("                 BLOC SUIVANT %3d          ",buf.suivant);
             textcolor(15);
             printf(" |\n|_________________________________________________________________________________________________________________________|___________________________________________|\n");

           printf("\n\n\n");
        } }
        else{
    printf("  le nombre de bloc introduit n'existe pas dans ce fichier :( \n\n");}
            fermer_L7OF(F);

}
void Affichage_fichier(char fichier[20] , int *lirdire , int nb) {
                Buffer buf ;
             L7OF *F=ouvrir_L7OF(fichier,'A');
             textcolor(15);
             printf("  __________________________________________________________________________________________________________________________________________________________________ \n");
             textcolor(11);
             printf("||============================================================== affichage de l'entete ==============================================================================|| \n");                                                                                                          //4octet
             textcolor(15);
             printf("||___________________________________________________________________________________________________________________________________________________________________||\n");
             printf("||\tNB BLOC %3d\t" ,entete_L7OF(F,1));
             printf("|| \t\tNB Enregistrement %6d\t" ,entete_L7OF(F,2));
             printf("|| \t La tete %1d\t " ,entete_L7OF(F,3));
             printf("||\t Queue %3d " ,entete_L7OF(F,4));
             printf("||\t Indice_libre%2d " ,entete_L7OF(F,5));
             printf("|| \t\tNBsup %6d ||" ,entete_L7OF(F,6));
            printf("\n  ==================================================================================================================================================================== \n\n\n");
    if (entete_L7OF(F,1)>=nb){
        for (int k =1 ;k<=nb;k++){
            liredir_L7OF(F,k,&buf);
            (*lirdire)++;

                textcolor(15);
        printf(" ________________________________________________________________");
        textcolor(11);
        printf("BLOC %d",k);
         textcolor(15);
          printf(" ______________________________________________________________________________________________ \n");
           printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");

              textcolor(15);
             printf("|                                                                                                                         |                                           |\n|");
          //   printf("|                                                                                                                         |                 ");
             textcolor(11);
             printf("                               NB ELEMENT %d                       ",buf.nb);
             textcolor(15);
             printf("                                                      |");textcolor(11);
             printf("                 NB SUPPRIME  %d          ",buf.nbSup);
             textcolor(15);
             printf("  |\n|_________________________________________________________________________________________________________________________|___________________________________________|\n");

        printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
        printf("| ");
        textcolor(11);
        printf("N");
        textcolor(15);
        printf(" |");
        textcolor(11);
        printf("Matricule");
        textcolor(15);
        printf("|");
        textcolor(11);
        printf("EFF");
        textcolor(15);
        printf("|                         ");
        textcolor(11);
        printf("NOM                       ");
        textcolor(15);
        printf("|                      ");
        textcolor(11);
        printf("PRENOM                       ");
        textcolor(15);
        printf("|");
        textcolor(11);
        printf("Date_NAISS");
        textcolor(15);
        printf("|");
        textcolor(11);
        printf("Wilaya");
        textcolor(15);
        printf("|");
        textcolor(11);
        printf("GR_SAN");
        textcolor(15);
        printf("|");
        textcolor(11);
        printf("Grade");
        textcolor(15);
        printf("|");
        textcolor(11);
        printf("FR_AR");
        textcolor(15);
        printf("|");
        textcolor(11);
        printf("REG_ML");
         textcolor(15);
        printf("|\n");
         printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");
            for(int i =0; i<buf.nb; i++) {

           printf("|%3d| %6d  |%2d |",i+1,buf.tab[i].Matricule,buf.tab[i].efface);
            affiche_nom_nombre(buf.tab[i]);
            affiche_prenom_nombre(buf.tab[i]);



           printf("%4d/%2d/%2d|  %2d  |  %2d  |  %2d |  %2d |  %2d  | \n" , buf.tab[i].Date_Nai.annee,buf.tab[i].Date_Nai.mois,buf.tab[i].Date_Nai.jour,buf.tab[i].wilaya_Nai,buf.tab[i].Groupe_S,buf.tab[i].Grade,buf.tab[i].Force_Ar,buf.tab[i].Region_Mi);
         }
             printf("|_____________________________________________________________________________________________________________________________________________________________________|\n");

              textcolor(15);
             printf("|                                                                                                                         |                                           |\n|");

             textcolor(11);
             printf("                                                                   ");
             textcolor(15);
             printf("                                                      |");textcolor(11);
             printf("                 BLOC SUIVANT  %4d        ",buf.suivant);
             textcolor(15);
             printf("|\n");
             printf("|_________________________________________________________________________________________________________________________|___________________________________________|\n");

           printf("\n\n\n");
        }
    }else{
    printf("  le nombre de bloc introduit n'existe pas dans ce fichier :( \n\n");}
            fermer_L7OF(F);

}


