/* Simplest code to investigate the startup file and the resulting object file*/
#include <stdint.h> 

#define RCC_AHB1RSTR    (*((volatile uint32_t *)0x40023810)) 
#define RCC_AHB1ENR     (*((volatile uint32_t *)0x40023830))
#define GPIOD_MODER     (*((volatile uint32_t *)0x40020c00))
#define GPIOD_OSPEEDR   (*((volatile uint32_t *)0x40020c08))
#define GPIOD_PUPDR     (*((volatile uint32_t *)0x40020c0c))
#define GPIOD_ODR       (*((volatile uint32_t *)0x40020c14))

void SystemInit(void)
{
    return; /* do nothing */
}

void main(void)
{
    int i;
    /* turn on an led (please work) */

    /* enable GPIOD peripheral clock*/
    RCC_AHB1ENR     |= 0x00000008;

    /* set GPIOD14 mode to output */
    GPIOD_MODER     |= 0x10000000;

    /* set GPIOD14 speed to fast */
    GPIOD_OSPEEDR   |= 0x20000000;

    /* set GPIOD14 pull to pull-up */
    GPIOD_PUPDR     |= 0x10000000;

    /* write 1 to GPIOD14 output */
    GPIOD_ODR       |=  0x00004000;
    while (1) {
        for (i = 0; i < 0xffff; i++) { ; }
        GPIOD_ODR       ^=  0x00004000;
    }

}

void __libc_init_array(void)
{
    return; /* do nothing, c++ sucks neway */
}

