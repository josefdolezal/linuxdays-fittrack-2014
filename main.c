//
//  main.c
//  fittrack1
//
//  Created by Josef Doležal on 05.10.14.
//  Copyright (c) 2014 Josef Doležal. All rights reserved.
//

#include <stdio.h>

int main() {
    char *zdroj = "zdroj.txt";
    char *cil = "cil.txt";
    FILE *f1, *f2;
    int znak;

    if((f1 = fopen(zdroj, "rb")) == NULL) { // r: read, b: binary
        printf("Zdroj se nepodarilo otevrit\n");
        return 1;
    }

    if((f2 = fopen(cil, "wb")) == NULL) { //w: write,
        printf("Cil se nepodarilo otevrit\n");
        return 1;
    }

    // cteni zdroje po znaku
    while ((znak = fgetc(f1)) != EOF) {
        fputc(znak, f2);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
