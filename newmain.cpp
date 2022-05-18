#include <cassert>
#include <stdio.h>
#include "TicketTripsLimited.h"
#include "TicketDaysLimited.h"
#include "ControlAttempt.h"
#include "TicketsRegister.h"
#include "pch.h"

extern "C" {

	__declspec(dllexport) TicketTripsLimited* create_ticket(int number, int time, int maxTrips, int timegap){
		return new TicketTripsLimited(number, time, maxTrips, timegap);
	}

	__declspec(dllexport) void delete_ticket(TicketTripsLimited* T){
		delete T;
	}
	
	__declspec(dllexport) TicketsRegister* create_register(){
		return new TicketsRegister();
	}

	__declspec(dllexport) void delete_register(TicketsRegister* R){
		delete R;
	}
	
	__declspec(dllexport) void add_ticket_to_register(TicketsRegister* ticketsRegister, Ticket* ticket) {

		ticketsRegister->add(ticket->get_number());
	}
}