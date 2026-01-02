// Bataille de navale

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "bataille_navale.h"
using namespace std ;

void initialisation_hasard(){
    srand(time(0)); //Démarre la suite de nombres aléatoires à une position différente à chaque exécution
}
void remplirgrille(char grille[10][10]){
    for (int i =0 ; i<10;i++){
        for (int j =0;j<10;j++){
            grille [i][j]= '.';
        }
    }
}

void affichergrille(char grille[10][10]) {

    // Afficher les numéros de colonnes 1 à 10
    cout << "  ";
    for (int j = 1; j <= 10; j++) {
        cout << j << " ";
    }
    cout << endl;

    // Afficher les lignes A à J
    for (int i = 0; i < 10; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < 10; j++) {
            cout << grille[i][j] << " ";
        }
        cout << endl;
    }
}


void placebateau_ordi(char grille [10][10],int taille){
    int ligne=rand() %10 ;
    int colonne=rand() %10 ;
    while (grille[ligne][colonne] == 'B'){
        ligne=rand() %10 ;
        colonne=rand() %10 ;
        }
        grille[ligne][colonne] = 'B';
    }

void placebateau_joueur(char grille [10][10],int taille) {
    char lettre;
    int chiffre;
    cout<<"Donne une case (exemple : A3, B7, J10) :"<<endl;

//  Lire la lettre
    cin>>lettre;
    while(lettre <'A' || lettre > 'J'){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>lettre;
    }

// Lire le chiffre
    cin>>chiffre;
    while(cin.fail() || chiffre < 1 || chiffre > 10){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>chiffre;
    }

// Conversion
        int ligne = lettre - 'A';
        int colonne = chiffre -1;

// Verifier si la case est occupée
    while (grille[ligne][colonne] == 'B'){
        cout<<"choisis une nouvelle case"<<endl;

        cin>>lettre;
        while(lettre <'A' || lettre > 'J'){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>lettre;
    }

    cin>>chiffre;
    while(chiffre < 1 || chiffre > 10){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>chiffre;
        }

        ligne = lettre - 'A';
        colonne = chiffre -1;
    }

// Placer le tableau
    grille[ligne][colonne] = 'B';
}

void tir_joueur(char grille [10][10],int taille){
    char lettre;
    int chiffre;
    cout<< "Choisis une case à tirer (exemple : A3, C9, J10) :" <<endl;
    cin>>lettre ;
    while (lettre < 'A' || lettre > 'J'){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>lettre ;
    }
    cin>>chiffre ;
    while (chiffre < 1 || chiffre > 10){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>> chiffre ;
    }

    int ligne = lettre - 'A' ;
    int colonne = chiffre - 1 ;

// Verifier si la case contient B alors on tire

while (grille[ligne][colonne]=='X'|| grille[ligne][colonne]=='O')
    {
    cout<<"tu as déja tiré ici redemarre"<<endl;
     cin>>lettre;
        while(lettre <'A' || lettre > 'J'){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>lettre;
        }
         cin>>chiffre;
    while(chiffre < 1 || chiffre > 10){
        cout<<"redemarre"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin>>chiffre;
        }
        ligne = lettre - 'A';
        colonne = chiffre -1;
    }
//Tirer

if(grille[ligne][colonne]=='B'){
    grille[ligne][colonne]='X' ;
    cout<<"Touché"<<endl;
}
else{
    grille[ligne][colonne]='O' ;
    cout<<"A l'eau"<<endl;
}
}

void tir_ordi(char grille [10][10],int taille){
     int ligne=rand() %10 ;
     int colonne=rand() %10 ;
  while (grille[ligne][colonne]=='X'|| grille[ligne][colonne]=='O')
    {
        cout<<"choisir une nouvelle case"<<endl;
        ligne=rand() %10 ;
        colonne=rand() %10 ;
    }
    if(grille[ligne][colonne]=='B'){
    grille[ligne][colonne]='X' ;
    cout<<"Touché"<<endl;
}
else{
    grille[ligne][colonne]='O' ;
    cout<<"A l'eau"<<endl;
}
}

int compter_bateaux(char grille [10][10],int taille){
    int compteur =0;
    for (int i =0 ; i<10;i++){
        for (int j =0;j<10;j++){
            if (grille[i][j]=='B'){
                compteur ++;
            }
        }
    }
    return compteur;
}

void affichergrille_cachee(char grille[10][10]) {
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if (grille[i][j] == 'B')
                cout << ". ";
            else
                cout << grille[i][j] << " ";
        }
        cout << endl;
    }
}
namespace bataille_navale {
void lancer() {
    cout<<" Bienvenue dans le jeu bataille de navale ! "<<endl;
    cout<<" Bonne chance capitaine ! " <<endl;
    cout<<" Coulez tous les bateaux ennemis ! " << endl;

    initialisation_hasard();

    char grilleJoueur[10][10];
    char grilleOrdi[10][10];
    remplirgrille(grilleJoueur);
    remplirgrille(grilleOrdi);

    cout << "grille de joueur :" <<endl;
    affichergrille(grilleJoueur);



    for (int i=1;i<=5;i++){
            placebateau_ordi(grilleOrdi,1);
        }
cout << "Tu as 5 bateaux a placer. Choisis leur position !" << endl;
    for (int i=1;i<=5;i++){
            cout<<"Placement du bateau"<<i<< " sur 5 : " <<endl;
            placebateau_joueur(grilleJoueur,1);
            affichergrille(grilleJoueur);
        }

        cout << "Grille de l'ordinateur :" << endl;
    affichergrille_cachee(grilleOrdi);

    while(compter_bateaux(grilleJoueur,1)>0 && compter_bateaux(grilleOrdi,1)>0){
        cout << "TOUR DU JOUEUR"<<endl;
    tir_joueur(grilleOrdi, 1);

    cout << "TOUR DE L'ORDINATEUR"<<endl;
    tir_ordi(grilleJoueur, 1);

    cout << "Grille de l'ordinateur"<<endl;
    affichergrille_cachee(grilleOrdi);

    cout << "Grille du joueur"<<endl;
    affichergrille(grilleJoueur);
    cout << "Bateaux restants - Joueur : "
     << compter_bateaux(grilleJoueur,1)
     << " | Ordinateur : "
     << compter_bateaux(grilleOrdi,1)
     << endl;


    }
    if (compter_bateaux(grilleOrdi,1) == 0) {
    cout << "BRAVO ! Tu as gagné ! Tous les bateaux ennemis sont détruits";
}
else {
    cout << "L'ordinateur a gagné... Tous tes bateaux sont coulés";
}

}
}



























