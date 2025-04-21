# TP 2 – Structures simples de fichiers (Méthode « LObarreF »)


---

## 📋 Description

Ce projet est la réalisation du **Travail Pratique** du cours de Structures de fichiers, portant sur la méthode **LObarreF** (Liste non Ordonnée à enregistrements de taille Fixe).  
L’objectif est de manipuler un fichier binaire (`PERSONNEL-ANP_DZ.bin`) représentant le personnel actif de l’Armée Nationale Populaire, avec :

- Une organisation en blocs de 1 024 octets.  
- Des enregistrements composés de 9 champs (`Matricule`, `Nom`, `Prénom`, `Date_Naissance`, `Wilaya_Naissance`, `Groupe_Sanguin`, `Grade`, `Force_Armée`, `Région_Militaire`).  
- Un index en mémoire centrale pour accélérer les requêtes.

---

## 🚀 Fonctions et modules implémentés

1. **Machine Abstraite L7OF**  
   - `ouvrir_L7OF`, `fermer_L7OF`  
   - `liredir_L7OF`, `ecriredir_L7OF`  
   - `aff_entete_L7OF`, `entete_L7OF`  
   - `alloc_bloc_L7OF`

2. **Chargement initial**  
   - `chargement_initial`  
   - Génération aléatoire des enregistrements (avec contrôles date, wilaya, groupe sanguin, grade, force et région militaire)

3. **Épuration du fichier**  
   - `suppr_doublons` (suppression logique des doublons)  
   - `supprision_physique` (recréation physique du fichier sans les enregistrements supprimés)

4. **Opérations CRUD**  
   - **Insertion** : `insert_novelle_matricule`  
   - **Modification** : `modifie_region_militaire`  
   - **Suppression logique** : `supprimer_enre_logiquement`  
   - **Suppression par critère** :  
     - `Supprime_Force_Arme` (tous les enregistrements d’une force donnée)  
     - `supprision_physique` (suppression physique des logs)

5. **Requêtes et fragmentation**  
   - `consulte_region_militaire` (âge et région)  
   - `consult_Groupe_grade` (par catégorie de grades)  
   - `Fragmentation_region_militaire` (six fichiers, un par région militaire)

6. **Affichages et statistiques**  
   - `Affichage_fichier`, `Affichage_fichier1`, `Affichage_bloc`  
   - `affiche_table_index`  
   - Compte des opérations `LIREDIRE` / `ECRIREDIRE` et représentation graphique des trois premiers blocs

