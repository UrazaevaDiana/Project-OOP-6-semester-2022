#include "ControlAttempt.h"
#include "TicketTripsLimited.h"
#include "TicketDaysLimited.h"
#include <stdio.h>
#include "pch.h"
/*
bool TicketTripsLimited::controlAttempt(int newtime) {
	int timegap = 5;
	printf("\n%d\n", (newtime - timeLastPass));

	if (leftTrips <= 0) {
		printf("failed pass by trips\n");
		return false;
	}

	if (timegap < (newtime - timeLastPass) || timegap == (newtime - timeLastPass)) {
		printf("success pass\n");
		timeLastPass = newtime;
		--leftTrips;
		return true;
	}
	else {
		printf("failed pass by time\n");
		return false;
	}

	//...//

	if (validityPeriod < (newtime - time) || validityPeriod == (newtime - time)) {
		printf("success pass\n");
		return true;
	}
	else {
		printf("failed pass by validityPeriod\n");
		return false;
	}

}*/