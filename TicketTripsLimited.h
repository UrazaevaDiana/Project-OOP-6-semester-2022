#pragma once
#include "Ticket.h"

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
		this->leftTrips = maxTrips;
		this->maxTrips = maxTrips;
		this->timegap = timegap;
		this->timeLastPass = time - timegap;
	}
	/*
	//! ��������� ��������� �� ������� �������
	bool operator==(const TicketTripsLimited& other) const {
		return this->time == other.time; //return this->time == other.time;
	}

	bool operator<(const TicketTripsLimited& other) const {
		return this->time < other.time;
	}*/
	
	//! ������� ������� ��������
	//! \return true, ���� ������ ��������
	bool controlAttempt(int newtime);

};