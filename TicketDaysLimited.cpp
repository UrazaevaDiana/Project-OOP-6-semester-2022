#include "TicketDaysLimited.h"
#include <stdio.h>
#include "pch.h"

bool TicketDaysLimited::controlAttempt(int newtime) {
	
	if (validityPeriod < (newtime - get_time()) || validityPeriod == (newtime - get_time())) {
		//printf("The ticket number %d: failed pass by validityPeriod\n", get_number());
		return false;
	}
	else {
		//printf("The ticket number %d: success pass\n", get_number());
		return true;
	}

}