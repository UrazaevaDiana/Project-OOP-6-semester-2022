#pragma once

class ControlAttempt{

	//int time; // �� ������� ��� ���������� ������ ����
	bool pass;

public:
	//! ������� ������� ��������
	//! \param ticketType ������������� �����
	//! \param time ����� ������� ��������
	//! \param pass ������� ��� ��������� ������� ������� ��������
 
	template <typename T>
	ControlAttempt(T& ticketType, int time){
		pass = ticketType.controlAttempt(time);
	}
};

