#include "stm32l4xx.h"

int main(void)
{
	// Enable the peripheral clock of GPIO Port	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOEEN;
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	// LD4 Red = PB2
	///////////////////////////////////////////////////////////////////////////////////////////////
	// GPIO Mode: Input(00), Output(01), AlterFunc(10), Analog(11, reset)
	GPIOB->MODER &= ~(3U<<(2*2));  
	GPIOB->MODER |= 1U<<(2*2);      //  Output(01)
	
	// GPIO Speed: Low speed (00), Medium speed (01), 
	//             Fast speed (10), High speed (11)
	GPIOB->OSPEEDR &= ~(3U<<(2*2));	// Azzero i due bit di PB2
	GPIOB->OSPEEDR |=   3U<<(2*2);  // Imposto a uno i due bit di PB2 -> High speed
	
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOB->OTYPER &= ~(1U<<2);       // Push-pull
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOB->PUPDR   &= ~(3U<<(2*2));  // No pull-up, no pull-down

	for(;;) {
		// Turn Red LED On
		GPIOB->ODR |= GPIO_ODR_ODR_2;
		// Turn Red LED Off
		GPIOB->ODR &= ~GPIO_ODR_ODR_2;
		// Toggle Red LED 
		GPIOB->ODR ^= GPIO_ODR_ODR_2;
	}
}
