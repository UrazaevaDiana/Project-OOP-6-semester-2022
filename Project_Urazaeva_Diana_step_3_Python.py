import ctypes
Tickets_Library = ctypes.CDLL('./Project_Urazaeva_Diana_step_3.dll')

print('Hello, passenger!');

Tickets_Library.create_ticket.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int]
Tickets_Library.create_ticket.restype = ctypes.c_void_p
Tickets_Library.delete_ticket.argtypes = [ctypes.c_void_p]
Tickets_Library.delete_ticket.restype = None
Tickets_Library.create_register.argtypes = []
Tickets_Library.create_register.restype = ctypes.c_void_p
Tickets_Library.delete_register.argtypes = [ctypes.c_void_p]
Tickets_Library.delete_register.restype = None
Tickets_Library.add_ticket_to_register.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
Tickets_Library.add_ticket_to_register.restype = None

ticket1 = Tickets_Library.create_ticket(333,0,10,5)
register = Tickets_Library.create_register()
Tickets_Library.add_ticket_to_register(register, ticket1)
Tickets_Library.delete_ticket(ticket1)
Tickets_Library.delete_register(register)