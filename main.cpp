#include "mbed.h"
#include "uLCD_4DGL.h"
using namespace std::chrono;


uLCD_4DGL uLCD(D1, D0, D2);
AnalogOut  aout(D7);
AnalogIn ain(A0);
DigitalIn button_up(D13);
DigitalIn button_down(D12);
DigitalIn button_sel(D11);
void ulcd_display(int);
void wave_generate(float);

int frequency = 366;
float increment = 0.02;

int main()
{
    int count_ = 0;
    float ADCdata[50];
    float cycle = 0.0;
    float i = 0.0;
    int flag_prt = 0;
    int flag = 1;
    ulcd_display(frequency);
    while(1){
        if(frequency < 10 && button_down == 1){
            frequency = 0;
            ulcd_display(frequency);
        }
        
        else if (button_up == 1){
            frequency += 10;
            ulcd_display(frequency);
        }
        
        else if (button_down == 1){
            frequency -= 10;
            ulcd_display(frequency);
        }
        
        else if (button_sel == 1){
            cycle = 1000/frequency; //unit:ms
            flag_prt = 1;
        }
        if(i <= 0){
            flag = 1;
            i = i + increment;
            aout = i/1.1;
            wait_us(cycle*20);
        }
        else if(i >= 1){
            flag = 0;
            i = i - increment;
            aout = i/1.1;
            wait_us(cycle*20);
        }
        else if(flag == 1){
            i = i + increment;
            aout = i/1.1;
            wait_us(cycle*20);
        }
        else if(flag == 0){
            i = i - increment;
            aout = i/1.1;
            wait_us(cycle*20);
        }
        if(count_ == 50){
            flag_prt = 0;
            count_ = 0;
            printf("%d\r\n", frequency);
            for (int i = 0; i < 50; i++){
                printf("%f\r\n", ADCdata[i]);
            }
        }
        else if(flag_prt == 1){
            ADCdata[count_] = ain;
            count_ ++;
        }
    }
}

void ulcd_display(int freq){
    uLCD.cls();
    uLCD.locate(1,2);
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    uLCD.printf("%d\n", freq);
}
