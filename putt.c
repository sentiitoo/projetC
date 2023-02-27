#include <unistd.h>

void gd_putchar(char c){
    write(1, &c, 1);
}

#include <unistd.h>

int gd_putstr(char *str){    
    int count = 0;
    while (*str != '\0') {
        write(1, str, 1);
        str++;
        count++;
    }
    return count;
}

int main(void){
    int nb_put = gd_putstr("Coucou");
    /* nb_put = 6 */
    return 0;
}
