#pragma once
class Ticket{
	friend class TicketsRegister;
	int number;
	int time;
	
public:

	//! ������� ������� ��� ������
	//! \param number ����� ������
	//! \param time ����� ������� (����� ����� ������ � ���������� �������������� ������� �������) 
	Ticket(int number, int time)
		:number(number), time(time) {}

	//! ������� ������� ��������
	//! \return true, ���� ������ ��������
	virtual bool controlAttempt(int newtime);

	//! ��������� ������ ������
	//! \return number ����� ������
	int get_number() {
		return number;
	}

	int get_time() {
		return time;
	}

};

