#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*****************************************/
#define _SPI1_MODE_MASTER  0U
#define _SPI1_MODE_SLAVE   1U
/*****************************************/
#define _SPI1_CPOL_LOW     0U
#define _SPI1_CPOL_HIGH    1U
/*****************************************/
#define _SPI1_DATA_SIZE_8    0U
#define _SPI1_DATA_SIZE_16   1U
/*****************************************/
#define _SPI1_DATA_ORDER_MSB    0U
#define _SPI1_DATA_ORDER_LSB    1U
/*****************************************/
#define _SPI1_FPCLK_DIV_2           0b000
#define _SPI1_FPCLK_DIV_4           0b001
#define _SPI1_FPCLK_DIV_8           0b010
#define _SPI1_FPCLK_DIV_16          0b011
#define _SPI1_FPCLK_DIV_32          0b100
#define _SPI1_FPCLK_DIV_64          0b101
#define _SPI1_FPCLK_DIV_128         0b110
#define _SPI1_FPCLK_DIV_256         0b111

/**********************/
#define _SPI1_ENABLE                    1U
#define _SPI1_DISABLE					0U
/*********************/
#define _SPI1_INT_DISABLE             0U
#define _SPI1_TXE_INT_ENABLE          1U
#define _SPI1_RXNE_INT_ENABLE         2U
/*********************/
#define _SPI1__MODE0                   0U /* CPL =0   & CPH =0  */
#define _SPI1__MODE1                   1U /* CPL =0   & CPH =1  */
#define _SPI1__MODE2                   2U /* CPL =1   & CPH =0  */
#define _SPI1__MODE3                   3U /* CPL =1   & CPH =1  */
/*********************/
#define RXNEIE       6U
#define TXEIE        7U


/****************************************************************************
*- APIS
****************************************************************************/
void MSPI1_vInit(void);





#endif