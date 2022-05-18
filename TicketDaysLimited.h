#pragma once
#include "Ticket.h"

class TicketDaysLimited: public Ticket {

	int validityPeriod;

public:
	//! создать билет с ограниченным сроком действия
	//! \param number номер билета
	//! \param time время продажи (целое число секунд с некоторого фиксированного момента времени)
	//! \param validityPeriod срок действия (целое число секунд с момента продажи)
	TicketDaysLimited(int number, int time, int validityPeriod)
		:Ticket(number, time) {
		this->validityPeriod = validityPeriod;
	}
	/*
	//! операторы сравнения по времени прохода
	bool operator==(const TicketDaysLimited& other) const {
		return this->time == other.time; //return this->time == other.time;
	}

	bool operator<(const TicketDaysLimited& other) const {
		return this->time < other.time;
	}
	*/
	//! попытка прохода контроля
	//! \return true, если проход успешный
	bool controlAttempt(int newtime);

};

