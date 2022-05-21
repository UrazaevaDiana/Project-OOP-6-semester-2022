#include "TicketTripsLimited.h"
#include <stdio.h>
#include "pch.h"

bool TicketTripsLimited::controlAttempt(int newtime) {

	if (leftTrips <= 0) {
		//printf("The ticket number %d: failed pass by trips\n", get_number());
		return false;	
	}
	
	if ((timegap < (newtime-timeLastPass)) || (timegap == (newtime - timeLastPass))) {
		//printf("The ticket number %d: success pass\n", get_number());
		timeLastPass = newtime;
		--leftTrips;
		return true;
	}
	else {
		//printf("The ticket number %d: failed pass by time\n", get_number());
		return false;
	}	
	
}