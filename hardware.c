/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
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

#define VALUE_ADRESS_22 "/sys/class/gpio/gpio22/value"

#define VALUE_ADRESS_27 "/sys/class/gpio/gpio27/value"

#define VALUE_ADRESS_25 "/sys/class/gpio/gpio25/value"

#define VALUE_ADRESS_24 "/sys/class/gpio/gpio24/value"

#define VALUE_ADRESS_23 "/sys/class/gpio/gpio23/value"

#define VALUE_ADRESS_18 "/sys/class/gpio/gpio18/value"
#define VALUE_ADRESS_4 "/sys/class/gpio/gpio4/value"
#define VALUE_ADRESS_17 "/sys/class/gpio/gpio17/value"

int setup(void)
{
    FILE* handle_export;
    int nWritten;
    int i =0;
    char direcction [][]={"/sys/class/gpio/gpio17/direcction","/sys/class/gpio/gpio4/direcction",
    "/sys/class/gpio/gpio18/direcction","/sys/class/gpio/gpio23/direcction","/sys/class/gpio/gpio24/direcction"
    "/sys/class/gpio/gpio25/direcction","/sys/class/gpio/gpio22/direcction","/sys/class/gpio/gpio27/direcction"};
    char pins [][]={"17","4","18","23","24","25","22","27"};
    for(i=0;i<NPINS;i++){
        if((handle_export = fopen(EXPORT_ADRESS ,"w")) == NULL )
        {
            printf("Failed to open EXPORT File.\n");
            exit(1);
        }
    
        nWritten = fputs(pins[i],handle_export);//hacer para todos los pins
        if(nWritten==-1)
        {
            printf("Failed to export pin.%d\n", i);
            exit(1);
        }else
    {
            printf("Export file opened successfuly.\n");
    }
    
    }
    fclose(handle_export);
    /////////////////////////
    FILE* handle_direcction;
    for(i=0;i<NPINS;++i){
        if((handle_export = fopen(direcction[i] ,"w")) == NULL )
    {
            printf("Failed to open DIRECCTION File.\n");
            exit(1);
    }
    
        nWritten = fputs("out",handle_direcction);//hacer para todos los pins
        if(nWritten==-1)
        {
            printf("Failed to direct pin.%d\n", i);
            exit(1);
        }else
        {
            printf("Direcction file opened successfuly.\n");
        }
    }
    
    fclose(handle_direcction);
    ///////////////////////////////////
    
}


