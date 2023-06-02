#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define MSPI1_STATUS _SPI1_ENABLE
/*
	-option :
			 _SPI1__MODE0
	         _SPI1__MODE1
	         _SPI1__MODE2
	         _SPI1__MODE3	
*/
#define MSPI1_MODE  _SPI1__MODE3 /* ideal high , w / read */
/*
	-option :
			_SPI1_MODE_MASTER 
	        _SPI1_MODE_SLAVE  
*/
#define MSPI1_MASTER_SELECTION   _SPI1_MODE_MASTER


/*
	-option :
		_SPI1_DATA_ORDER_MSB
		_SPI1_DATA_ORDER_LSB	
*/
#define MSPI1_DATA_ORDER   _SPI1_DATA_ORDER_MSB

/*
	-option :		
		_SPI1_DATA_SIZE_8 
		_SPI1_DATA_SIZE_16
		
*/

#define MSPI1_DATA_SIZE _SPI1_DATA_SIZE_8

#define MSPI1_FPCLK     _SPI1_FPCLK_DIV_8
#endif
