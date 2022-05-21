#include <cassert>
#include <stdio.h>
#include "TicketTripsLimited.h"
#include "TicketDaysLimited.h"
#include "ControlAttempt.h"
#include "TicketsRegister.h"
#include "pch.h"

extern "C" {

	__declspec(dllexport) TicketTripsLimited* create_ticketTripsLimited(int number, int time, int maxTrips, int timegap) {
		return new TicketTripsLimited(number, time, maxTrips, timegap);
	}

	__declspec(dllexport) void delete_ticketTripsLimited(TicketTripsLimited* T) {
		delete T;
	}

	__declspec(dllexport) TicketDaysLimited* create_ticketDaysLimited(int number, int time, int validityPeriod) {
		return new TicketDaysLimited(number, time, validityPeriod);
	}

	__declspec(dllexport) void delete_ticketDaysLimited(TicketDaysLimited* T) {
		delete T;
	}
	
	__declspec(dllexport) TicketsRegister* create_register() {
		return new TicketsRegister();
	}

	__declspec(dllexport) void delete_register(TicketsRegister* R) {
		delete R;
	}
	
	__declspec(dllexport) void add_ticket_to_register(TicketsRegister* ticketsRegister, Ticket* ticket) {
		ticketsRegister->add(ticket->get_number());
	}

	__declspec(dllexport) ControlAttempt* create_control_attempt() {
		return new ControlAttempt();
	}

	__declspec(dllexport) void delete_control_attempt(ControlAttempt* C) {
		delete C;
	}

	__declspec(dllexport) bool check_ticket_number(ControlAttempt* control, TicketsRegister* ticketsRegister, int ticketNumber) {
		return control->attemptCheck(ticketsRegister, ticketNumber);
	}

	__declspec(dllexport) bool check_whole_ticket(Ticket* ticketType, int ticketNumber, int time) {
		if (ticketType->controlAttempt(time))
			return true;
		else
			return false;
	}
}