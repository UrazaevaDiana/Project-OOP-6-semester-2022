#pragma once
#include "Ticket.h"

class TicketTripsLimited: public Ticket{
	int maxTrips;
	int leftTrips;
	int timeLastPass;
	int timegap;

public:
	//! создать билет на заданное число поездок
	//! \param number номер билета
	//! \param time время продажи (целое число секунд с некоторого фиксированного момента времени) 
	//! \param maxTrips максимальное число поездок
	//! \param leftTrips оставшееся число поездок
	//! \param timeLastPass время последнего прозода
	TicketTripsLimited(int number, int time, int maxTrips, int timegap) :
		Ticket(number, time) {
		this->leftTrips = maxTrips;
		this->maxTrips = maxTrips;
		this->timegap = timegap;
		this->timeLastPass = time - timegap;
	}
	/*
	//! операторы сравнения по времени прохода
	bool operator==(const TicketTripsLimited& other) const {
		return this->time == other.time; //return this->time == other.time;
	}

	bool operator<(const TicketTripsLimited& other) const {
		return this->time < other.time;
	}*/
	
	//! попытка прохода контроля
	//! \return true, если проход успешный
	bool controlAttempt(int newtime);

};