/*Reakizar un programa codificado el cual por cada vez que se presiona un botón(interrupción),
 cambie de incrementar a decrementar o viceversa el conteo en un display 7 segementos.
    Cuando incrementa -> LED rojo interno encendido
    Cuando decrementa -> LED verde interno encendido 
*/

#include "MKL25Z4.h"
int main(){
    int segmentos [8] = {4, 5, 0, 2, 3, 1, 6, 7, 8};
    SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK|SIM_SCGC5_PORTD_MASK;
    PORTA-> PCR[0]|=(1<<8)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
    PTA -> PDDR&=~(1u << 1);
    for(int i = 0; i < 7; i++){
    PORTD -> PCR[segmentos [i]]|=(1<<8);
    PTD -> PDDR|=(1u << segmentos [i]);
    NVIC_EnableIRQ(PORTA_IRQn); /*Habilitamos interrupción en el puerto*/
    NVIC_SerPriority(PORTA_IRQn, 0);/*Seteamos prioridad en el puerto*/
    PORTA -> PCR[1]=PORT_PCR_MUX(1)|PORT_PCR_IRQC(0b1000);/*Establecemos que activará la interrupción*/
    
    }
    while(1){

    }
    return 0;
} 