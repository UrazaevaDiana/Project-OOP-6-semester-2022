#pragma once
#include "Ticket.h"

class TicketDaysLimited: public Ticket {

	int validityPeriod;

public:
	//! ������� ����� � ������������ ������ ��������
	//! \param number ����� ������
	//! \param time ����� ������� (����� ����� ������ � ���������� �������������� ������� �������)
	//! \param validityPeriod ���� �������� (����� ����� ������ � ������� �������)
	TicketDaysLimited(int number, int time, int validityPeriod)
		:Ticket(number, time) {
		this->validityPeriod = validityPeriod;
	}

	//! ������� ������� ��������
	//! \return true, ���� ������ ��������
	bool controlAttempt(int newtime);

};

