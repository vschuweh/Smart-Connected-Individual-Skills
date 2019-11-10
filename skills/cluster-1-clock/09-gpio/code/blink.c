/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define Bit3_green 21
#define Bit2_red 4
#define Bit1_blue 25
#define Bit0_yellow 26

// takes in an int count and displays it in binary through the LEDs
void display_led_count(int count) {
  if ((count % 2) > 0) {
    gpio_set_level(Bit0_yellow, 1);
  } else {
    gpio_set_level(Bit0_yellow, 0);
  }
  if ((count % 4) > 1) {
    gpio_set_level(Bit1_blue, 1);
  } else {
    gpio_set_level(Bit1_blue, 0);
  }
  if ((count % 8) > 3) {
    gpio_set_level(Bit2_red, 1);
  } else {
    gpio_set_level(Bit2_red, 0);
  }
  if ((count % 16) > 7) {
    gpio_set_level(Bit3_green, 1);
  } else {
    gpio_set_level(Bit3_green, 0);
  }
}

void app_main(void){
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_pad_select_gpio(Bit3_green);
    gpio_pad_select_gpio(Bit2_red);
    gpio_pad_select_gpio(Bit1_blue);
    gpio_pad_select_gpio(Bit0_yellow);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(Bit3_green, GPIO_MODE_OUTPUT);
    gpio_set_direction(Bit2_red, GPIO_MODE_OUTPUT);
    gpio_set_direction(Bit1_blue, GPIO_MODE_OUTPUT);
    gpio_set_direction(Bit0_yellow, GPIO_MODE_OUTPUT);
    int count = 0;

    while(1) {
      display_led_count(count);
      count++;
      if (count == 16) {
        count = 0;
      }
      vTaskDelay(1000 / portTICK_PERIOD_MS);  /*Wait (block this task) 1s */
    }
}
