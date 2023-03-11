/*

 * main.c
 *
 *  Created on: Feb 12, 2023
 *      Author: diego
 */


#include "leon3_uart.h"
#include "leon3_bprint.h"

int main() {
	char * pchar="cadena\n";
	leon3_print_string(pchar);
	leon3_print_uint8(3); leon3_putchar('\n');
	leon3_print_uint8(143); leon3_putchar('\n');
	leon3_print_uint16(1080); leon3_putchar('\n');
	return 0;
}
