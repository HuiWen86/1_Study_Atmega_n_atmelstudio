/*
 * fast_pwm_led_control.cpp
 *
 * Created: 2024-04-05 오전 10:27:00
 * Author : 2
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
    DDRB |= (1<<PB3);
	//타이머 /카운터2번을 고속 PWM 모드로 설정
	TCCR2A |= (1<<WGM21) |(1<<WGM20);
	TCCR2A |= (1<<COM2A1); //비반전 모드
	TCCR2B |= (1<<CS22); //분주비64
	
	while (1) 
    {
		for(int i =0; i<256; i++){
		OCR2A= i; // 듀티 사이클 설정
		_delay_ms(10);
		}
    }
}

