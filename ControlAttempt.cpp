#include "ControlAttempt.h"
#include "pch.h"

bool ControlAttempt::attemptCheck(TicketsRegister* ticketsRegister, int ticketNumber) {
	return pass = ticketsRegister->checkTicketNumber(ticketNumber);
}