#include "BotonDisplay.h"
#include "MKL25Z4.h"

int segmentos [8] = {4, 0, 2, 3, 1, 5, 6, 7, 8};

int BCD7segm [10][7] =  {
                        {1, 1, 1, 1, 1, 1, 0},
                        {0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 1},
                        {1, 1, 1, 1, 0, 0, 1},
                        {0, 1, 1, 0, 0, 1, 1},
                        {1, 0, 1, 1, 0, 1, 1},
                        {1, 0, 1, 1, 1, 1, 1},
                        {1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 0, 1, 1}                  
                        };



int boton(){
    int boton = PTA -> PDIR &(1 << 1);
    return boton;
}

int BCD7seg() {
    for (int i=0;i<10;i++) {
        for (int j=0;j<7;j++) {
            PTA -> PSOR |= (BCD7segm[i][j] << segmentos[j]);
        }
    }
}

