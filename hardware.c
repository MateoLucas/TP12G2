/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define LED_0 (17)
#define LED_1 (4)
#define LED_2 (18)
#define LED_3 (23)
#define LED_4 (24)
#define LED_5 (25)
#define LED_6 (22)
#define LED_7 (27)
#define EXPORT_ADRESS "/sys/class/gpio/export"
#define DIRECCTION_ADRESS_22 "/sys/class/gpio/gpio22/direcction"
#define VALUE_ADRESS_22 "/sys/class/gpio/gpio22/value"

int setup(void)
{
    FILE* handle_export;
    int nWritten;
    if((handle_export = fopen(EXPORT_ADRESS ,"w")) == NULL )
    {
        printf("Failed to open EXPORT File.\n");
        exit(1);
    }
    
    nWritten = fputs("22",handle_export);//hacer para todos los pins
    if(nWritten==-1)
    {
        printf("Failed to export pin.\n");
        exit(1);
    }else
    {
        printf("Export file opened successfuly.\n");
    }
    fclose(handle_export);
    /////////////////////////
    FILE* handle_direcction;
    
    if((handle_export = fopen(DIRECCTION_ADRESS_22 ,"w")) == NULL )
    {
        printf("Failed to open DIRECCTION File.\n");
        exit(1);
    }
    
    nWritten = fputs("out",handle_direcction);//hacer para todos los pins
    if(nWritten==-1)
    {
        printf("Failed to direct pin.\n");
        exit(1);
    }else
    {
        printf("Direcction file opened successfuly.\n");
    }
    fclose(handle_direcction);
    ///////////////////////////////////
    
}


