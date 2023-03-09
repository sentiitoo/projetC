#include <unistd.h>
#include <stdio.h>
//permet de print
void gd_putchar(char c) { 
    write(1,&c, 1);
}

int gd_putstr(char *list) {
    int i;
    i = 0;
    while(list[i] != '\0') {
        gd_putchar(list[i]);
        i++;
    }
    return i;

}

int main(void) {
    //gd_putchar('a');
    //gd_putchar('\n');
    int nb_put = gd_putstr("coucou");
    printf("%i\n", nb_put);
}