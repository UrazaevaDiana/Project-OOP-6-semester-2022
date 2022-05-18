#include <stdio.h>
#include "TicketsRegister.h"
#include "pch.h"

struct node // ��������� ��� ������������� ����� AVL-������
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) {
		key = k;
		left = right = 0;
		height = 1;
	}
};

static node* head = nullptr;

//������ ������

unsigned char height(node* p)
{
	return p ? p->height : 0;
}

int bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateRight(node* p) // ������ ������� ������ p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateLeft(node* q) // ����� ������� ������ q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // ������������ ���� p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateRight(p->right);
		return rotateLeft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateLeft(p->left);
		return rotateRight(p);
	}
	return p;
}

node* insert(node* p, int k) // ������� ����� k � ������ � ������ p
{
	if (!p)
		return new node(k);
	if (k < p->key){
		p->left = insert(p->left, k);
	}	
	else {
		p->right = insert(p->right, k);
	}
	return balance(p);
}

void TicketsRegister::add(int ticketNumber){

	printf("The ticket number %d is added in Register\n", ticketNumber);
	head = insert(head, ticketNumber);
}

bool TicketsRegister::check(Ticket* ticketType, int ticketNumber, int time){

	//�������� ������� ������ � ��������
	node* p = head;
	if (p == nullptr) {
		printf("The ticket number %d: not in Register\n", ticketNumber);
		return false;
	}
	
	//�������� ������� ������ � ��������
	int k = ticketType->number;

	while (k != p->key && (p->left != nullptr || p->right != nullptr)){
	if (k < p->key)
		p = p->left;
	else
		p = p->right;
	}

	//�������� ���������� ������ �� ���� �������� ��� ����� ���������� ������� 
	if (k == p->key) {				
		if (!ticketType->controlAttempt(time))
			return false;
		return true;
	}
		
	else {
		printf("The ticket number %d: not in Register\n", ticketNumber);
		return false;
	}
}