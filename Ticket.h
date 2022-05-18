#pragma once
class Ticket{
	friend class TicketsRegister;
	int number;
	int time;
	
public:

	//! создать базовый тип билета
	//! \param number номер билета
	//! \param time время продажи (целое число секунд с некоторого фиксированного момента времени) 
	Ticket(int number, int time)
		:number(number), time(time) {}

	//! попытка прохода контроля
	//! \return true, если проход успешный
	virtual bool controlAttempt(int newtime);

	//! получение номера билета
	//! \return number номер билета
	int get_number() {
		return number;
	}

	int get_time() {
		return time;
	}

};

