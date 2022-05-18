#pragma once

class ControlAttempt{

	//int time; // по заданию эта переменная должна быть
	bool pass;

public:
	//! Попытка прохода контроля
	//! \param ticketType предъявляемый билет
	//! \param time время прохода контроля
	//! \param pass удачная или неудачная попытка прохода контроля
 
	template <typename T>
	ControlAttempt(T& ticketType, int time){
		pass = ticketType.controlAttempt(time);
	}
};

