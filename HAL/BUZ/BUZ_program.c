/***********************************************************/
/***********************************************************/
/****************  Auther  : Ziad Akram ********************/
/****************  Layer   : HAL        ********************/
/****************  SWC     : BUZ        ********************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "BUZ_interface.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to BUZ as output pin
* Parameters :
            => struct has the BUZ port , pin , status
* return : void
*/
void BUZ_voidInit( BUZ_Type BUZ_Configuration )
{

	DIO_u8SetPinDirection( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_u8PIN_OUTPUT );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set high on BUZ pin ( BUZ on )
* Parameters :
            => struct has the BUZ port , pin , status
* return : void
*/
void BUZ_voidOn  ( BUZ_Type BUZ_Configuration )
{

	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_u8SetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_u8PIN_HIGH );

	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){

		DIO_u8SetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_u8PIN_LOW  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set low on BUZ pin ( BUZ off )
* Parameters :
             => struct has the BUZ port , pin , status
* return : void
*/
void BUZ_voidOff ( BUZ_Type BUZ_Configuration )
{

	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_u8SetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_u8PIN_LOW  );

	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){

		DIO_u8SetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_u8PIN_HIGH  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function toggle BUZ pin
* Parameters :
             => struct has the BUZ port , pin , status
* return : void
*/
void BUZ_voidToggle      ( BUZ_Type BUZ_Configuration )
{
	DIO_u8TogglePinValue  ( BUZ_Configuration.Port , BUZ_Configuration.Pin );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
