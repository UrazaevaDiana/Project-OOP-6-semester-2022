﻿#include <cassert>
#include <stdio.h>
#include "TicketTripsLimited.h"
#include "TicketDaysLimited.h"
#include "ControlAttempt.h"
#include "TicketsRegister.h"
#include "pch.h"

extern "C" {

    void test_TicketControl(int timegap) {
        TicketTripsLimited ticket1(1, 0, 2, timegap); //билет на заданное число поездок (номер билета, время продажи, максимальное число поездок)

        assert(ticket1.controlAttempt(10)); // успешный проход
        assert(!ticket1.controlAttempt(14)); // неудачный проход: время после предыдущего прохода менее 5 с
        assert(ticket1.controlAttempt(16)); // успешный проход
        assert(!ticket1.controlAttempt(30)); // неудачный проход: билет израсходован

        TicketDaysLimited ticket2(2, 0, 10); //билет с ограниченным сроком действия (номер билета, время продажи, срок действия)

        assert(ticket2.controlAttempt(1)); // успешный проход
        assert(!ticket2.controlAttempt(17)); // неудачный проход: истек срок действия

        TicketTripsLimited ticket3(3, 0, 2, timegap); //билет на заданное число поездок (номер билета, время продажи, максимальное число поездок)
        TicketTripsLimited ticket4(4, 0, 8, timegap); //билет на заданное число поездок (номер билета, время продажи, максимальное число поездок)                                              

        ControlAttempt attempt1(ticket3, 1); //успешная попытка прохода контроля
        ControlAttempt attempt2(ticket3, 7); //успешная попытка прохода контроля
        ControlAttempt attempt3(ticket3, 18); //неудачная попытка прохода контроля

        TicketsRegister ticketsRegister0; //создание регистра билетов
        ticketsRegister0.add(ticket1.get_number()); //добавление билета в регистр
        ticketsRegister0.add(ticket2.get_number()); //добавление билета в регистр
        ticketsRegister0.add(ticket4.get_number()); //добавление билета в регистр

        TicketDaysLimited* pticket2 = &ticket2;
        TicketTripsLimited* pticket3 = &ticket3;
        TicketTripsLimited* pticket4 = &ticket4;

        assert(ticketsRegister0.check(pticket4, ticket4.get_number(), 10)); //билет на заданное число поездок есть в регистре
        assert(!ticketsRegister0.check(pticket4, ticket4.get_number(), 12)); //билет на заданное число поездок есть в регистре, но время после предыдущего прохода менее 5 с
        assert(!ticketsRegister0.check(pticket2, ticket2.get_number(), 14)); //билет с ограниченным сроком действия есть в регистре, но истек срок действия
        assert(!ticketsRegister0.check(pticket3, ticket3.get_number(), 16)); //билета на заданное число поездок нет в регистре
    }

}

int main(){
    int timegap = 5;

    //test_TicketControl(timegap);

    
    return 0;
}