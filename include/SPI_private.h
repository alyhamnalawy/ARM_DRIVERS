#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define _SPI_1_BASE_ADDRESS          0x40013000 
#define _SPI_2_BASE_ADDRESS          0x40003800 
#define _SPI_3_BASE_ADDRESS          0x40003C00 
#define _SPI_4_BASE_ADDRESS          0x40013400 


typedef struct
{
	volatile u32 CR1     ;        	        
	volatile u32 CR2     ;        
	volatile u32 SR      ;          
	volatile u32 DR      ;          
	volatile u32 CRCPR   ;          
	volatile u32 RXCRCR  ;          
	volatile u32 TXCRCR  ;          
	volatile u32 I2SCFGR ;          
	volatile u32 I2SPR   ;          
	
}SPI_t;

#define MSPI_1          ( (SPI_t        *)(_SPI_1_BASE_ADDRESS))        
#define MSPI_2          ( (SPI_t        *)(_SPI_2_BASE_ADDRESS)) 
#define MSPI_3          ( (SPI_t        *)(_SPI_3_BASE_ADDRESS)) 
#define MSPI_4          ( (SPI_t        *)(_SPI_4_BASE_ADDRESS))






#endif