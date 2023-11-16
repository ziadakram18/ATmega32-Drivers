/***********************************************************/
/***********************************************************/
/****************  Auther  : Ziad Akram ********************/
/****************  Layer   : HAL        ********************/
/****************  SWC     : LED        ********************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to led as output pin
* Parameters :
            => struct has the led port , pin , status
* return : void
*/
void LED_voidInit( LED_Type LED_Configuration )
{

	DIO_u8SetPinDirection( LED_Configuration.Port , LED_Configuration.Pin , DIO_u8PIN_OUTPUT );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set high on led pin ( led on )
* Parameters :
            => struct has the led port , pin , status
* return : void
*/
void LED_voidOn  ( LED_Type LED_Configuration )
{

	if( LED_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_u8SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_u8PIN_HIGH );

	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){

		DIO_u8SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_u8PIN_LOW  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set low on led pin ( led off )
* Parameters :
             => struct has the led port , pin , status
* return : void
*/
void LED_voidOff ( LED_Type LED_Configuration )
{

	if( LED_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_u8SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_u8PIN_LOW  );

	}else if( LED_Configuration.Active_State == ACTIVE_LOW ){

		DIO_u8SetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_u8PIN_HIGH  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function toggle led pin
* Parameters :
             => struct has the led port , pin , status
* return : void
*/
void LED_voidToggle      ( LED_Type LED_Configuration )
{
	DIO_u8TogglePinValue  ( LED_Configuration.Port , LED_Configuration.Pin );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
