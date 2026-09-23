/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: ??? ????
 */

#include "../LIB/STD_TYPES.h"
#include "DEVICES_APP.h"

int main(void) {

    Devices_App_voidInit();

    while (1) {

        Devices_App_voidUpdate();
    }

    return 0;
}
