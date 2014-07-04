#!/bin/bash
arm-none-eabi-gcc -nostdlib -mthumb -mcpu=cortex-m4 -T STM32F407VG_FLASH.ld startup_stm32f407xx.s main.c -o simplest-blink.elf -g3
