#pragma once
class Ticket{
	friend class TicketsRegister;
	//int *number = new int;
	int number;
	int time;
	
public:

	//! ������� ������� ��� ������
	//! \param number ����� ������
	//! \param time ����� ������� ������ (����� ����� ������ � ���������� �������������� ������� �������) 
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

	//! ��������� ������� ������� ������
	//! \return time ����� ������� ������
	int get_time() {
		return time;
	}

	//! �������� ��������� �� ������� �������
	bool operator==(Ticket& other) const {
		return this->time == other.get_time();
	}
	
	//! �������� ��������� �� ������� �������
	bool operator<(Ticket& other) const {
		return this->time < other.get_time();
	}
};

