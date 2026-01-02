//Morpion
#include <iostream>
#include "morpion.h"
using namespace std;

// Initialiser la grille
void initialiserGrille(char grille[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grille[i][j] = '.';
}

// afficher la grille
void affichergrille(char grille[10][10],int n)
{
    for(int i= 0;i<n;i++){
        for (int j = 0 ;j<n;j++){
            cout << grille[i][j] << " | ";
        }
        cout << endl;
        for (int k = 0; k < n; k++) cout << "----";
        cout << endl;
    }
}

char choisirSymboleJoueur1() {
    char choix;
    cout << "Joueur 1, choisis X ou O : ";
    cin >> choix;
    if (choix == 'X' || choix == 'x') return 'X';
    return 'O';
}

char alterner_joueur(char joueur1,char joueur_actuel,char ordi){
    if(joueur_actuel == joueur1){
        return ordi;
    }
    else {
        return joueur1;
    }
}

// Choisir case
int choisirCase(int n) {
    int c;
    cout << "Choisis une case (1 a " << n * n << ") : ";
    cin >> c;
    return c;
}

//Placer symbole
bool placerSymbole(char grille[10][10], int caseChoisie, int n, char joueur) {
    if (caseChoisie < 1 || caseChoisie > n * n) {
        cout << "Choix invalide !" << endl;
        return false;
    }

    int ligne = (caseChoisie - 1) / n;
    int colonne = (caseChoisie - 1) % n;

    if (grille[ligne][colonne] != '.') {
        cout << "Case déjà occupée !" << endl;
        return false;
    }

    grille[ligne][colonne] = joueur;
    return true;
}

bool checkWin(char grille[10][10], int n, int K, char joueur){

    // Horizontale
    for (int i=0;i<n;i++){
        int compteur = 0;
        for(int j=0;j<n;j++){
            if(grille[i][j]==joueur){
                compteur++;
                }
            else {
                    compteur = 0;
            }
            if (compteur == K) return true;
        }
    }

    // Verticale
    for (int j=0;j<n;j++){
        int compteur = 0;
        for(int i=0;i<n;i++){
            if(grille[i][j]==joueur) compteur++;
            else compteur = 0;
            if (compteur == K) return true;
        }
    }

    // diagonale ↘
    for (int i = 0; i <= n - K; i++) {
        for (int j = 0; j <= n - K; j++) {
            int compteur = 0;
            for (int k = 0; k < K; k++) {
                if (grille[i + k][j + k] == joueur) compteur++;
                else break;
            }
            if (compteur == K) return true;
        }
    }

    // diagonale ↙
    for (int i = 0; i <= n - K; i++) {
        for (int j = K - 1; j < n; j++) {
            int compteur = 0;
            for (int k = 0; k < K; k++) {
                if (grille[i + k][j - k] == joueur) compteur++;
                else break;
            }
            if (compteur == K) return true;
        }
    }

    return false;
}
namespace morpion {
void lancer() {
    cout << "Bienvenue dans le jeu de Morpion" << endl;

    int n;
    int K;
    int caseChoisie;
    int tour = 0;
    bool jeu_en_cours = true;
    char grille[10][10];

    cout << "Entrer la taille N de la grille : ";
    cin >> n;

    cout << "Entrer K symboles à aligner : ";
    cin >> K;

    // initialisation
    initialiserGrille(grille, n);

    char joueur1 = choisirSymboleJoueur1();
    char ordi ;
         if (joueur1 == 'X') {
             ordi = 'O';
                      }
         else {
             ordi = 'X';
              }


    char joueur_actuel = joueur1;

    while (jeu_en_cours) {

        affichergrille(grille, n);

        if (joueur_actuel == joueur1) {
            caseChoisie = choisirCase(n);
        }
        else {
            cout << "L'ordinateur joue"<<endl;



// pc test chaque case
            for (int i = 1; i <= n*n; i++) {
                int ligne = (i - 1) / n;
                int colonne = (i - 1) % n;

                if (grille[ligne][colonne] == '.') {
                    caseChoisie = i;
                    break;
                }
            }
        }
        if (!placerSymbole(grille, caseChoisie, n, joueur_actuel)) {
            continue;
        }
        if (checkWin(grille, n, K, joueur_actuel)) {
            affichergrille(grille, n);
            cout << "Le joueur " << joueur_actuel << " gagne !" << endl;
            break;
        }
        tour++;
        if (tour == n*n) {
            cout << "Match nul !" << endl;
            break;
        }
        joueur_actuel = alterner_joueur(joueur1, joueur_actuel, ordi);
    }

}
}
