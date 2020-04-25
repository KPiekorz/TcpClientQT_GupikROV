# TcpClientQT_GupikROV

Aplikacja sluzy do realizacji komunikacji ethernet pomiedzy stacja kontroli, a stm32h745zi sterujący ROV. 
W tym celu zostały zaimplementowne trzy klasy:

1. TcpClientSocket:
Odpowiada za stworzenie klienta TCP i komunikacje z ROV.


2. CommandPacket:
Przechowywanie i tworzenie komend służacych do sterowania praca ROV.
Atrybuty:
- 


3. DataPacket