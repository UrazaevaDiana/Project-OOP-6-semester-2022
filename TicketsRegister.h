#pragma once
#include "Ticket.h"

class TicketsRegister{
	friend class ControlAttempt;
public:

	//! создать регистр билетов
	TicketsRegister(){}
	
	//! добавление билета в регистр
	void add(int ticketNumber);
	
	//! проверка номера билета в регистре
	//! \return true, если билет есть в регистре
	bool checkTicketNumber(int ticketNumber);
};

