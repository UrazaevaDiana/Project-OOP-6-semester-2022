#pragma once
class Ticket{
	friend class TicketsRegister;
	//int *number = new int;
	int number;
	int time;
	
public:

	//! создать базовый тип билета
	//! \param number номер билета
	//! \param time время продажи билета (целое число секунд с некоторого фиксированного момента времени) 
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

	//! получение времени продажи билета
	//! \return time время продажи билета
	int get_time() {
		return time;
	}

	//! оператор сравнения по времени прохода
	bool operator==(Ticket& other) const {
		return this->time == other.get_time();
	}
	
	//! оператор сравнения по времени прохода
	bool operator<(Ticket& other) const {
		return this->time < other.get_time();
	}
};

