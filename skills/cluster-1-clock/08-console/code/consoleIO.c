#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "driver/uart.h"
#include "esp_vfs_dev.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO 13

void app_main() {
    ESP_ERROR_CHECK( uart_driver_install(UART_NUM_0, 256, 0, 0, NULL, 0) ); 
    esp_vfs_dev_uart_use_driver(UART_NUM_0); 

    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    int mode = 0;
    char inputS[20];
    char switchS[2];
    char toggleT[2];
    char temp;
    bool ledToggleOn = false;
    strcpy(switchS, "s");
    strcpy(toggleT, "t");

    while(1) {
      switch (mode) {
        case 0: 
          printf("toggle mode\n");
          while(1) {
            scanf("%s", inputS);
            printf("Read: %s\n", inputS);
            if (strcmp (switchS, inputS) == 0) {
              mode = 1;
              gpio_set_level(BLINK_GPIO, 0);
						  ledToggleOn = false;
              vTaskDelay(50 / portTICK_RATE_MS);
              break;
            } else if (strcmp (toggleT, inputS) == 0){
              if (ledToggleOn == true) {
							  gpio_set_level(BLINK_GPIO, 0);
							  ledToggleOn = false;
						  } else {
							  gpio_set_level(BLINK_GPIO, 1);
							  ledToggleOn = true;
						  }
            }
          }        
        
        case 1: 
          printf("echo mode\n");
          while(1){
            scanf("%c", &temp); //temp to clear buffer
            scanf("%[^\n]", inputS);
            printf("Echo: %s\n", inputS);
            if (strcmp (switchS, inputS) == 0) {
              mode = 2;
              vTaskDelay(50 / portTICK_RATE_MS);
              break;
            }
        }
        
        case 2:
          printf("echo dec to hex\n");
          while(1){
            long int decimalNumber, quotient;
            int i = 1, j, temp;
            char hexadecimalNumber[100];
            printf("Enter an integer:\n");
            scanf("%s", inputS);
            if (strcmp (switchS, inputS) == 0) {
              mode = 0;
              vTaskDelay(50 / portTICK_RATE_MS);
              break;
            } else {
              decimalNumber = atoi(inputS);
            }
              quotient = decimalNumber;
              while (quotient!=0) {
                temp = quotient % 16;
              if (temp < 10) {  //To convert integer into hex
                temp = temp + 48; 
              } else {
                temp = temp + 55;
              }
              hexadecimalNumber[i++]= temp;
              quotient = quotient / 16;
              }
              printf("Hex: ");
              for (j = i -1; j > 0; j--) {
                printf("%c", hexadecimalNumber[j]);
              }
              printf("\n");
            }  
          }   
      }
    }