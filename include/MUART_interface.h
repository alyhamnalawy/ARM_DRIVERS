#ifndef MUART_INTERFACE_H
#define MUART_INTERFACE_H


void MUART_voidInit(void);

void MUART_voidEnable(void);

void MUART_voidDisable(void);

void MUART_u8SendData(u8* copy_u8Data, u8 copy_u8Len);

u8 MUART_u8ReadData(void);


#endif
