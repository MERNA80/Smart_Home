

#include "../../LIB/STD_types.h"
#include "../../LIB/BitMath.h"
#include "../../MCAL//MDIO/DIO.h"
#include "BUTTON_INTERFACE.h"

void BUTTON_VoidInIt (BUTTON_t* Copy_PstructButton){
	MDIO_voidInitPin  ( Copy_PstructButton->Port ,  Copy_PstructButton->Pin , DIO_INPUT);
	MDIO_voidSetPinValue (Copy_PstructButton->Port ,  Copy_PstructButton->Pin , DIO_HIGH);

}


u8 BUTTON_u8GetState (BUTTON_t* Copy_PstructButton){
	return MDIO_u8ReadPin  (Copy_PstructButton->Port , Copy_PstructButton->Pin);
}






