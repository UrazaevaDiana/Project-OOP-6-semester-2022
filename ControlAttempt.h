#pragma once
#include "Ticket.h"
#include "TicketsRegister.h"

class ControlAttempt{

	bool pass; // ������� ��� ��������� ������� ������� ��������

public:
	//! �������� ������� ������������� ������
	ControlAttempt(){
		pass = 0;
	}

	//! ������� ������� ��������
	//! \param ticketsRegister ������� �������
	//! \param ticketType ������������� �����
	//! \param ticketNumber ����� ������
	//! \param time ����� ������� ��������
	//! \return true, ���� ������� �������
	bool attemptCheck(TicketsRegister* ticketsRegister, int ticketNumber);
};

