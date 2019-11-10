#  Servo

Author: Vanessa Schuweh, 2019-09-20

## Summary
In this skill I read about the functionality of servos and PWM. I wired my servo to the ESP32 through 3v, GND, and GPIO pin A5. I changed the max degree, min pulse width, and max pulse width to allow the servo to reach it's maximum rotation. Each servo is a bit different, so I had to experiment with the numbers to find the values that let my servo rotate it's full arc length. I used the GitHub esp-idf mcpwm_servo_control example as my basline and modified it to finish this skill.

## Sketches and Photos
Demo video of my servo                                        
[![](https://img.youtube.com/vi/nhi9bNUr4dg/0.jpg)](https://www.youtube.com/watch?v=nhi9bNUr4dg)

## Modules, Tools, Source Used in Solution
* Servo
* PWM
* ESP32

## Supporting Artifacts
* [GitHub mcpwm_servo_control example](https://github.com/espressif/esp-idf/tree/master/examples/peripherals/mcpwm/mcpwm_servo_control)


-----

## Reminders
- Repo is private
