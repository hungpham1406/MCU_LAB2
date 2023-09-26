/*
 * software_timer.c
 *
 *  Created on: Sep 26, 2023
 *      Author: Asus
 */
#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;

void setTimer1(int duration) {
	timer1_counter = duration;
	timer1_flag = 0;
}

void timerRun() {
	if(timer1_counter > 0) {
		timer1_counter--;
		if(timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
}
