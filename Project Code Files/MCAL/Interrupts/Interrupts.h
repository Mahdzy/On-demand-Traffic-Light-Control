/*
* File:		Interrupts.h
* Project:	On demand Traffic Light Control
* Author:	Abdelrahman Almahdy
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Registers.h"
#include "../../BitManip.h"

#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3
#define TIM2_COMP __vector_4
#define TIM2_OVF __vector_5
#define TIM1_CAPT __vector_6
#define TIM1_COMPA __vector_7
#define TIM1_COMPB __vector_8
#define TIM1_OVF __vector_9
#define TIM0_COMP __vector_10
#define TIM0_OVF __vector_11
#define SPI_STC __vector_12
#define USART_RXC __vector_13
#define USART_UDRE __vector_14
#define USART_TXC __vector_15
#define ADC __vector_16
#define EE_RDY __vector_17
#define ANA_COMP __vector_18
#define TWI __vector_19
#define SPM_RDY __vector_20

#define ISR(Int_Vector) void Int_Vector(void) __attribute__ ((signal, used));\
void Int_Vector(void)

typedef enum EN_ExtInterrupts_t {Int_0, Int_1, Int_2} EN_ExtInterrupts_t;
typedef enum EN_ExtIntSense_t {LOW, Change, F_Edge, R_Edge} EN_ExtIntSense_t;
typedef enum EN_ExtIntError_t {Ext_Interrupt_OK, Ext_Interrupt_Error} EN_ExtIntError_t;
typedef enum EN_TimInterrupts_t {Tim_0, Tim_1, Tim_2} EN_TimInterrupts_t;
typedef enum EN_TimIntType_t {OverFlow, CompareMatch} EN_TimIntType_t;
typedef enum EN_TimIntError_t {Tim_Interrupt_OK, Tim_Interrupt_Error} EN_TimIntError_t;

void GlobalInt_En (void);
EN_ExtIntError_t ExtInt_Init (EN_ExtInterrupts_t Interrupt, EN_ExtIntSense_t IntType);
EN_TimIntError_t TimInt_Init (EN_TimInterrupts_t Timer, EN_TimIntType_t Type);

#endif /* INTERRUPTS_H_ */