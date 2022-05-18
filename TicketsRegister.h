#pragma once
#include "Ticket.h"

class TicketsRegister{

public:

	//! создать регистр билетов
	TicketsRegister(){}
	
	//! добавление билета в регистр
	void add(int ticketNumber);
	
	//! проверка билета в регистре
	//! \return true, если проверка билета успешная
	bool check(Ticket* ticketType, int ticketNumber, int time);
};

