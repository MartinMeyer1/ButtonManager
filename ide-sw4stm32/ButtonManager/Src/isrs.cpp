#include "mcu/mcu.h"
#include "main.h"

extern "C" void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch (GPIO_Pin)
    {/*
    case BUTTON0_Pin:
    case BUTTON1_Pin:
    case BUTTON2_Pin:
    case BUTTON3_Pin:
        // TODO: Notify ButtonsController about interrupt
        break;*/
    default:
        break;
    }
}
