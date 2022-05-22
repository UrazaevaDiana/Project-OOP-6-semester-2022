#pragma once
#include <stdio.h>
#include "Ticket.h"
#include <exception> 

class TicketTripsLimited: public Ticket{
	int maxTrips;
	int leftTrips;
	int timeLastPass;
	int timegap;

public:
	//! ������� ����� �� �������� ����� �������
	//! \param number ����� ������
	//! \param time ����� ������� (����� ����� ������ � ���������� �������������� ������� �������) 
	//! \param maxTrips ������������ ����� �������
	//! \param leftTrips ���������� ����� �������
	//! \param timeLastPass ����� ���������� �������
	TicketTripsLimited(int number, int time, int maxTrips, int timegap) :
		Ticket(number, time) {
		//this->leftTrips = maxTrips;
		//this->maxTrips = maxTrips;
		this->timegap = timegap;
		this->timeLastPass = time - timegap;

		if (maxTrips <= 0)
				throw std::exception();
		else {
				this->leftTrips = maxTrips;
				this->maxTrips = maxTrips;
			}
	}
	
	//! ������� ������� ��������
	//! \return true, ���� ������ ��������
	bool controlAttempt(int newtime);

};