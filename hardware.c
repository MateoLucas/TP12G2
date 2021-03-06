/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdlib.h>
#include<stdio.h>
#define NPINS 8
#define LED_0 (17)
#define LED_1 (4)
#define LED_2 (18)
#define LED_3 (23)
#define LED_4 (24)
#define LED_5 (25)
#define LED_6 (22)
#define LED_7 (27)
#define EXPORT_ADRESS "/sys/class/gpio/export"
int setup(void)
{
    FILE* handle_export;
    int nWritten;
    int i =0;
    char direcction [][34]={"/sys/class/gpio/gpio17/direction","/sys/class/gpio/gpio4/direction",
    "/sys/class/gpio/gpio18/direction","/sys/class/gpio/gpio23/direction","/sys/class/gpio/gpio24/direction",
    "/sys/class/gpio/gpio25/direction","/sys/class/gpio/gpio22/direction","/sys/class/gpio/gpio27/direction"};
    char pins [][3]={"17","4","18","23","24","25","22","27"};
    
    for(i=0;i<NPINS;i++){
        if((handle_export = fopen(EXPORT_ADRESS ,"w")) == NULL )
        {
            printf("Failed to open EXPORT File.%d\n",i);
            exit(1);
        }
    
        nWritten = fputs(pins[i],handle_export);//hacer para todos los pins
        if(nWritten==-1)
        {
            printf("Failed to export pin.%d\n", i);
            exit(1);
        }else
    {
            printf("Export file opened successfuly.%d\n",i);
    }
    
    }
    fclose(handle_export);
    /////////////////////////
    FILE* handle_direction;
    for(i=0;i<NPINS;++i){
        if((handle_direction = fopen(direcction[i] ,"w")) == NULL )
    {
            printf("Failed to open DIRECCTION File.\n");
            exit(1);
    }
    
        nWritten = fputs("out",handle_direction);//hacer para todos los pins
        if(nWritten==-1)
        {
            printf("Failed to direct pin.%d\n", i);
            exit(1);
        }else
        {
            printf("Direcction file opened successfuly.\n");
        }
    }
    
    fclose(handle_direction);
    ///////////////////////////////////
    return 0;
}

void leds (int puerto,int estado){//prende y apaga leds
    FILE * handle;
    char direcction [][29]={"/sys/class/gpio/gpio17/value","/sys/class/gpio/gpio4/value",
    "/sys/class/gpio/gpio18/value","/sys/class/gpio/gpio23/value","/sys/class/gpio/gpio24/value",
    "/sys/class/gpio/gpio25/value","/sys/class/gpio/gpio22/value","/sys/class/gpio/gpio27/value"};
    if ((handle = fopen(direcction[puerto],"w")) == NULL){
        printf("Cannot open device. Try again later.\n");
        exit(1);
    }else{
        printf("Device successfully opened\n");
    }
    if(estado==1){//prendo
    if(fputc('1' ,handle)==-1){ // Set pin low
    printf("Clr_Pin: Cannot write to file. Try again later.\n");
    exit(1);
    }
    else{
        printf("Write to file %s successfully done.\n",direcction[puerto]);
    }
    }else{
        if(fputc('0' ,handle)==-1){ // Set pin low
    printf("Clr_Pin: Cannot write to file. Try again later.\n");
    exit(1);
    }
    else{
        printf("Write to file %s successfully done.\n",direcction[puerto]);
    }
    }
        fclose(handle);
}
