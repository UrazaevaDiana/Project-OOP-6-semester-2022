#pragma once
#include "Ticket.h"
#include "TicketsRegister.h"

class ControlAttempt{

	bool pass; // удачная или неудачная попытка прохода контроля

public:
	//! контроль попыток использования билета
	ControlAttempt(){
		pass = 0;
	}

	//! Попытка прохода контроля
	//! \param ticketsRegister регистр билетов
	//! \param ticketType предъявляемый билет
	//! \param ticketNumber номер билета
	//! \param time время прохода контроля
	//! \return true, если попытка удачная
	bool attemptCheck(TicketsRegister* ticketsRegister, int ticketNumber);
};

