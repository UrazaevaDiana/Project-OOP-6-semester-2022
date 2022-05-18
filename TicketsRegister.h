#pragma once
#include "Ticket.h"

class TicketsRegister{

public:

	//! ������� ������� �������
	TicketsRegister(){}
	
	//! ���������� ������ � �������
	void add(int ticketNumber);
	
	//! �������� ������ � ��������
	//! \return true, ���� �������� ������ ��������
	bool check(Ticket* ticketType, int ticketNumber, int time);
};

