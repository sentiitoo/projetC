#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool absentSurLigne (int k, int grille[9][9], int i)
{
    for (int j=0; j < 9; j++)
        if (grille[i][j] == k)
            return false;
    return true;
}
bool absentSurColonne (int k, int grille[9][9], int j)
{
    for (int i=0; i < 9; i++)
        if (grille[i][j] == k)
            return false;
    return true;
}

bool absentSurBloc (int k, int grille[9][9], int i, int j)
{
    int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
    for (i=_i; i < _i+3; i++)
        for (j=_j; j < _j+3; j++)
            if (grille[i][j] == k)
                return false;
    return true;
}

bool estValide (int grille[9][9], int position)
{
    if (position == 9*9)
        return true;

    int i = position/9, j = position%9;

    if (grille[i][j] != 0)
        return estValide(grille, position+1);

    for (int k=1; k <= 9; k++)
    {
        if (absentSurLigne(k,grille,i) && absentSurColonne(k,grille,j) && absentSurBloc(k,grille,i,j))
        {
            grille[i][j] = k;

            if ( estValide (grille, position+1) )
                return true;
        }
    }
    grille[i][j] = 0;

    return false;
}


void lire_grille_fichier(int grille[9][9])
{
    FILE *fichier = fopen("C:\\Users\\rabdo\\Desktop\\C\\sudoku.txt", "r"); 
    if (fichier == NULL) 
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char c = fgetc(fichier); //lire un caractère du fichier
            
            while (c == '\n' || c == '\r') //passer les caractères de fin de ligne
            {
                c = fgetc(fichier);
            }
            
            grille[i][j] = c - '0'; 
        }
    }
    
    fclose(fichier);

    //affichage de la grille esthetique
    puts("|-----------------|");
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
        if (j == 0) {
            putchar('|');
        }
            printf( ((j+1)%3) ? "%d " : "%d|", grille[i][j]);
        }
        putchar('\n');
        if (!((i+1)%3))
            puts("|-----------------|");
    }
    puts("\n");
}

void lire_grille(int grille[9][9])
{
    //affichage de la grille esthetique
    puts("|-----------------|");
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
        if (j == 0) {
            putchar('|');
        }
            printf( ((j+1)%3) ? "%d " : "%d|", grille[i][j]);
        }
        putchar('\n');
        if (!((i+1)%3))
            puts("|-----------------|");
    }
    puts("\n");
}

int main()
{
    int grille[9][9];
    printf("\nVoici la grille sudoku du fichier :\n\n");
    lire_grille_fichier(grille);
    printf("Voici la grille sudoku apres resolution :\n\n");
    estValide(grille,0);
    lire_grille(grille);
    
    return 0;
}