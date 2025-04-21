#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include"fonction.h"

int ldir=0 ;
int edir=0;
//*********************************************LES_MODULES*********************************************************************//
//___________________________________________________________________________________________________________________
//_________permet de mettre a jour les elements de l'entete du ficher_____________//
    void aff_entete_L7OF(L7OF *fichier,int i , int valeur)
{

    switch(i)
    {
        case 1:
        {
            fichier->Entete_L7OF.NbBloc=valeur; // nombre total de bloc allou�s dans le fichier
        }break;
        case 2:
        {
            fichier->Entete_L7OF.NbEnregistrement=valeur;  // numero du bloc representatnt la tete du fichier
        }break;
         case 3:
        {
            fichier->Entete_L7OF.Tete=valeur;  // numero du bloc representatnt la tete du fichier
        }break;
         case 4:
        {
            fichier->Entete_L7OF.Queue=valeur;  // numero du bloc representatnt la queue du ficheir
        }break;
         case 5:
        {
            fichier->Entete_L7OF.indice_libre=valeur; // la postion libre dans le bloc de queue
        }break;
         case 6:
        {
            fichier->Entete_L7OF.NBsupp=valeur;  // le nombre de bloc supprime dans logiquement

        }break;

    };
}

 //____________________________________________________________________________________________//
//______________Role :permet d'obtenir les elements de l'entete du ficher_____________________//
  int entete_L7OF(L7OF *fichier, int i)

{

    switch(i)
    {
        case 1:
        {
            return(fichier->Entete_L7OF.NbBloc);
        }break;
          case 2:
        {
            return(fichier->Entete_L7OF.NbEnregistrement);
        }break;
         case 3:
        {
            return(fichier->Entete_L7OF.Tete);
        }break;
         case 4:
        {
            return(fichier->Entete_L7OF.Queue);
        }break;
         case 5:
        {
            return(fichier->Entete_L7OF.indice_libre);
        }break;
         case 6:
        {
            return(fichier->Entete_L7OF.NBsupp);
        }break;

    };
   return 0 ;
}

 //__________________________________________________________________________________________________ //
//_______________ROLE: lecteur du bloc num i du fichier fichier dans la variable buf________________ //
    void liredir_L7OF(L7OF *fichier, int i , Buffer *buf)
{

 fseek(fichier->fich,(sizeof(Entete_L7OF)+sizeof(Tbloc)*(i-1)),SEEK_SET); // positionnement au debut du bloc numero i
 fread(buf,sizeof(Buffer),1,fichier->fich);                         //lecture d'un bloc de caract�re correspondant a la taille du bloc dans le buffer
 rewind(fichier->fich);                                            // repositionnement endebut de fichier
    ldir++;
}



 //__________________________________________________________________________________________________ //
//_______________ROLE: Ecriteur du bloc num i du fichier fichier dans la variable buf________________ //
void ecriredir_L7OF(L7OF *fichier, int i, Buffer *buf)
{

     fseek(fichier->fich,sizeof(Entete_L7OF)+sizeof(Tbloc)*(i-1),SEEK_SET); // positionnement au debut du bloc numero i
     fwrite(buf,sizeof(Buffer),1,fichier->fich);                       //ecriture du contenu du buffer dans le bloc numero i du fichier
     edir++;
}



 //______________________________________________________________________________________________________ //
//_______________ROLE: ouverture ou creation d'un nouveau fichier sur le nom nom_fichier ________________ //
L7OF *ouvrir_L7OF(char nom_fichier[], char mode)
{

    L7OF *fichier=malloc(sizeof(L7OF));                      // allocation  de la structure
    Buffer buf;
    if( (mode=='A') ||  (mode == 'a') )                        // mode ancien // lecteur et ecriteur
    {
        fichier->fich=fopen(nom_fichier,"rb+");               // ouverture du fichier en mode binaire lecture et ecriture
        fread(&(fichier->Entete_L7OF),sizeof(Entete_L7OF),1,fichier->fich);  // chargement de l'entete enregistr�e en debut de fichier
    }
    else
    {
        if( (mode=='N') ||  (mode == 'n') )                   // mode nouveau = ecriteur
        {
             fichier->fich=fopen(nom_fichier,"wb+");         // ouverture du fichier en mode binaire  ecriture
             aff_entete_L7OF(fichier,1,0);                         // mise a zeo du nombre de bloc si entete(fichier,1)=0 alors le fichier est vide
             aff_entete_L7OF(fichier,2,0);                         //le nombre d'enregistrement initiale est 0
             aff_entete_L7OF(fichier,3,1);                         // mettre tete au premier bloc
             aff_entete_L7OF(fichier,4,1);                         // de meme pour la queue puisque au debut tete est queue sont confondues
             aff_entete_L7OF(fichier,5,0);                         // le premier enregistrement du ficheir correspond a la position libre puisqu'il est nouveau
             aff_entete_L7OF(fichier,6,0);                         // aucun enregistrement n'est encore  supprim�
             fwrite(&(fichier->Entete_L7OF),sizeof(Entete_L7OF),1,fichier->fich);// enregistrement de l'entete dans le fichier
             buf.suivant=-1;                                 // le suivant du premier bloc a NULL
//             sprintf(buf.tab,"%s","");                       // initialisation du buffer a chaine vide
             ecriredir_L7OF(fichier,1,&buf);                      // ecriture du premier bloc dans le fichier


        }
        else                                                // format d'ouverture incorrecte
        {
            printf("format d'ouverture impossible");
        }
    }
    return(fichier);                                       // renvoyer la structure cr��e
}


 //__________________________________________________________________________________________________ //
//_______________ROLE: fermeture de fichier ________________ //

void fermer_L7OF(L7OF *fichier)
{
    rewind(fichier->fich); // repositionnement du curseur en debut de fichier
    fwrite(&(fichier->Entete_L7OF),sizeof(Entete_L7OF),1,fichier->fich); // sauvegarde de la derni�re version de l'entete de la strucuture L7OF
                                                                      //dans le fichier
    rewind(fichier->fich);// repositionnement du curseur en debut de fichier
    fclose(fichier->fich);// fermeture du fichier

}



//-------------------------------------permet d'allouer un nouveau bloc dans le ficiher et de maettre a jour les caract�ristiques des bloc eet de l'entete touch�s------------------------------//
void  alloc_bloc_L7OF(L7OF *fichier)
{

        Buffer *buf=malloc(sizeof(Buffer));       // allocation du Buffer

        liredir_L7OF(fichier,entete_L7OF(fichier,4),buf);   // lecture du bloc correspondant a la queue
        buf->suivant=entete_L7OF(fichier,1)+1;         // mise a jour du suivant de la queue au bloc correspondant a la nouvelle queue
        ecriredir_L7OF(fichier,entete_L7OF(fichier,4),buf);// ecriture du bloc de queue dans le fichier
        aff_entete_L7OF(fichier,4,entete_L7OF(fichier,1)+1);// mise a jour du numero du bloc correspondant a la nouvelle queue dan sl'entete
        buf->suivant=-1; // mise a jour du suivant a nill

//        sprintf(buf->tab,"%s","");               // vider la chaine du buffer
        ecriredir_L7OF(fichier,(entete_L7OF(fichier,4)),buf);// ecriture du buffer dans le bloc representatnt la nouvelle queue
        aff_entete_L7OF(fichier,1,entete_L7OF(fichier,1)+1);// incr�mentation du nombre de bloc allou�s

}

