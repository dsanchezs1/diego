/*

 * main.c
 *
 *  Created on: Feb 12, 2023
 *      Author: diego
 */


#include "leon3_uart.h"

/*int main()

{
	leon3_putchar('p');
	leon3_putchar('2');
	leon3_putchar('\n');
	while(!leon3_uart_tx_fifo_is_empty())
		;

	return 0;
}*/

int main() {
	int i = 0;
	char aux = 0;
	for (i = 0; i<10; i++) {
		leon3_putchar(aux);
		leon3_putchar('\n');
		aux++;
	}
	while (!leon3_uart_tx_fifo_is_empty())
		;
	return 0;
}
