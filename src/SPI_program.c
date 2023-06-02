/******************************
 * 
 * Name: Aly Ehab.
 * Date: 31, May 2023
 * Version: V1
 * 
 * 
******************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/SPI_interface.h"
#include "../include/SPI_private.h"
#include "../include/SPI_config.h"


void (*MSPI1_CallBack) (void);


/********************************************************** Start_FUNCTION  **********************************************************/
void MSPI1_vInit(void)
{
	#if MSPI1_STATUS == _SPI1_ENABLE
/*****************       Clock ( phase & polarity )       *****************/
			#if MSPI1_MODE == _SPI1__MODE0
					/* CPL =0   & CPH =0(r/w)  */
				CLR_BIT(MSPI_1 -> CR1 , CPOL);
				CLR_BIT(MSPI_1 -> CR1 , CPHA);	
			#elif  MSPI1_MODE == _SPI1__MODE1
					/* CPL =0   & CPH =1  */
				CLR_BIT(MSPI_1 -> CR1 , CPOL);
				SET_BIT(MSPI_1 -> CR1 , CPHA);		
			#elif  MSPI1_MODE == _SPI1__MODE2
					/* CPL =1  & CPH = 0  */
				SET_BIT(MSPI_1 -> CR1 , CPOL);
				CLR_BIT(MSPI_1 -> CR1 , CPHA);
			#elif  MSPI1_MODE == _SPI1__MODE3
					/* CPL =1   & CPH =1  */ 
				SET_BIT(MSPI_1 -> CR1 , CPOL);
				SET_BIT(MSPI_1 -> CR1 , CPHA);	
			#else 
				/**/
			#endif
/*****************       Master selection       *****************/			
			#if    MSPI1_MASTER_SELECTION  == _SPI1_MODE_MASTER
					SET_BIT(MSPI_1 -> CR1  ,MSTR);
			#elif  MSPI1_MASTER_SELECTION  == _SPI1_MODE_SLAVE
					CLR_BIT(MSPI_1 -> CR1  ,MSTR);
			#endif
/*****************       Frame format       *****************/
			#if     MSPI1_DATA_ORDER  ==   _SPI1_DATA_ORDER_MSB
						CLR_BIT(MSPI_1 -> CR1  ,LSBFIRST);
			#elif   MSPI1_DATA_ORDER  == _SPI1_DATA_ORDER_LSB
						SET_BIT(MSPI_1 -> CR1  ,LSBFIRST);
			#endif
/*****************       Data Size        *****************/
			#if   MSPI1_DATA_SIZE == _SPI1_DATA_SIZE_8
					CLR_BIT( MSPI_1 -> CR1 ,DFF);
			#elif MSPI1_DATA_SIZE == _SPI1_DATA_SIZE_16
					SET_BIT( MSPI_1 -> CR1 ,DFF);
			#endif
/*****************       Interrput enable | disabled      *****************/
			#if   MSPI1_INT_STATUS == MSPI_INT_DISABLE
					MSPI_1 ->CR2 = 0U ;
			#elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE
					SET_BIT(MSPI_1 ->CR2 , TXEIE);
			#elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE
					SET_BIT(MSPI_1 ->CR2 , RXNEIE);
			#endif
/*****************       Baud rate control      *****************/
			/* 1111 1111 1100 0111*/
			MSPI_1 ->CR1 &=0XFFC7;
			MSPI_1 ->CR1 |=(MSPI1_FPCLK<<3U);
/*****************       SPI enable       *****************/
		SET_BIT(MSPI_1 ->CR1,SPE);
#endif

}

u8 MSPI1_u8Transceive(u8 Copy_u8Data)
{
	u8 L_u8Resive=0U;
	/* Wait BSY Flag */
while ( GET_BIT(MSPI1 ->SR , BSY ) == 1 );	
	/* Write Data */
	MSPI1 ->DR =Copy_u8Data;
	/* Wait BSY Flag */
while ( GET_BIT(MSPI1 ->SR , BSY ) == 1 );		
	/* Return data */
	L_u8Resive = (u8)MSPI1 ->DR;
	return L_u8Resive;

}

u16 MSPI1_u16Transceive(u16 Copy_u16Data)
{
	u16 L_u16Resive=0U;
	/* Wait BSY Flag */
while ( GET_BIT(MSPI1 ->SR , BSY ) == 1 );	
	/* Write Data */
	MSPI1 ->DR =Copy_u16Data;
	/* Wait BSY Flag */
while ( GET_BIT(MSPI1 ->SR , BSY ) == 1 );		
	/* Return data */
	L_u16Resive = (u16)MSPI1 ->DR;
	return L_u16Resive;

}
	
void MSPI1_VidSetCallBack( void (*ptr) (void) ){

	MSPI1_CallBack = ptr;

}

void SPI1_IRQHandler(void){

	MSPI1_CallBack();

}
