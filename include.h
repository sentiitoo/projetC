#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void gd_pustr(char *str);

int gd_atoi(char *str);

#define VRAI 1
#define FAUX 0
typedef int BOOLEAN;

typedef struct my_struct{
    int minutes;
    int hours;
}   type_struc;

typedef struct my_lst{
    int nbr;
    struct my_lst *next; // permet de selectionner un élément de liste(sinon sans le * on ne peut rien sélectioner)
    struct my_lst *prev;
}   type_lst;

#endif
