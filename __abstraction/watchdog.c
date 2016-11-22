

void configWTD_NORST() //sem reset e com aproximadamente 1 segundo
{
	cli();
	//initialize timer
	// Enter Watchdog Configuration mode:
	//WDTCSR |= (1<<WDCE); //Permite mudar a configura��o do WDT
	WDTCSR |= (1<<WDCE) | (1<<WDE); //Apenas interrup��es e ligar WTD
	WDTCSR = 1<<WDP2 | 1<<WDP1; //Configura��o do tempo
	WDTCSR |= (1<<WDIE);
	//Enable global interrupts
	sei();
	// use --> ISR(WDT_vect)
}

