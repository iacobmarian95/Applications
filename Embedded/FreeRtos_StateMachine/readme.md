
#                       Controlling a LED intensity using a Finite State Machine model. 

## Board : Infineon XMC4500
## IDE : Dave

</br>
Using State Machine pattern, a LED intensity is controlled via two buttons. The buttons, who are associated with two tasks created via FreeRTOS api. One button is responsible for incrementing the duty cycle and another one for decrementing. LedController class provide 3 functions to the client: LightUp - Increase the duty cycle, LightDown - decrease the duty cycle and Stop who turn the led off.

