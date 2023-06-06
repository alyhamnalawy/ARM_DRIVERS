#ifndef MUART_PRIVATE_H
#define MUART_PRIVATE_H


#define UART1_BASE_ADRESS     0x40011000


typedef struct{
    u32 SBK       :1;
    u32 RWU       :1;
    u32 RE        :1;
    u32 TE        :1;
    u32 IDLEIE    :1;
    u32 RXNEIE    :1;
    u32 TCIE      :1;
    u32 TXEIE     :1;
    u32 PEIE      :1;
    u32 PS        :1;
    u32 PCE       :1;
    u32 WAKE      :1;
    u32 M         :1;
    u32 UE        :1;
    u32 RESERVED  :1;
    u32 OVER8     :1;
    u32 RESERVED2 :16;
}UART_CR1;


typedef struct{

    u32 SR;
    u32 DR;
    u32 BRR;
    UART_CR1 CR1;
    u32 CR2;
    u32 CR3;
    u32 GTPR;
}UART_t;


typedef    volatile UART_t* UART_REG ;

#define     UART1_REG    ((volatile UART_t*)(UART1_BASE_ADRESS))

UART_REG MUART_GetHandler(void);



#endif
