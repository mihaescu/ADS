#include"Rabin-Karp.h"
int main(){
	char *pattern = "mountains";
    int q = 101;
    search(pattern, fileReader(), q);
    getch();
    return 0;
}