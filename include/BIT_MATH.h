/***********************
* Author : Aly Ehab
* Date : 22 MAR,2023
* Version : v1
* Compiler : GNU GCC
***********************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

/************** FUNCTIONS LIKE MACRO TO MANIPULATE OVER SPECIFIC BIT **********************/
#define SET_BIT(REG_NAME,BIT)       REG_NAME|=(1<<BIT)
#define CLR_BIT(REG_NAME,BIT)       REG_NAME&=~(1<<BIT)
#define TOGGLE_BIT(REG_NAME,BIT)    REG_NAME^=(1<<BIT)
#define GET_BIT(REG_NAME,BIT)       (REG_NAME>>BIT)&0x01

/************** FUNCTIONS LIKE MACRO TO MANIPULATE OVER SPECIFIC REGISTER **********************/
#define SET_REG(REG_NAME,VALUE)     REG_NAME=VALUE
#define CLR_REG(REG_NAME,VALUE)     REG_NAME=0x00
#define GET_REG(REG_NAME)           REG_NAME

#endif