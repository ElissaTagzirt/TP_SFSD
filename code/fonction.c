#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include"fonction.h"

const int nb_enr_max = 98 ;
/*************************************les fonctions princinales********************************************/
void turn_to_string(char chaine[], int n, int longueur)
{

    int k;
    for(k=longueur-1;k>=0;k--)          // on commence par le poids faible du nombre qui va etre mi a chaine[longueur-1]
    {
        chaine[k]=(n%10)+'0';           // extraction chiffre par chiffre  grace au mod par 10 et ajout du code ascii du zero afoin d'obtenir le code ascii correspondant au chiffre obtenu
        n=n/10;                        // on passe au chiffre suivant
    }
    chaine[longueur]='\0';             // fin de la chaine construite
}
//____________________________________________________________________________________________________________________//
//____________________________________________________________________________________________________________________//
int nb_aleatoire(int inf,int sup)         //g�nerer un nombre al�atoire
{
    int inter=0;
    inter = (rand()%(sup - inf + 1))+inf;   //la fonction random de la g�n�ration al�atoire
    {
        return (inter);
    }
}



void enreg_aleat(Tenreg *enreg)   // gï¿½nï¿½re un enregistrement alï¿½atoire qui va ï¿½tre insï¿½rï¿½ dans un bloc du fichier
{
    char  P[15],N[15];
    //----------------------------case efface :----------------------------//
    enreg->efface=0;
    //----------------------------case matricule :-------------------------//

    enreg->Matricule=nb_aleatoire(111111,666666);

    //----------------------------case nom/prenom :----------------------//

    int x;
    x=nb_aleatoire(4,15);
    (enreg)->Nom_prenom.taillenom=x;

    int i;
    char c;
    for (i=0;i<x;i++){
        (enreg)->Nom_prenom.Nom[i]=nb_aleatoire(1,26);


    }

    (enreg)->Nom_prenom.tailleprenom=x;
    for (i=0;i<x;i++){
        (enreg)->Nom_prenom.Prenom[i]=nb_aleatoire(1,26);


    }





    //------------------------case_date_Naissence :----------------------//
             //_________________________l'annee:____________________________//
         int an;

        an=nb_aleatoire(1940,2003);
        ((enreg)->Date_Nai).annee=an;
        //_________________________le mois:____________________________//
        int mo;

         mo=nb_aleatoire(1,12);
         ((enreg)->Date_Nai).mois=mo;

       //_________________________le mois:____________________________//
    if ((mo==4)||(mo==6)||(mo==9)||(mo==11))
        {
       enreg->Date_Nai.jour=nb_aleatoire(1,30);

        }
    else {
        if (mo==2){
           if (an%4 ==0){
            //l'anne est bissextile
            enreg->Date_Nai.jour=nb_aleatoire(1,29);

        }
          else{
               ((enreg)->Date_Nai).jour=nb_aleatoire(1,28);

        }
    }
 else {
            ((enreg)->Date_Nai).jour=nb_aleatoire(1,31);

      }
    }
//------------------------case wilaya:------------------------------------//
           enreg->wilaya_Nai=nb_aleatoire(1,58);

//------------------------case Groupe sanguin:---------------------------//
   enreg->Groupe_S = nb_aleatoire(1,8);// on a 8 groupes Sanguins
//--------------------------- case Grade:-------------------------------//
    enreg->Grade = nb_aleatoire(1,17);// on a 17 grades
//------------------------ case Force Arme: ---------------------------//
    enreg->Force_Ar = nb_aleatoire(1,8);// on a 8 force armee
//------------------------case Rï¿½gion militaire:----------------------//
     enreg->Region_Mi = nb_aleatoire(1,6);// on a 6 regions militaires
}
//________________________________________________________________________________________________

void chargement_initial(char nom_fichier[20], int n ,table_index tab_ind[] , int *liredire , int *ecriredire )  //le chargement aléatoire du fichier
{

    Buffer buf_bloc ;
    const int nb_enr_max = 98;// le nombre max d'enregistrement que peut contenir un bloc
        L7OF *F=ouvrir_L7OF(nom_fichier,'N');
        Tenreg enr;

         int i=1 ;  // pour parcourir les bloc
         int j=0 ;    // pour parcourir dans le bloc

    if ( n>0 ){


          // le fichier n'existe pas alors il faudra le créer

            alloc_bloc_L7OF(F);            //allocation de premier bloc
            liredir_L7OF(F,1,&buf_bloc);   // Ecriture dans le buffer
            (*liredire)++;
            unsigned k ;
    for (k=0 ;k<n ; k++ )
    {
        enreg_aleat(&enr);  // générer des enregistrements aléatoires
       // affichage(enr);
        if (j < (nb_enr_max) )
        {
            buf_bloc.tab[j] = enr ; // peut etre c'est faut
        //    affichage(buf_bloc.tab[j] );

            /*______ inserstion dans l'index :_______*/
            tab_ind[k].cle=enr.Matricule;
            tab_ind[k].NumBloc= i;
            tab_ind[k].posBloc=j;
            tab_ind[k].region= enr.Region_Mi;
            tab_ind[k].DateN=enr.Date_Nai;
            tab_ind[k].efface=0;
            //______________________________________//
            j++ ;
        }
        else
        {
            buf_bloc.nb = j ; // nombre d'enregistrement
            buf_bloc.nbSup = 0 ; //nombre d'enregistrement supprimer
            buf_bloc.suivant= i+1 ;
            ecriredir_L7OF(F,i,&buf_bloc);
            (*ecriredire)++;
            buf_bloc.tab[0] = enr ;
            i++ ;

            // insertion dans l'index //
             tab_ind[k].cle=enr.Matricule;
            tab_ind[k].NumBloc= i;
            tab_ind[k].posBloc=0;
            tab_ind[k].region= enr.Region_Mi;
            tab_ind[k].DateN=enr.Date_Nai;
            tab_ind[k].efface=0;
            j=1 ;


        }
    }
            buf_bloc.nb = j ; // nombre d'enregistrement
            buf_bloc.nbSup = 0 ; //nombre d'enregistrement supprimer
            buf_bloc.suivant= -1 ; //le dernier maillon (bloc )
            ecriredir_L7OF(F,i,&buf_bloc);
            (*ecriredire)++;
            aff_entete_L7OF(F,1,i);     //le nombre de bloc
            aff_entete_L7OF(F,2,n);    //le nombre d'enregistrement
            aff_entete_L7OF(F,3,1);   //la tete
            aff_entete_L7OF(F,4,i);  //la queue
            aff_entete_L7OF(F,5,j);  //l'indice libre dans le dernier bloc
            aff_entete_L7OF(F,6,0);  //le nombre d'enregistrement supprimer



    }
    fermer_L7OF(F);
}




//_______________________________________________________________________________________________
void suppr_doublons(char nom_fichier[20], table_index tab_ind[], int taille_tab , int *liredire , int *ecriredire)// Supprime logiquement les doublons d'un fichier
{
    Buffer buf ; int NbSp;
    L7OF  *F=ouvrir_L7OF( nom_fichier,'A');
         NbSp=0;
         int k;



    for (int i=0; i<=taille_tab; i++)
    {
        if (tab_ind[i].efface==0)   // Si un enregistrement a un bit d'effacement = 0 alors on le garde
        {

            for( k=i+1; k<=taille_tab; k++)
            {
                if((tab_ind[i].cle == tab_ind[k].cle)&&( tab_ind[i].efface == 0)) // si 2 enregistrements ont le même matricule
                {
                    tab_ind[i].efface=1;
                    NbSp++; // le numbre de enregistrement totale supprimer
                    liredir_L7OF(F,tab_ind[k].NumBloc,&buf);
                    (*liredire)++;
                     buf.tab[tab_ind[k].posBloc].efface=1 ;
                     buf.nbSup =  buf.nbSup + 1 ;

                    ecriredir_L7OF(F,tab_ind[k].NumBloc,&buf);
                   (*ecriredire)++;
                }
            }
        }
    }
     printf("   Nous avons trouve ");
     textcolor(11);
     printf(" %d ",NbSp);
     textcolor(15);
     printf(" doubblant dans ce fichier ");
     textcolor(11);
     printf(" :O\n\n");
     textcolor(15);
     aff_entete_L7OF(F,6,entete_L7OF(F,6)+NbSp);

     fermer_L7OF(F);
  //  Affichage_fichier(nom_fichier);

}


  //____________________________________________________________________________________________________//
 //___________________________________ L'insertion ____________________________________________________//
//____________________________________________________________________________________________________//



void insert_novelle_matricule( char nom_fichier[] , table_index tab_ind[], int taille_index , int *liredire , int *ecriredire)
{
     int mat;
    Buffer buf ;

                  Tenreg eng ; int stop=0 ;
           while(stop!=1){
                       enreg_aleat(&eng);
                      printf("   Veuillez introduire la matricule de la nouvelle personne  ");
                      textcolor(11);
                      scanf("%d",&mat);
                      textcolor(15);
                      printf("\n\n");
                       eng.Matricule=mat ;
                            int cp=0 ;
                                  int trouv=0;
                                   while ( (trouv !=1) && (cp<taille_index) )
                                           {
                                        if (( tab_ind[cp].efface != 1)&&( tab_ind[cp].cle == mat))
                                          {
                                              trouv = 1;

                                             textcolor(15);
                                             printf("  -> cette matricule est deja associe a une personne");
                                             textcolor(11);
                                                 printf(" :( \n");
                                                 textcolor(15);
                                          }
                                             cp++ ;
                                           }
                                          if(trouv !=1) {stop=1;

                                                        printf("   la generation des information de la nouvelle personne est termine ");
                                                        textcolor(11);
                                                 printf(" =) \n\n\n");
                                                 textcolor(15);}
                                          else{stop=0;
                                          textcolor(15);
                                          printf("  -> cette matricule est deja associe a une personne");
                                          textcolor(11);
                                                 printf(" :( \n");
                                                 textcolor(15);
                                                 }

           }

                              int i ; int j ;
                             L7OF *F=ouvrir_L7OF(nom_fichier,'A');
                             int n = entete_L7OF(F,2); //je recuper le nombre d'enregistrement
                                 i=entete_L7OF(F,4);      //on recupere le numero du  dernier bloc
                                 j=entete_L7OF(F,5);     //on recupere le premier indice libre  pour le dernier bloc

                    if( j<max1)
                    {

                        liredir_L7OF(F,i,&buf);
                        (*liredire)++;/***/
                        buf.tab[j]=eng ;
                        buf.nb++; // revoire si je depasse la taille d'un bloc

                       // tab_ind = (table_index*)realloc( tab_ind, n*sizeof(table_index) );
                       //n++;
                     //  tab_ind = (table_index*)realloc( tab_ind, (n+1)*sizeof(int) );

                         /*______ inserstion dans l'index :_______*/
                             tab_ind[n].cle=eng.Matricule;
                             tab_ind[n].NumBloc= i;
                             tab_ind[n].posBloc=j;
                             tab_ind[n].region= eng.Region_Mi;
                             tab_ind[n].DateN=eng.Date_Nai;
                             tab_ind[n].efface=0;

                        //______________________________________//
                            ecriredir_L7OF(F,i,&buf);
                            (*ecriredire)++;/***/
                            aff_entete_L7OF(F,2,n+1);
                            aff_entete_L7OF(F,5,j+1);

                            fermer_L7OF(F);
                    }

                    else{  //insertion dans le bloc i+1
                            liredir_L7OF(F,i,&buf);
                            (*liredire)++;/***/
                            buf.suivant=i+1;
                            ecriredir_L7OF(F,i,&buf);
                            (*ecriredire)++;/***/
                            i++;
                            buf.tab[0]=eng;
                            buf.nb=1;
                            buf.suivant=-1;
                            buf.nbSup=0;
                            ecriredir_L7OF(F,i,&buf);
                            (*ecriredire)++;/***/



                      // tab_ind = (table_index*)realloc( tab_ind, (n+1)*sizeof(table_index) );
                          /*______ inserstion dans l'index :_______*/
                             tab_ind[n].cle=eng.Matricule;
                             tab_ind[n].NumBloc= i;
                             tab_ind[n].posBloc=0;
                             tab_ind[n].region= eng.Region_Mi;
                             tab_ind[n].DateN=eng.Date_Nai;
                             tab_ind[n].efface=0;
                         //______________________________________//
                            aff_entete_L7OF(F,1,i);
                            aff_entete_L7OF(F,2,entete_L7OF(F,2)+1);
                            aff_entete_L7OF(F,4,i);
                            aff_entete_L7OF(F,5,1);
                            fermer_L7OF(F);
                    }
       textcolor(15);
      printf("   Vous avez ajoute une nouvelle personne ayant la matricule : ");
      textcolor(11);
           printf("%d\n\n",mat);
           textcolor(15);
}

  //_________________________________________________________________________________________________//
 //_____________________________________ Supprision physique : _____________________________________//
//_________________________________________________________________________________________________//
void supprision_physique( char nom_fichier[20],char nom_fichiernew[20],table_index tab_ind[] , int *taille_index ,int *liredire , int *ecriredire)
   {
    Buffer buf, buf1 ;
    const int nb_enr_max=98 ;
    L7OF  *F=ouvrir_L7OF( nom_fichier,'A');
    L7OF  *F1=ouvrir_L7OF(nom_fichiernew,'N');
     int i1=1 , i=1;
     int j1=0 , j=0 ;
      int     NG=0;
      int NbBloc=entete_L7OF(F,1) ;

     alloc_bloc_L7OF(F1);
     liredir_L7OF(F1,1,&buf1);
    (*liredire)++;/**/
     while(i<=NbBloc)
     {
         liredir_L7OF(F,i,&buf);
         (*liredire)++;/**/

         for (j=0;j<buf.nb;j++)
         {
            if (buf.tab[j].efface==0)
                {
                  if (j1<nb_enr_max)
                  {
                     buf1.tab[j1]=buf.tab[j];
                     //________ table index : _________//
                        tab_ind[NG].cle=buf.tab[j].Matricule;
                        tab_ind[NG].NumBloc= i1;
                        tab_ind[NG].posBloc=j1;
                        tab_ind[NG].region= buf.tab[j].Region_Mi;
                        tab_ind[NG].DateN=buf.tab[j].Date_Nai;
                        tab_ind[NG].efface=0;



                      j1++ ;
                      NG++;
                  }
                  else {
                       buf1.nb = j1 ;
                       buf1.nbSup = 0;
                       buf1.suivant = i1+1;
                       ecriredir_L7OF(F1,i1,&buf1);
                       (*ecriredire)++; /**/
                       buf1.tab[0]=buf.tab[j];
                       i1++;

                        //________ table index : _________//
                        tab_ind[NG].cle=buf.tab[j].Matricule;
                        tab_ind[NG].NumBloc= i1;
                        tab_ind[NG].posBloc=0;
                        tab_ind[NG].region= buf.tab[j].Region_Mi;
                        tab_ind[NG].DateN=buf.tab[j].Date_Nai;
                        tab_ind[NG].efface=0;
                       j1=1;
                       NG++;
                  }
                }
         }
         j=0; i++;
     }

                       buf1.nb = j1 ;
                       buf1.nbSup = 0;
                       buf1.suivant = -1;
                       ecriredir_L7OF(F1,i1,&buf1);
                       (*ecriredire)++;/**/
                       aff_entete_L7OF(F1,1,i1);     //le nombre de bloc
                       aff_entete_L7OF(F1,2,NG);    //le nombre d'enregistrement
                       aff_entete_L7OF(F1,3,1);   //la tete
                       aff_entete_L7OF(F1,4,i1);  //la queue
                       aff_entete_L7OF(F1,5,j1);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F1,6,0);  //le nombre d'enregistrement supprimer
                       *taille_index = NG;
      fermer_L7OF(F);
      fermer_L7OF(F1);
        printf("   enregistrement supprimer avec succes :) vous povez acceder a votre noveau fichier ");
     textcolor(11);
     printf("%s",nom_fichiernew);
     textcolor(15);
            printf(" pour verifier les resultat \n\n");

}

/*
void supprision_physique( char nom_fichier[20],char nom_fichiernew[20]){


    L7OF  *F=ouvrir_L7OF(nom_fichier,'A');
    L7OF  *F1=ouvrir_L7OF(nom_fichiernew,'N');

    Buffer buf , buf1;
    int i =1;int i1 = 1;
    int j = 0;int j1 =0;
    int NbBloc=entete_L7OF(F,1);

    int NG1 =0 ;
    int n ; int ld=0 ;
      printf("\n\n   Veuillez introduire le nombre de bloc a affiche  ");
              textcolor(11);
              scanf("%d",&n);
              Affichage_fichier(nom_fichier ,&ld ,n);

//______________________________________________________________________________________________________________________//
    //___________________________//
     alloc_bloc_L7OF(F1);
     liredir_L7OF(F1,1,&buf1);

   //_____________________________//
     while(i<=NbBloc)
     {
         liredir_L7OF(F,i,&buf);

         for (j=0;j<buf.nb;j++)
         {
        //_______________________ pour le premier 1 : ________________________________//
            if (buf.tab[j].efface==0)
                {
                  if (j1<nb_enr_max)
                  {
                     buf1.tab[j1]=buf.tab[j];
                      j1++ ;
                      NG1++;
                  }
                  else {
                       buf1.nb = j1 ;
                       buf1.nbSup = 0;
                       buf1.suivant = i1+1;
                       ecriredir_L7OF(F1,i1,&buf1);

                       buf1.tab[0]=buf.tab[j];
                       i1++;
                       j1=1;
                       NG1++;

                  }
                }
        //__________________________________________________________________________//

         }
         j=0; i++;  //prochaine bloc
     }
                 //___________________________________________________________________________//
                       buf1.nb = j1 ;
                       buf1.nbSup = 0;
                       buf1.suivant = -1;
                       ecriredir_L7OF(F1,i1,&buf1);

                       aff_entete_L7OF(F1,1,i1);     //le nombre de bloc
                       aff_entete_L7OF(F1,2,NG1);    //le nombre d'enregistrement
                       aff_entete_L7OF(F1,3,1);   //la tete
                       aff_entete_L7OF(F1,4,i1);  //la queue
                       aff_entete_L7OF(F1,5,j1);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F1,6,0);  //le nombre d'enregistrement supprimer

      fermer_L7OF(F);
      fermer_L7OF(F1);
      printf("NG %d ",NG1);
       printf("\n\n   Veuillez introduire le nombre de bloc a affiche  ");
              textcolor(11);
              scanf("%d",&n);
              Affichage_fichier(nom_fichiernew,&ld ,n);

}*/
  //__________________________________________________________________________________________________________________________//
 //______________________________________ Recherche Matricule : _____________________________________________________________//
//__________________________________________________________________________________________________________________________//
void recher_matricule( table_index tab_ind[], int taille_index , int motrech , int *pos , int *bloc ,int *found , int *indice)
{
   // table_index tab_ind[200];
    int i=0 ;
   int trouv =0;

    while ( (trouv !=1) && (i<taille_index) )
    {
        if (( tab_ind[i].efface != 1)&&( tab_ind[i].cle == motrech))
        {

            *pos=tab_ind[i].posBloc;
            *bloc=tab_ind[i].NumBloc ;
            trouv = 1;
            *indice=i;

    }
        i++ ;
    }

    if (trouv==0)
    {   textcolor(11);
        printf("\n   cette matricule n'existe dans le fichier :( \n");
        textcolor(15);
        *pos=0;
        *bloc=0;
        *indice=0;
    }
    *found = trouv ;
}
  //_____________________________________________________________________________________________________________________________//
 //_____________________________Modification de la region militaire par matricule ______________________________________________//
//_____________________________________________________________________________________________________________________________//

void modifie_region_militaire( char nom_fichier[] , table_index tab_ind[], int taille_index , int matricule , int region ,int *liredire , int *ecriredire )
{

    int trouv=0 ; int pos , bloc , indice ;
    recher_matricule(tab_ind,taille_index, matricule ,&pos ,&bloc,&trouv,&indice); // on cherche d'abord la valeur dans l'index
    if (trouv==0){ // si elle n'existe pas
        printf("\n\n   modification impossible :( \n");
    }

    else { // si on trouve la matricule
      L7OF *F=ouvrir_L7OF(nom_fichier,'A'); // on ouvre le fichier
      Buffer buf ;
      liredir_L7OF(F,bloc,&buf); // on charge le buffer avec le bloc ou on vas insere modifie la region
              (*liredire)++;  /**/
      buf.tab[pos].Region_Mi= region ; // la nouvelle region
      tab_ind[indice].region=region;
      ecriredir_L7OF(F,bloc,&buf);
           (*ecriredire)++; /***/ // on recruiter des informations
      fermer_L7OF(F);
      textcolor(11);
      printf("             -->  modefication faite avec succes :) vous povez acceder a votre fichier pour verifier le resultat  <--\n\n");
      textcolor(15);
    }

}
  //______________________________________________________________________________________________________________//
 //_______________________________ Supprision par rapport a une force arme: _____________________________________//
//______________________________________________________________________________________________________________//
void Supprime_Force_Arme( table_index tab_ind[] , char nom_fichier[20] ,int taille_index, int F_Arme  ,int *liredire , int *ecriredire)
{
  Buffer buf;
  L7OF  *F=ouvrir_L7OF(nom_fichier,'A');
  int i=1; int j=0;   int Sup=0 , SupBloc =0;


  while(i<=entete_L7OF(F,1)){
    liredir_L7OF(F,i,&buf);
       (*liredire )++;/***/
    for (j=0;j<=buf.nb ;j++)
    {
        if((buf.tab[j].Force_Ar==F_Arme)&&(buf.tab[j].efface==0))
           {
             buf.tab[j].efface=1;
             Sup++ ;
             SupBloc++;
             //____________On doit maitre ajour la table d'index : ______________//

                 int irech=0 ;
                 int trouv =0;

              while ( (trouv !=1) && (irech<=taille_index) )
                   {
                  if (( tab_ind[irech].efface != 1)&&( tab_ind[irech].cle ==buf.tab[j].Matricule))
                     {
                       tab_ind[irech].efface=1;
                       trouv = 1;
                     }
                     irech++ ;// je passe a l'enregistrement suivant
                      }
            //________________________________________________________________________//

              }
         }
        //_______________________ on passe ou bloque suivant : ___________________//
             //--------- mais je doit maitre ajoure le dernier bloque -----------//
               buf.nbSup = buf.nbSup + Sup ;
               ecriredir_L7OF(F,i,&buf);
               (*ecriredire)++;
            //---- on prepare le terain pour la prochaine eteration ( bloc ) ---//
               j=0;
               i++;
               Sup=0;
      //_______________________________________________________________________//

  }
          aff_entete_L7OF(F , 6 , entete_L7OF(F,6)+SupBloc);
          fermer_L7OF(F);
}
//______________________________________________________________________________________________________________________________________________________//
//____________________________________________ affichage de conute de la table d'index _________________________________________________________________//
//______________________________________________________________________________________________________________________________________________________//
void affiche_table_index(table_index index[], int taille)
{   textcolor(11);
    printf("\tle contune de la table d'index :\n\n\n");
    textcolor(15);
    printf("\t  ======================================================================= \n ");
    printf("\t||  N |matricule | efface |  NumBloc  | posBloc|  region | date_Naissance||\n ");
    printf("\t||_______________________________________________________________________||\n ");
    printf("\t||                 la taille de l'index est %4d                         ||\n ",taille);
    printf("\t||_______________________________________________________________________||\n ");
    for (int i=0;i<taille;i++)
    {
        printf("\t||_______________________________________________________________________||\n ");

        printf("\t||%4d|  %6d  |   %d   |    %4d    |  %3d   |   %2d    |",i+1,index[i].cle,index[i].efface,index[i].NumBloc,index[i].posBloc , index[i].region);
                printf("  %4d/%2d/%2d   ||\n ",index[i].DateN.annee, index[i].DateN.jour ,index[i].DateN.mois);
    }
    printf("\t||_______________________________________________________________________||\n");
    printf("\t ==========================================================================\n");
}

void Fragmentation_region_militaire( char nom_fichier[20] ,char fichier1[20],char fichier2[20],char fichier3[20],char fichier4[20],char fichier5[20],char fichier6[20],int *liredire , int *ecriredire){


    L7OF  *F=ouvrir_L7OF(nom_fichier,'A');
    L7OF  *F1=ouvrir_L7OF(fichier1,'N');
    L7OF  *F2=ouvrir_L7OF(fichier2,'N');
    L7OF  *F3=ouvrir_L7OF(fichier3,'N');
    L7OF  *F4=ouvrir_L7OF(fichier4,'N');
    L7OF  *F5=ouvrir_L7OF(fichier5,'N');
    L7OF  *F6=ouvrir_L7OF(fichier6,'N');
    Buffer buf , buf1,buf2,buf3,buf4,buf5 ,buf6;
    int i =1;int i1 = 1,i2 = 1,i3 = 1,i4 = 1,i5 = 1,i6 = 1;
    int j = 0;int j1 =0, j2 =0, j3 =0, j4 =0,  j5 =0,j6 =0;
    int NbBloc=entete_L7OF(F,1);

    int NG1 =0 ,NG2 =0,NG3 =0,NG4 =0,NG5 =0,NG6 =0;


//______________________________________________________________________________________________________________________//
    //___________________________//
     alloc_bloc_L7OF(F1);
     liredir_L7OF(F1,1,&buf1);
          (*liredire)++;

     alloc_bloc_L7OF(F2);
     liredir_L7OF(F2,1,&buf2);
          (*liredire)++;

     alloc_bloc_L7OF(F3);
     liredir_L7OF(F3,1,&buf3);
          (*liredire)++;

     alloc_bloc_L7OF(F4);
     liredir_L7OF(F4,1,&buf4);
           (*liredire)++;

     alloc_bloc_L7OF(F5);
     liredir_L7OF(F5,1,&buf5);
           (*liredire)++;

     alloc_bloc_L7OF(F6);
     liredir_L7OF(F6,1,&buf6);
           (*liredire)++;
   //_____________________________//
     while(i<=NbBloc)
     {
         liredir_L7OF(F,i,&buf);
              (*liredire)++;
         for (j=0;j<buf.nb;j++)
         {
        //_______________________ pour le premier 1 : ________________________________//
            if (buf.tab[j].Region_Mi==1)
                {
                  if (j1<nb_enr_max)
                  {
                     buf1.tab[j1]=buf.tab[j];
                      j1++ ;
                      NG1++;
                  }
                  else {
                       buf1.nb = j1 ;
                       buf1.nbSup = 0;
                       buf1.suivant = i1+1;
                       ecriredir_L7OF(F1,i1,&buf1);
                       (*ecriredire)++;
                       buf1.tab[0]=buf.tab[j];
                       i1++;
                       j1=1;
                       NG1++;

                  }
                }
        //__________________________________________________________________________//

       //_______________________ pour le premier 2 : ________________________________//
            if (buf.tab[j].Region_Mi==2)
                {
                  if (j2<nb_enr_max)
                  {
                     buf2.tab[j2]=buf.tab[j];
                      j2++ ;
                      NG2++;
                  }
                  else {
                       buf2.nb = j2 ;
                       buf2.nbSup = 0;
                       buf2.suivant = i2+1;
                       ecriredir_L7OF(F2,i2,&buf2);
                       (*ecriredire)++;
                       buf2.tab[0]=buf.tab[j];
                       i2++;
                       j2=1;
                       NG2++;

                  }
                }
        //__________________________________________________________________________//
       //_______________________ pour le premier 3 : ________________________________//
            if (buf.tab[j].Region_Mi==3)
                {
                  if (j3<nb_enr_max)
                  {
                     buf3.tab[j3]=buf.tab[j];
                      j3++ ;
                      NG3++;
                  }
                  else {
                       buf3.nb = j3 ;
                       buf3.nbSup = 0;
                       buf3.suivant = i3+1;
                       ecriredir_L7OF(F3,i3,&buf3);
                       (*ecriredire)++;
                       buf3.tab[0]=buf.tab[j];
                       i3++;
                       j3=1;
                       NG3++;

                  }
                }
        //__________________________________________________________________________//
                //_______________________ pour le premier 4 : ________________________________//
            if (buf.tab[j].Region_Mi==4)
                {
                  if (j4<nb_enr_max)
                  {
                     buf4.tab[j4]=buf.tab[j];
                      j4++ ;
                      NG4++;
                  }
                  else {
                       buf4.nb = j4 ;
                       buf4.nbSup = 0;
                       buf4.suivant = i4+1;
                       ecriredir_L7OF(F4,i4,&buf4);
                       (*ecriredire)++;
                       buf4.tab[0]=buf.tab[j];
                       i4++;
                       j4=1;
                       NG4++;

                  }
                }
        //__________________________________________________________________________//
                //_______________________ pour le premier 5 : ________________________________//
            if (buf.tab[j].Region_Mi==5)
                {
                  if (j5<nb_enr_max)
                  {
                     buf5.tab[j5]=buf.tab[j];
                      j5++ ;
                      NG5++;
                  }
                  else {
                       buf5.nb = j5 ;
                       buf5.nbSup = 0;
                       buf5.suivant = i5+1;
                       ecriredir_L7OF(F5,i5,&buf5);
                       (*ecriredire)++;
                       buf5.tab[0]=buf.tab[j];
                       i5++;
                       j5=1;
                       NG5++;

                  }
                }
         //__________________________________________________________________________//

        //_______________________ pour le premier 6 : ________________________________//
            if (buf.tab[j].Region_Mi==6)
                {
                  if (j6<nb_enr_max)
                  {
                     buf6.tab[j6]=buf.tab[j];
                      j6++ ;
                      NG6++;
                  }
                  else {
                       buf6.nb = j6 ;
                       buf6.nbSup = 0;
                       buf6.suivant = i6+1;
                       ecriredir_L7OF(F6,i6,&buf6);
                       (*ecriredire)++;
                       buf6.tab[0]=buf.tab[j];
                       i6++;
                       j6=1;
                       NG6++;

                  }
                }
        //__________________________________________________________________________//

         }
         j=0; i++;  //prochaine bloc
     }
                 //___________________________________________________________________________//
                       buf1.nb = j1 ;
                       buf1.nbSup = 0;
                       buf1.suivant = -1;
                       ecriredir_L7OF(F1,i1,&buf1);
                       (*ecriredire)++;
                       aff_entete_L7OF(F1,1,i1);     //le nombre de bloc
                       aff_entete_L7OF(F1,2,NG1);    //le nombre d'enregistrement
                       aff_entete_L7OF(F1,3,1);   //la tete
                       aff_entete_L7OF(F1,4,i1);  //la queue
                       aff_entete_L7OF(F1,5,j1);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F1,6,0);  //le nombre d'enregistrement supprimer
                //___________________________________________________________________________//
                       buf2.nb = j2 ;
                       buf2.nbSup = 0;
                       buf2.suivant = -1;
                       ecriredir_L7OF(F2,i2,&buf2);
                       (*ecriredire)++;
                       aff_entete_L7OF(F2,1,i2);     //le nombre de bloc
                       aff_entete_L7OF(F2,2,NG2);    //le nombre d'enregistrement
                       aff_entete_L7OF(F2,3,1);   //la tete
                       aff_entete_L7OF(F2,4,i2);  //la queue
                       aff_entete_L7OF(F2,5,j2);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F2,6,0);  //le nombre d'enregistrement supprimer
                //___________________________________________________________________________//
                       buf3.nb = j3 ;
                       buf3.nbSup = 0;
                       buf3.suivant = -1;
                       ecriredir_L7OF(F3,i3,&buf3);
                       (*ecriredire)++;
                       aff_entete_L7OF(F3,1,i3);     //le nombre de bloc
                       aff_entete_L7OF(F3,2,NG3);    //le nombre d'enregistrement
                       aff_entete_L7OF(F3,3,1);   //la tete
                       aff_entete_L7OF(F3,4,i3);  //la queue
                       aff_entete_L7OF(F3,5,j3);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F3,6,0);  //le nombre d'enregistrement supprimer
                //___________________________________________________________________________//
                       buf4.nb = j4 ;
                       buf4.nbSup = 0;
                       buf4.suivant = -1;
                       ecriredir_L7OF(F4,i4,&buf4);
                       (*ecriredire)++;
                       aff_entete_L7OF(F4,1,i4);     //le nombre de bloc
                       aff_entete_L7OF(F4,2,NG4);    //le nombre d'enregistrement
                       aff_entete_L7OF(F4,3,1);   //la tete
                       aff_entete_L7OF(F4,4,i4);  //la queue
                       aff_entete_L7OF(F4,5,j4);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F4,6,0);  //le nombre d'enregistrement supprimer
               //___________________________________________________________________________//
                       buf5.nb = j5 ;
                       buf5.nbSup = 0;
                       buf5.suivant = -1;
                       ecriredir_L7OF(F5,i5,&buf5);
                       (*ecriredire)++;
                       aff_entete_L7OF(F5,1,i5);     //le nombre de bloc
                       aff_entete_L7OF(F5,2,NG5);    //le nombre d'enregistrement
                       aff_entete_L7OF(F5,3,1);   //la tete
                       aff_entete_L7OF(F5,4,i5);  //la queue
                       aff_entete_L7OF(F5,5,j5);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F5,6,0);  //le nombre d'enregistrement supprimer
               //___________________________________________________________________________//
                       buf6.nb = j6 ;
                       buf6.nbSup = 0;
                       buf6.suivant = -1;
                       ecriredir_L7OF(F6,i6,&buf6);
                       (*ecriredire)++;
                       aff_entete_L7OF(F6,1,i6);     //le nombre de bloc
                       aff_entete_L7OF(F6,2,NG6);    //le nombre d'enregistrement
                       aff_entete_L7OF(F6,3,1);   //la tete
                       aff_entete_L7OF(F6,4,i6);  //la queue
                       aff_entete_L7OF(F6,5,j6);  //l'indice libre dans le dernier bloc
                       aff_entete_L7OF(F6,6,0);  //le nombre d'enregistrement supprimer
      fermer_L7OF(F);
      fermer_L7OF(F1);
      fermer_L7OF(F2);
      fermer_L7OF(F3);
      fermer_L7OF(F4);
      fermer_L7OF(F5);
      fermer_L7OF(F6);

}
//____________________________________________________________________________________________________________//
//___________________ supprisson d'un enregistrement logiquement par matricule _______________________________//
//____________________________________________________________________________________________________________//
void supprimer_enre_logiquement( char nom_fichier[] , table_index tab_ind[], int taille_index , int matricule ,int *liredire , int *ecriredire)
{
      int trouv=0 ; int pos , bloc ;
      //___________recherche a l'interieur de l'index : __________________//
   int i=0 ;

    while ( (trouv !=1) && (i<taille_index) )
    {
        if (( tab_ind[i].efface != 1)&&( tab_ind[i].cle == matricule))
        {
            // lorque on trouve la valeur
            pos=tab_ind[i].posBloc;
            bloc=tab_ind[i].NumBloc ;
            trouv = 1;
            tab_ind[i].efface = 1 ; // on efface d'abord logiquement la valeur dans l'index
        }
        i++ ;
    }
        if (trouv==0){ // si on termine de boucle est en trouve pas de valeur
        textcolor(11);
        printf("\n\n   cette matricule n'existe dans le fichier :( \n");
        textcolor(15);
        }


        else { // si on trouve la matricule
          L7OF *F=ouvrir_L7OF(nom_fichier,'A'); // on ouvre le fichier
          Buffer buf ;
          liredir_L7OF(F,bloc,&buf);     // on charge le buffer avec le bloc ou en vas supprime l'information
          (*liredire)++;
          buf.tab[pos].efface= 1;
          buf.nbSup=buf.nbSup+1 ; // maitre ajoure l'information sup dans le bloc
          ecriredir_L7OF(F,bloc,&buf);
          (*ecriredire)++; /**/
          aff_entete_L7OF(F,6,entete_L7OF(F,6)+1); //maitre ajoure l'information sup dans l'entete
          fermer_L7OF(F);
          printf("\n\n   enregistrement supprimer avec succes :) vous povez acceder a votre fichier pour verifier les resultat \n\n");
    }
    // a suivre si on depasse un sertain nombre on fait une supprision physique
}


//____________________________________________________________________________________________________________//
void consult_Groupe_grade(char nom_fichier[20], int a , int b , int c , int d,int *liredire)
{
     L7OF  *F=ouvrir_L7OF(nom_fichier,'A');
     Buffer buf ;
     int i=1 , j=0;
                  textcolor(11);
             printf(" _________________________________________________________________________________________________________________________________________________________________ \n");

        textcolor(15);
        printf("|");
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
     while(i<entete_L7OF(F,1))
     {
         liredir_L7OF(F,i,&buf);
         (*liredire)++;
          for (j=0;j<buf.nb;j++)
          {
              if ((buf.tab[j].Grade==a)||(buf.tab[j].Grade==b)||(buf.tab[j].Grade==c)||(buf.tab[j].Grade==d))
              {
                         printf("| %6d  |%2d |",buf.tab[j].Matricule,buf.tab[j].efface);
            affiche_nom_nombre(buf.tab[j]);
            affiche_prenom_nombre(buf.tab[j]);

           printf("%4d/%2d/%2d|  %2d  |  %2d  |  %2d |  %2d |  %2d  | \n" , buf.tab[j].Date_Nai.annee,buf.tab[j].Date_Nai.mois,buf.tab[j].Date_Nai.jour,
                  buf.tab[j].wilaya_Nai,buf.tab[j].Groupe_S,buf.tab[j].Grade,buf.tab[j].Force_Ar,buf.tab[j].Region_Mi);
         }
          }
          i++;
          j=0;


     }
     printf("|");
             textcolor(11);
             printf("_________________________________________________________________________________________________________________________________________________________________");
            textcolor(15);
             printf("|\n");
     fermer_L7OF(F);
}

void consulter_groupe_gra(char nom_fichier[20], int *liredire){
    int choix; int stop =0 ; int ld =0;

    while(stop!=1){
            printf("\n\n\n");
    choix=menu2(6,"\t|      1- Affichage des grades qui font parti au groupe {Officiers-generaux}   |",
                  "\t|      2- Affichage des grades qui font parti au groupe {officiers-superieurs} |",
                  "\t|      3- Affichage des grades qui font parti au groupe {officiers}            |",
                  "\t|      4- Affichage des grades qui font parti au groupe {sous-officiers}       |",
                  "\t|      5- Affichage des grades qui font parti au groupe {hommes de troupes}    |",
                  "\t|      6- Quitter                                                              |");

    switch (choix)
    {
    case 1:
         printf("|      1- Affichage des grades qui font parti au groupe {Officiers-generaux} \n\n");
         consult_Groupe_grade(nom_fichier,1,2,3,3,&ld);
         system("PAUSE");
         system("cls");
        break;
    case 2:
         printf("\n\n      2- Affichage des grades qui font parti au groupe {officiers-superieurs} \n\n");
         consult_Groupe_grade(nom_fichier,4,5,6,6,&ld);
        system("PAUSE");
        system("cls");
        break;
    case 3:
         printf("\n\n      3- Affichage des grades qui font parti au groupe {officiers} \n\n");
         consult_Groupe_grade(nom_fichier,7,8,9,10,&ld);
        system("PAUSE");
              system("cls");
        break;
    case 4:
         printf("\n\n      4- Affichage des grades qui font parti au groupe {sous-officiers} \n\n");
         consult_Groupe_grade(nom_fichier,11,12,13,14,&ld);
         system("PAUSE");
              system("cls");
        break;
    case 5:
         printf("\n\n     5- Affichage des grades qui font parti au groupe {hommes de troupes} \n\n");
         consult_Groupe_grade(nom_fichier,15,16,17,17,&ld);
         system("PAUSE");
              system("cls");
        // stop =1;
        break;
    case 6 :
        stop =1;
        break;

    }
    }
     (*liredire)=ld;
}

void consulte_region_militaire( char nom_fichier[20],int taille_index ,table_index index[],int  annee_actuale ,int age1,int  age2 ,int  region, int *lirdr )
{
             Buffer buf ;
             L7OF *F=ouvrir_L7OF(nom_fichier,'A');
             int age_extrait ;
             textcolor(11);
             printf(" _________________________________________________________________________________________________________________________________________________________________ \n");

        textcolor(15);
        printf("|");
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
           int cpt=0;
             for (int i=0; i<taille_index ;i++ )
             {
                 if ((index[i].region==region)&& (index[i].efface==0))
                 {
                     age_extrait=(annee_actuale)-index[i].DateN.annee;

                     if (((age1)>=(age_extrait))||((age_extrait)<=(age2)))
                     {
                         liredir_L7OF(F,index[i].NumBloc,&buf);
                         (*lirdr)++;

                            printf("| %6d  |%2d |",buf.tab[index[i].posBloc].Matricule,buf.tab[index[i].posBloc].efface);
                            affiche_nom_nombre(buf.tab[index[i].posBloc]);
                           affiche_prenom_nombre(buf.tab[index[i].posBloc]);

                    printf("%4d/%2d/%2d|  %2d  |  %2d  |  %2d |  %2d |  %2d  | \n" , buf.tab[index[i].posBloc].Date_Nai.annee,buf.tab[index[i].posBloc].Date_Nai.mois,buf.tab[index[i].posBloc].Date_Nai.jour,
                          buf.tab[index[i].posBloc].wilaya_Nai,buf.tab[index[i].posBloc].Groupe_S,buf.tab[index[i].posBloc].Grade,buf.tab[index[i].posBloc].Force_Ar,buf.tab[index[i].posBloc].Region_Mi);


                         cpt++;
                         (*lirdr)++;

                     }
                 }
             }
             printf("|");
             textcolor(11);
             printf("_________________________________________________________________________________________________________________________________________________________________");
            textcolor(15);
             printf("|\n");
             if (cpt==0){
                    textcolor(15);
                printf("\n\n\n\n     ---> aucune personne n'appartient a  region militaire ");
                textcolor(11);
                printf("%d",region);
                textcolor(15);
                printf(" :( \n\n");
             textcolor(15);
             }
             fermer_L7OF(F);
}

