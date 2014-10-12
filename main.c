//
//  main.c
//  fittrack1
//
//  Created by Josef Doležal on 05.10.14.
//  Copyright (c) 2014 Josef Doležal. All rights reserved.
//
// preklad s prepinacem -g je pro debug, gdb --args ./copy zdroj cil 777
// r
// bt (backtrace)
// q



#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    char *zdroj;
    char *cil;
    char *buff;
    FILE *f1, *f2;
    int d, len;

    // zadavani zdroje a cile pres argumenty
    if (argc != 4) {
        printf("Zadejte zdrojovy a cilovy soubor a velikost pameti.\n");
        return 3;
    }

    zdroj = argv[1]; // arg 0 je nazev programu
    cil = argv[2];
    len = atoi(argv[3]);

    buff = malloc(len * sizeof(char)); //memory alloc


    if((f1 = fopen(zdroj, "rb")) == NULL) { // r: read, b: binary
        printf("Zdroj se nepodarilo otevrit\n");
        return 1;
    }

    if((f2 = fopen(cil, "wb")) == NULL) { //w: write,
        printf("Cil se nepodarilo otevrit\n");
        return 2;
    }

    // cteni souboru pomoci bufferu
    while ((d = fread(buff, sizeof(char), LEN, f1))) {
        fwrite(buff, sizeof(char), d, f1); // velikost souboru sedi, protoze se na konci souboru zapise
                                           // velikost, ktera byla skutecne prectena
    }

    fclose(f1); // uzavreni souboru
    fclose(f2);

    return 0;
}
