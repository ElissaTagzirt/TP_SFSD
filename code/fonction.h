#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#define max1 98 // la taille d'un seul bloc est 8504 donc
                //le nombre d'enregistrement dans un seul bloc est : ((8504-24) div 86) = 98
  //_______________________________________________________________________________//
 //*********************declaration des types ************************************//
//_______________________________________________________________________________//


typedef struct NomPrenom   //30 ocetet
{
    int Nom[15];//15octet
    int taillenom ;
    int  Prenom[15];  //15octet
    int tailleprenom ;
}NomPrenom;

typedef struct DateNaissance  //12octet
{
    int annee;     //4octet
    int mois;     //4octet
    int jour;    //4octet
}DateNaissance;

typedef struct Tenreg                                                                            //totale : 74 octet
{
    int efface ; //booleen pour la suppression logique 0: non supprime 1: supprime            //4octet
    int Matricule;                                                                           //8octet
    int Groupe_S;                                                                           //4octet
    NomPrenom Nom_prenom ; //un enregistrement divise en deux champ  le nom et le prenom   //30octet
    int wilaya_Nai;                                                                       //4octet
    DateNaissance Date_Nai; //un enregistrement divise en trois champ annee mois jour    //12octet
    int Grade;                                                                          //4octet
    int Force_Ar;                                                                      //4octet
    int Region_Mi ;                                                                   //4octet

}Tenreg;
typedef struct Tbloc                                                         //totale : 86octet
{
    Tenreg tab[max1]; // le tableau de d'enregistrement                     //74ocete
    int suivant;    // le numero du bloc suivant dans la liste            //4octet
    int nb ;       // le nombre d'eregistrement dans tab ( <= max )      //4octet
    int nbSup ;   //le nombre d'enregistrement supprime dans un bloc    //4octet
}Tbloc;


typedef struct Tbloc Buffer ; // declaration du tampon

typedef struct Entete_L7OF                                                                                   //totale : 24octet
{
    int NbBloc ;                                                                                     //4octet
    int NbEnregistrement ; // le nombre d'enregistrement occupe                                     //4octet
    int Tete ;                                                                                     //4octet
    int Queue ;                                                                                   //4octet
    int indice_libre ;  //l'indice libre dans le bloc de dernier bloc la queue                   //4octet
    int NBsupp ;       //le nombre d'enregistrements supprimer                                  //4octet
}Entete_L7OF;

typedef struct L7OF
{
    FILE *fich ;
    Entete_L7OF Entete_L7OF;
}L7OF ;
//_________________________________________________________________________________________//
//______________________________sctructeur d'une case addresse : _____________________________________________________
/*typedef struct  ADR   //8 octet
{
    int NumBloc ;  //le numero du maillon (position i)                    //4octet
    int posBloc ;  //la position a l'interieur d'un bloc (position j)     //4octet

} ADR ;*/

//____________________________________________________________________________________________________________________


//_______________________________  sctructeur d'une seule case index : _______________________________________________
typedef struct table_index
{
     int efface ; //booleen pour la suppression logique (1: oui , 0:non)    //4octet
     int  cle;                                                             //4octet
     int NumBloc ;  //le numero du maillon (position i)                    //4octet
     int posBloc ;
     int region ;
     DateNaissance DateN ;

                                                        //8octet

}table_index ;

 //______________________________________________________________________________________________________________________//
typedef struct type {

            char nom [20];
            int num;
             } type;
//___________________________________ LES ENTETS DES MACHINE ABSTRAITE : _______________________________________________//

void aff_entete_L7OF(L7OF *fichier,int i , int valeur);
int  entete_L7OF(L7OF *fichier, int i);
void liredir_L7OF(L7OF *fichier, int i , Buffer *buf);
void ecriredir_L7OF(L7OF *fichier, int i, Buffer *buf);
L7OF *ouvrir_L7OF(char nom_fichier[], char mode);
void fermer_L7OF(L7OF *fichier);
void alloc_bloc_L7OF(L7OF *fichier);
//____________________________________________________________________________________________________________________//

int nb_aleatoire(int inf,int sup);
void turn_to_string(char chaine[], int n, int longueur);
void affichage(Tenreg enreg);
void enreg_aleat(Tenreg *enreg);
int nb_aleatoire(int inf,int sup);
void generer_nom_prenon(char n[15]);
void chargement_initial(char nom_fichier[20], int n ,table_index tab_ind[] , int *liredire , int *ecriredire );/***/
//----------------------------------------------------------------------------------------------------------------//
void Affichage_bloc(L7OF* fichier, int b);
void Affichage_fichier(char fichier[20],int *lirdire , int nb);
void Affichage_fichier1(char fichier[20], int *lirdire , int nb);
 void aff_fichier(char nom_fichier[20],int *lirdire);
void affiche_nom_nombre(Tenreg enreg);
 void affiche_prenom_nombre(Tenreg enreg);
void conversion_caracter(int car);
void affiche_nom_caractere(Tenreg enreg);
void affiche_prenom_caractere(Tenreg enreg);
void affiche_table_index(table_index index[], int taille);
void force_armee(int num);
void grade(int num);
void wilaya(int num);
void groupe_sanguin(int num);
//----------------------------------------------------------------------------------------------------------------//
void suppr_doublons(char nom_fichier[20], table_index tab_ind[], int taille_tab , int *liredire , int *ecriredire);/**/
void supprision_physique( char nom_fichier[20],char nom_fichiernew[20],table_index tab_ind[] , int *taille_index ,int *liredire , int *ecriredire);/**/
void supprimer_enre_logiquement( char nom_fichier[] , table_index tab_ind[], int taille_index , int matricule ,int *liredire , int *ecriredire);/**/
void Supprime_Force_Arme( table_index tab_ind[] , char nom_fichier[20] ,int taille_index, int F_Arme  ,int *liredire , int *ecriredire);/**/
void modifie_region_militaire( char nom_fichier[] , table_index tab_ind[], int taille_index , int matricule , int region ,int *liredire , int *ecriredire );/**/
//----------------------------------------------------------------------------------------------------------------//
void recher_matricule( table_index tab_ind[], int taille_index , int motrech , int *pos , int *bloc ,int *found ,int *indice);/**/
//----------------------------------------------------------------------------------------------------------------//
void insert_novelle_matricule( char nom_fichier[] , table_index tab_ind[], int taille_index , int *liredire , int *ecriredire);
void Fragmentation_region_militaire( char nom_fichier[20] ,char fichier1[20],char fichier2[20],char fichier3[20],char fichier4[20],char fichier5[20],char fichier6[20],int *liredire , int *ecriredire);
//---------------------------------------------------------------------------------------------------------------//
void consulte_region_militaire( char nom_fichier[20],int taille_index ,table_index index[],int  annee_actuale ,int age1,int  age2 ,int  region, int *lirdr);/***/

void consulter_groupe_gra(char nom_fichier[20], int *liredire ); /***/
void consult_Groupe_grade(char nom_fichier[20], int a , int b , int c , int d,int *liredire);/***/

//void epuration_fichier(char nom_fichier[20],table_index tab_ind[] , int taille_index);
//______________________________________________________________________________________//


void force_armee(int num);
void grade(int num);
void wilaya(int num);
void groupe_sanguin(int num);

#endif // FONCTION1_H_INCLUDED

