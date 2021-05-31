/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 12 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


typedef struct{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;
}DMA_Channel_e;

typedef struct{
	volatile u32	ISR;
	volatile u32	IFCR;
	DMA_Channel_e	Channel[7];
}DMA_e;

#define DMA 		((volatile DMA_e*)(0x4002 0000))

#define DAM_ISR 	*((volatile u32*)(0x4002 0000))
#define DAM_IFCR	*((volatile u32*)(0x4002 0000+0x004))

/*channel 1*/
#define DMA_CCR1	*((volatile u32*)(0x4002 0000+0x008))
#define DMA_CNDTR1	*((volatile u32*)(0x4002 0000+0x00C))
#define DMA_CPAR1	*((volatile u32*)(0x4002 0000+0x010))
#define DMA_CMAR1	*((volatile u32*)(0x4002 0000+0x014))

/*channel 2*/
#define DMA_CCR2	*((volatile u32*)(0x4002 0000+0x01C))
#define DMA_CNDTR2	*((volatile u32*)(0x4002 0000+0x020))
#define DMA_CPAR2	*((volatile u32*)(0x4002 0000+0x024))
#define DMA_CMAR2	*((volatile u32*)(0x4002 0000+0x028))

/*channel 3*/
#define DMA_CCR3	*((volatile u32*)(0x4002 0000+0x030))
#define DMA_CNDTR3	*((volatile u32*)(0x4002 0000+0x034))
#define DMA_CPAR3	*((volatile u32*)(0x4002 0000+0x038))
#define DMA_CMAR3	*((volatile u32*)(0x4002 0000+0x03C))

/*channel 4*/
#define DMA_CCR4	*((volatile u32*)(0x4002 0000+0x044))
#define DMA_CNDTR4	*((volatile u32*)(0x4002 0000+0x048))
#define DMA_CPAR4	*((volatile u32*)(0x4002 0000+0x04C))
#define DMA_CMAR4	*((volatile u32*)(0x4002 0000+0x050))

/*channel 5*/
#define DMA_CCR5	*((volatile u32*)(0x4002 0000+0x058))
#define DMA_CNDTR5	*((volatile u32*)(0x4002 0000+0x05C))
#define DMA_CPAR5	*((volatile u32*)(0x4002 0000+0x060))
#define DMA_CMAR5	*((volatile u32*)(0x4002 0000+0x064))

/*channel 6*/
#define DMA_CCR6	*((volatile u32*)(0x4002 0000+0x06C))
#define DMA_CNDTR6	*((volatile u32*)(0x4002 0000+0x070))
#define DMA_CPAR6	*((volatile u32*)(0x4002 0000+0x074))
#define DMA_CMAR6	*((volatile u32*)(0x4002 0000+0x078))

/*channel 7*/
#define DMA_CCR7	*((volatile u32*)(0x4002 0000+0x080))
#define DMA_CNDTR7	*((volatile u32*)(0x4002 0000+0x084))
#define DMA_CPAR7	*((volatile u32*)(0x4002 0000+0x088))
#define DMA_CMAR7	*((volatile u32*)(0x4002 0000+0x08C))












#endif