/***********************************************************/
/***********************************************************/
/****************  Auther  : Ziad Akram ********************/
/****************  Layer   : MCAL       ********************/
/****************  SWC     : DIO        ********************/
/****************  Version : 1.00       ********************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = 0 ;

	if(Copy_u8Pin<= DIO_u8PIN7)
	{
		if(Copy_u8Direction==DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port){
			case DIO_u8PORTA: CLR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8PORTB: CLR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8PORTC: CLR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8PORTD: CLR_BIT(DDRD,Copy_u8Pin); break;
			default : Local_u8ErrorState= 1 ;
			}
		}else if(Copy_u8Direction==DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port){
			case DIO_u8PORTA: SET_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(DDRD,Copy_u8Pin); break;
			default : Local_u8ErrorState= 1 ;
			}

		}else
		{
			Local_u8ErrorState = 1 ;
		}
	}else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;

}
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8Port){
	case DIO_u8PORTA : DDRA = Copy_u8Direction ; break ;
	case DIO_u8PORTB : DDRB = Copy_u8Direction ; break ;
	case DIO_u8PORTC : DDRC = Copy_u8Direction ; break ;
	case DIO_u8PORTD : DDRD = Copy_u8Direction ; break ;
	default : Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState =0;

		if(Copy_u8Pin<= DIO_u8PIN7)
		{
			if(Copy_u8Value==DIO_u8PIN_LOW)
			{
				switch(Copy_u8Port){
				case DIO_u8PORTA: CLR_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB: CLR_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC: CLR_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD: CLR_BIT(PORTD,Copy_u8Pin); break;
				default : Local_u8ErrorState= 1 ;
				}
			}else if(Copy_u8Value==DIO_u8PIN_HIGH)
			{
				switch(Copy_u8Port){
				case DIO_u8PORTA: SET_BIT(PORTA,Copy_u8Pin); break;
				case DIO_u8PORTB: SET_BIT(PORTB,Copy_u8Pin); break;
				case DIO_u8PORTC: SET_BIT(PORTC,Copy_u8Pin); break;
				case DIO_u8PORTD: SET_BIT(PORTD,Copy_u8Pin); break;
				default : Local_u8ErrorState= 1 ;
				}

			}else
			{
				Local_u8ErrorState = 1 ;
			}
		}else
		{
			Local_u8ErrorState = 1 ;
		}
		return Local_u8ErrorState ;

}
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8ErrorState =0;
	switch(Copy_u8Port){
		case DIO_u8PORTA : PORTA = Copy_u8Value ; break ;
		case DIO_u8PORTB : PORTB = Copy_u8Value ; break ;
		case DIO_u8PORTC : PORTC = Copy_u8Value ; break ;
		case DIO_u8PORTD : PORTD = Copy_u8Value ; break ;
		default : Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
}
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value)
{
	u8 Local_u8ErrorState = 0;
	if((Copy_pu8Value != NULL) && (Copy_u8Pin<= DIO_u8PIN7))
	{
		switch(Copy_u8Port){
				case DIO_u8PORTA : *Copy_pu8Value = GET_BIT(PINA ,Copy_u8Pin); break ;
				case DIO_u8PORTB : *Copy_pu8Value = GET_BIT(PINB ,Copy_u8Pin); break ;
				case DIO_u8PORTC : *Copy_pu8Value = GET_BIT(PINC ,Copy_u8Pin); break ;
				case DIO_u8PORTD : *Copy_pu8Value = GET_BIT(PIND ,Copy_u8Pin); break ;
				default : Local_u8ErrorState = 1 ;
			}
	}else
	{
		Local_u8ErrorState =1;
	}
	return Local_u8ErrorState ;
}
u8  DIO_u8TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState =0  ;
	switch(Copy_u8Port){
	case DIO_u8PORTA : TOG_BIT(PORTA,Copy_u8Pin); break;
	case DIO_u8PORTB : TOG_BIT(PORTB,Copy_u8Pin); break;
	case DIO_u8PORTC : TOG_BIT(PORTC,Copy_u8Pin); break;
	case DIO_u8PORTD : TOG_BIT(PORTD,Copy_u8Pin); break;
	default : Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState ;
	
}
u8 DIO_voidWriteHighNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{

	u8 Local_u8ErrorState = 0;

	if ( (Copy_u8PORT <= DIO_u8PORTD))
	{
		Copy_u8value = (Copy_u8value<<4) ;
		switch(Copy_u8PORT)
		{
		case DIO_u8PORTA :
			PORTA&=0x0f;                   // make sure the high bits = 0000
			PORTA|=Copy_u8value;			//Set only the high nibble of the port A by the given value
			break ;
		case DIO_u8PORTB:
			PORTB&=0x0f;                 //Set only the high nibble of the port B by the given value
			PORTB|=Copy_u8value;
			break ;
		case DIO_u8PORTC :
			PORTC&=0x0f;                 //Set only the high nibble of the port C by the given value
			PORTC|=Copy_u8value;
			break ;
		case DIO_u8PORTD:
			PORTD&=0x0f;                 //Set only the high nibble of the port D by the given value
			PORTD|=Copy_u8value;
			break ;
		default: break ;

		}
	}
	else
	{
		Local_u8ErrorState =1;
	}

	return Local_u8ErrorState ;

}

u8 DIO_voidWriteLowNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{
	u8 Local_u8ErrorState = 0;
	
	if ( (Copy_u8PORT <= DIO_u8PORTD))
	{
		Copy_u8value&=0x0f;
		switch(Copy_u8PORT)
		{
		case DIO_u8PORTA :
			PORTA &= 0xf0;                 //Set only the high nibble of the port A by the given value
			PORTA |= Copy_u8value;
			break ;
		case DIO_u8PORTB:
			PORTB &= 0xf0;                 //Set only the high nibble of the port B by the given value
			PORTB |= Copy_u8value;
			break ;
		case DIO_u8PORTC :
			PORTC &= 0xf0;                 //Set only the high nibble of the port C by the given value
			PORTC |= Copy_u8value;
			break ;
		case DIO_u8PORTD:
			PORTD &= 0xf0;                 //Set only the high nibble of the port D by the given value
			PORTD |= Copy_u8value;
			break ;
		default: break ;

		}


	}
	else
	{
		Local_u8ErrorState =1;
	}

	return Local_u8ErrorState ;

}
