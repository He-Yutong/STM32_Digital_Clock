#include "tim.h"
#include "sys.h"

extern int second;

void TIM3_Init(const uint16_t arr1,const uint16_t psc1)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
	TIM_BaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_BaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_BaseInitStructure.TIM_Period=arr1-1;                 
	TIM_BaseInitStructure.TIM_Prescaler=psc1-1;
	TIM_BaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&TIM_BaseInitStructure);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); 
	TIM_Cmd(TIM3,ENABLE);
}
void TIM4_Init(const uint16_t arr2,const uint16_t psc2)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
	TIM_BaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_BaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_BaseInitStructure.TIM_Period=arr2-1;                  
	TIM_BaseInitStructure.TIM_Prescaler=psc2-1;
	TIM_BaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4,&TIM_BaseInitStructure);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);  
	TIM_Cmd(TIM4,ENABLE);
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) 
	{
		second++; 
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  
}
  
