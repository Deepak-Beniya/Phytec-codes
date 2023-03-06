#include<stdio.h>


struct Weather
{
    char day[10];
    double temp;
    char climate[20];

};


int data(){

     float a;

    struct Weather data1={"Sunday",38.56,"Sunny"};

    struct Weather data2={"Monday",35.79,"Mostly Sunny"};

    struct Weather data3={"Tuesday",33.25,"Haze"};

    struct Weather data4={"Wednesday",24.73,"Fog"};

    struct Weather data5={"Thursday",38.56,"Clear"};

    struct Weather data6={"Friday",38.56,"Rainy"};

    struct Weather data7={"Saturday",38.56,"Heavy Rain"};


    for(int i=0;i<150;i++){
        printf("*");
    }
    printf("\n");

    printf("\t\t\t\t\t\t\t WEATHER REPORT CASTING\n");

     for(int i=0;i<150;i++){
        printf("*");
    }
    printf("\n");

    printf("\t\t\t\t DAY \t\t\t TEMPRATURE \t\t\t CLIMATE\n");

    for(int i=0;i<150;i++){
        printf("-");
    }
    printf("\n");

    printf("\t\t\t\t%s \t\t\t %f \t\t\t %s\n",data1.day, data1.temp, data1.climate);
    printf("\t\t\t\t%s \t\t\t %f \t\t\t %s\n",data2.day, data2.temp, data2.climate);
    printf("\t\t\t\t%s \t\t %f \t\t\t %s\n",data3.day, data3.temp, data3.climate);
    printf("\t\t\t\t%s \t\t %f \t\t\t %s\n",data4.day, data4.temp, data4.climate);
    printf("\t\t\t\t%s \t\t %f \t\t\t %s\n",data5.day, data5.temp, data5.climate);
    printf("\t\t\t\t%s \t\t\t %f \t\t\t %s\n",data6.day, data6.temp, data6.climate);
    printf("\t\t\t\t%s \t\t %f \t\t\t %s\n",data7.day, data7.temp, data7.climate);
    
    
    printf("Enter the  Temperature: ");
    scanf("%f",&a);
    
    printf("\n%.3f",a);
    temp(&a);
    
return;
}