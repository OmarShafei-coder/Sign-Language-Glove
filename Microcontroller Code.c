/*
 * main.c
 *
 *  Created on: Apr 30, 2020
 *      Author: Omar Shafei
 */


#include "util/delay.h"
#include <avr/io.h>
#include <stdlib.h>

void ADC_init(){
	ADCSRA = 0X87;
	ADCSRA |= (1 << ADSC);
	while((ADCSRA & (1 << ADIF)) == 0);
}

void usart_init(){
	UCSRB = (1<<TXEN);
	UCSRC = (1<<UCSZ1) | (1<<UCSZ0) | (1<<URSEL);
	UBRRL = 0X4D;
}
void usart_send(unsigned char ch){
	while(!(UCSRA & (1<<UDRE)));
	UDR = ch;
}
void UART_String_TX(char string[]){

	usart_send(' ');
	for(int i=0; i<strlen(string); i++){
		usart_send(string[i]);
	}
	_delay_ms(1500);
}


int main(void)
{
	PORTD = 0XFF; //HC05
	PORTA = 0X00; //Sensors
	int s0, s1, s2, s3, s4; //sensor reading

	usart_init();
	ADC_init();

	 while(1)
	 {
		 	 	 ADMUX = 0XE0;
				 if(ADCH >= 50 && ADCH <= 100){
					 s0 = 1;
				 }else if(ADCH >= 110 && ADCH <= 140){
					 s0 = 2;
				 }else if(ADCH >= 145 && ADCH <= 200){
					 s0 = 3;
				 }



		 	 	 ADMUX = 0XE1;
				 if(ADCH >= 40 && ADCH <= 70){
					 s1 = 1;
				 }else if(ADCH >= 90 && ADCH <= 110){
					 s1 = 2;
				 }else if(ADCH >= 120 && ADCH <= 160){
					 s1 = 3;
				 }





		 	 	 ADMUX = 0XE2;
				 if(ADCH >= 40 && ADCH <= 70){
					 s2 = 1;
				 }else if(ADCH >= 100 && ADCH <= 120){
					 s2 = 2;
				 }else if(ADCH >= 130 && ADCH <= 180){
					 s2 = 3;
				 }




		 	 	 ADMUX = 0XE3;
				 if(ADCH >= 55 && ADCH <= 65){
					 s3 = 1;
				 }else if(ADCH >= 90 && ADCH <= 125){
					 s3 = 2;
				 }else if(ADCH >= 140 && ADCH <= 180){
					 s3 = 3;
				 }






		 	 	 ADMUX = 0XE4;
				 if(ADCH >= 115 && ADCH <= 140){
					 s4 = 1;
				 }else if(ADCH >= 145 && ADCH <= 160){
					 s4 = 2;
				 }else if(ADCH >= 170 && ADCH <= 195){
					 s4 = 3;
				 }

				 if(s1 == 1 && s0 != 1 && s2 != 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("1");

				}

				 if(s1 == 1 && s0 != 1 && s2 == 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("2");
				 }

				 if(s1 == 1 && s0 != 1 && s2 == 1 && s3 == 1 && s4 != 1){
					 UART_String_TX("3");
				 }

				 if(s1 == 1 && s0 != 1 && s2 == 1 && s3 == 1 && s4 == 1){
					 UART_String_TX("4");
				 }

				 if(s1 == 1 && s0 == 1 && s2 == 1 && s3 == 1 && s4 == 1){
					 //UART_String_TX("5");
					 UART_String_TX("Thanks");
					 UART_String_TX("doctor");
					 UART_String_TX("Samir");

				 }

				 if(s1 != 1 && s0 == 1 && s2 != 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("Ok");
				 }


				 if(s1 == 3 && s0 == 3 && s2 == 3 && s3 == 3 && s4 == 3){
					 UART_String_TX("0");
				 }

				 if(s1 == 1 && s0 == 1 && s2 != 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("Bom");
				 }


				 if(s1 == 1 && s0 != 1 && s2 != 1 && s3 != 1 && s4 == 1){
					 UART_String_TX("I Love you");
				 }

				 if(s1 == 1 && s0 == 1 && s2 != 1 && s3 != 1 && s4 == 1){
					 UART_String_TX("Omar");
				 }

	 }
	 return 0;
}

/*
  	 	 	 	 ADCSRA = 0X87;
		 	 	 ADMUX = 0XE0;
				 ADCSRA |= (1 << ADSC);
				 while((ADCSRA & (1 << ADIF)) == 0);

				 if(ADCH >= 50 && ADCH <= 100){
					 s0 = 1;
				 }else if(ADCH >= 110 && ADCH <= 140){
					 s0 = 2;
				 }else if(ADCH >= 145 && ADCH <= 200){
					 s0 = 3;
				 }



		 	 	 ADCSRA = 0X87;
		 	 	 ADMUX = 0XE1;
				 ADCSRA |= (1 << ADSC);
				 while((ADCSRA & (1 << ADIF)) == 0);

				 if(ADCH >= 40 && ADCH <= 70){
					 s1 = 1;
				 }else if(ADCH >= 90 && ADCH <= 110){
					 s1 = 2;
				 }else if(ADCH >= 120 && ADCH <= 160){
					 s1 = 3;
				 }





		 	 	 ADCSRA = 0X87;
		 	 	 ADMUX = 0XE2;
				 ADCSRA |= (1 << ADSC);
				 while((ADCSRA & (1 << ADIF)) == 0);

				 if(ADCH >= 40 && ADCH <= 70){
					 s2 = 1;
				 }else if(ADCH >= 100 && ADCH <= 120){
					 s2 = 2;
				 }else if(ADCH >= 130 && ADCH <= 180){
					 s2 = 3;
				 }




		 	 	 ADCSRA = 0X87;
		 	 	 ADMUX = 0XE3;
				 ADCSRA |= (1 << ADSC);
				 while((ADCSRA & (1 << ADIF)) == 0);

				 if(ADCH >= 55 && ADCH <= 65){
					 s3 = 1;
				 }else if(ADCH >= 90 && ADCH <= 125){
					 s3 = 2;
				 }else if(ADCH >= 140 && ADCH <= 180){
					 s3 = 3;
				 }





		 	 	 ADCSRA = 0X87;
		 	 	 ADMUX = 0XE4;
				 ADCSRA |= (1 << ADSC);
				 while((ADCSRA & (1 << ADIF)) == 0);

				 if(ADCH >= 115 && ADCH <= 140){
					 s4 = 1;
				 }else if(ADCH >= 145 && ADCH <= 160){
					 s4 = 2;
				 }else if(ADCH >= 170 && ADCH <= 195){
					 s4 = 3;
				 }

				 if(s1 == 1 && s0 != 1 && s2 != 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("1");

				}

				 if(s1 == 1 && s0 != 1 && s2 == 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("2");
				 }

				 if(s1 == 1 && s0 != 1 && s2 == 1 && s3 == 1 && s4 != 1){
					 UART_String_TX("3");
				 }

				 if(s1 == 1 && s0 != 1 && s2 == 1 && s3 == 1 && s4 == 1){
					 UART_String_TX("4");
				 }

				 if(s1 == 1 && s0 == 1 && s2 == 1 && s3 == 1 && s4 == 1){
					 //UART_String_TX("5");
					 UART_String_TX("Thanks");
					 UART_String_TX("doctor");
					 UART_String_TX("Samir");

				 }

				 if(s1 != 1 && s0 == 1 && s2 != 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("Ok");
				 }


				 if(s1 == 3 && s0 == 3 && s2 == 3 && s3 == 3 && s4 == 3){
					 UART_String_TX("0");
				 }

				 if(s1 == 1 && s0 == 1 && s2 != 1 && s3 != 1 && s4 != 1){
					 UART_String_TX("Bom");
				 }


				 if(s1 == 1 && s0 != 1 && s2 != 1 && s3 != 1 && s4 == 1){
					 UART_String_TX("I Love you");
				 }

				 if(s1 == 1 && s0 == 1 && s2 != 1 && s3 != 1 && s4 == 1){
					 UART_String_TX("Omar");
				 }

  */

