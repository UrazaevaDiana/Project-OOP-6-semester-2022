import ctypes
Tickets_Library = ctypes.CDLL('./Project_Urazaeva_Diana_step_3_v210522-2014.dll')

Tickets_Library.create_ticketTripsLimited.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int]
Tickets_Library.create_ticketTripsLimited.restype = ctypes.c_void_p
Tickets_Library.delete_ticketTripsLimited.argtypes = [ctypes.c_void_p]
Tickets_Library.delete_ticketTripsLimited.restype = None
Tickets_Library.create_ticketDaysLimited.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
Tickets_Library.create_ticketDaysLimited.restype = ctypes.c_void_p
Tickets_Library.delete_ticketDaysLimited.argtypes = [ctypes.c_void_p]
Tickets_Library.delete_ticketDaysLimited.restype = None
Tickets_Library.create_register.argtypes = []
Tickets_Library.create_register.restype = ctypes.c_void_p
Tickets_Library.delete_register.argtypes = [ctypes.c_void_p]
Tickets_Library.delete_register.restype = None
Tickets_Library.add_ticket_to_register.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
Tickets_Library.add_ticket_to_register.restype = None
Tickets_Library.create_control_attempt.argtypes = []
Tickets_Library.create_control_attempt.restype = ctypes.c_void_p
Tickets_Library.delete_control_attempt.argtypes = [ctypes.c_void_p]
Tickets_Library.delete_control_attempt.restype = None
Tickets_Library.check_ticket_number.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int]
Tickets_Library.check_ticket_number.restype = ctypes.c_bool
Tickets_Library.check_whole_ticket.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int]
Tickets_Library.check_whole_ticket.restype = ctypes.c_bool

import time
t_start = time.process_time_ns()
timegap = 50000000 # for a trips limited ticket
ticket_number = 1
tickets_trips = []
tickets_days = []
ticket_dict = {}
register = Tickets_Library.create_register()

print('Hello, passenger!');
continue_flag = 1

while (continue_flag == 1):
    action = int(input('If you want to buy a ticket, please, enter 1\n''If you want to pass the control, please, enter 2\n'))
    if (action == 1): # to buy a ticket
        ticket_type = int(input('If you want to buy\n \t a trips limited ticket, please, enter 1\n''\t a days limited ticket, please, enter 2\n'))
        if (ticket_type == 1):
            maxTrips = int(input('enter max number of trips you want \n'))
            if (maxTrips <= 0 or type(maxTrips) is not int):
                print('invalid  max number of trips')
            ticket = Tickets_Library.create_ticketTripsLimited(ticket_number, time.process_time_ns(), maxTrips, timegap)
            tickets_trips.append(ticket)
            ticket_dict[ticket_number] = ticket
            Tickets_Library.add_ticket_to_register(register, ticket)
            print('The ticket number', ticket_number,'is added in Register\n')
            ticket_number += 1
    
        if (ticket_type == 2):
            validityPeriod = int(input('enter ticket validity period [s] you want\n')) * 10**9
            if (validityPeriod <= 0 or type(validityPeriod) is not int):
                print('invalid ticket validity period')
            ticket = Tickets_Library.create_ticketDaysLimited(ticket_number, time.process_time_ns(), validityPeriod)
            tickets_days.append(ticket)
            ticket_dict[ticket_number] = ticket
            Tickets_Library.add_ticket_to_register(register, ticket)
            print('The ticket number', ticket_number,'is added in Register\n')

            ticket_number += 1
   
        if (ticket_type != 1 and ticket_type != 2):
            print('invalid character')

    if (action == 2): # to pass the control
        #print('time: current, start, differensce', time.process_time_ns(), t_start, time.process_time_ns() - t_start)
        control = Tickets_Library.create_control_attempt()
        check_the_ticket_number = int(input('enter the ticket number\n'))
        if (Tickets_Library.check_ticket_number(control, register, check_the_ticket_number)):
            if Tickets_Library.check_whole_ticket(ticket_dict[check_the_ticket_number], check_the_ticket_number, time.process_time_ns()):
                print('Success pass\n');
            else:
                print('Failed pass\n');
        else:
            print('The ticket number',check_the_ticket_number,'not in Register\n');
        Tickets_Library.delete_control_attempt(control)

    if (action != 1 and action != 2):
        print('invalid character')

    continue_flag = int(input('to continue enter 1, to exit enter 2\n'))

for ticket in tickets_trips:
    Tickets_Library.delete_ticketTripsLimited(ticket)
for ticket in tickets_days:
    Tickets_Library.delete_ticketDaysLimited(ticket)

Tickets_Library.delete_register(register)
