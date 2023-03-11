/*
 * main.c
 *
 *  Created on: Feb 25, 2023
 *      Author: diego
 */


#include "leon3_uart.h"
#include "leon3_bprint.h"
#include "leon3_hw_irqs.h"
#include "leon3_ev_handling.h"

void device_hw_irq_level_1_handler(void)
{
	leon3_print_string("Device HW IRQ user handler \n");

}

int main()

{

	//Instalar como manejador del trap 0x83 la rutina
	// que habilita las interrupciones
	leon3_set_trap_handler(0x83,leon3_trap_handler_enable_irqs);

	//Instalar el manejador del trap que 0x84 la rutina
	// que deshabilita las interrupciones
	leon3_set_trap_handler(0x84,leon3_trap_handler_disable_irqs);

	//Llamada al sistema para deshabilitar las interrupciones
	leon3_sys_call_disable_irqs();

	//COMPLETAR
	//
	//

	//Enmascarar todas las interrupciones
	leon3_mask_all_irqs();

	//Instalar la función device_hw_irq_level_1_handler como
	// manejador de usuario de la interrupción de nivel 1
	leon3_install_user_hw_irq_handler(1, device_hw_irq_level_1_handler);

	//Desenmascarar la interrupción de nivel 1
	leon3_unmask_irq(1);

	//Llamada al sistema para habilitar las interrupciones
	leon3_sys_call_enable_irqs();
	//Fuerza la interrupción

	// Ejercicio 5
	//leon3_mask_irq(1);

	leon3_force_irq(1);



	//Fin completar

	///Ejercicio 7


	/*uint8_t i;
	uint8_t j;
	for(i=10; i>0; i--){
		j=j/(i-9);
	}

	return 0;

	/*void sw_trap_vector_0x82_handler(void){
		int8_t i;
		char* str = "error, division por cero\n";

		for (i = 0; str[i] != '\0'; i++){
			leon3_putchar(str[i]);
		}

	}
	leon3_set_trap_handler(0x82,sw_trap_vector_0x82_handler);*/


}
