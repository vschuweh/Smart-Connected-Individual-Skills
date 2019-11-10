#  Console I/O

Author: Vanessa Schuweh, 2019-09-20

## Summary
In this skill I made an interactive console that utilized the ESP32 to respond to user inputs to switch between 3 different modes by entering an "s". The first mode, toggle, toggles on and off and LED when the user inputs a "t". The second mode, echo, takes the user's input and prints it to the console. The final mode, hexadecimal, takes a decimal number as input and outputs its hexadecimal equivalent. I utilized case statements and the strcmp() function to switch between different modes. I also used the atoi() function to convert strings to integers when scanning in the user input. Echo mode also included a special notation to take into account spaces in the user's input.

## Sketches and Photos

Screen recording of console                                            
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/XYvPXoiSy7k/0.jpg)](https://www.youtube.com/watch?v=XYvPXoiSy7k)


Video of onboard LED toggle and console                                    
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/r6XV8Mdy9hU/0.jpg)](https://www.youtube.com/watch?v=r6XV8Mdy9hU)

## Modules, Tools, Source Used in Solution
* GPIO
* Switch statements
* ESP-IDF

## Supporting Artifacts
* [GitHub esp-idf blink examaple](https://github.com/espressif/esp-idf/tree/master/examples/get-started/blink)

-----

## Reminders
- Repo is private
