//
//  main.c
//  fittrack1
//
//  Created by Josef Doležal on 05.10.14.
//  Copyright (c) 2014 Josef Doležal. All rights reserved.
//

#include <stdio.h>

int main(int argc, char **argv) {
    char *zdroj;
    char *cil;
    FILE *f1, *f2;
    int znak;

    // zadavani zdroje a cile pres argumenty
    if (argc != 3) {
        printf("Zadejte zdrojovy a cilovy soubor\n.");
        return 1;
    }

    zdroj = argv[1]; // arg 0 je nazev programu
    cil = argv[2];

    if((f1 = fopen(zdroj, "rb")) == NULL) { // r: read, b: binary
        printf("Zdroj se nepodarilo otevrit\n");
        return 1;
    }

    if((f2 = fopen(cil, "wb")) == NULL) { //w: write,
        printf("Cil se nepodarilo otevrit\n");
        return 1;
    }

    while ((znak = fgetc(f1)) != EOF) {
        fputc(znak, f2);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
