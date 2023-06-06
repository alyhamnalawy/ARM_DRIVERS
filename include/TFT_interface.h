#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H


void HTFT_voidInit(void);

static void HTFT_voidSendCommand(u8 Copy_u8Command);


static void HTFT_voidSendData(u8 Copy_u8Data);


void HTFT_voidDisplayImage(u16 * Copy_pu16Image);


void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1);




#endif
