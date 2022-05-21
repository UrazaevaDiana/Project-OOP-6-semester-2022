#pragma once
#include "Ticket.h"

class TicketsRegister{
	friend class ControlAttempt;
public:

	//! ������� ������� �������
	TicketsRegister(){}
	
	//! ���������� ������ � �������
	void add(int ticketNumber);
	
	//! �������� ������ ������ � ��������
	//! \return true, ���� ����� ���� � ��������
	bool checkTicketNumber(int ticketNumber);
};

