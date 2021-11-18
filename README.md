# Alarm-System--Bluetooth
Details
Bluetooth                                                                                                       Arduino
EN	3.3V
+5V	 5V
GND	GND
TX	10  
RX	11

AT command mode-
AT
AT+ADDR?     // Note the address of slave and master.
AT+ROLE?     // ROLE=0 i.e. it is slave; Role=1 i.e. it is master
 AT+ROLE=n   // here n=0 means to change rile to slave, n=1 means to change role to master.
AT+UART?     // To check baud rate (should be same for master and slave)
                                (use same rate for transferring data ) prefer 38400
AT+UART=38400,0,0     // To change baud rate
AT+BIND=n    // n is address ex- 0021,13,0039FC (commas used in master AT command)
                                                   Ex- 0021:12:0039FC (colon used in slave command)  
Now get exit from command mode.
        
Button   04 and 02     -of  Nano board 	Button 05v, 02 of Arduino board
Vibrator (redwire)08 and
 (black wire) GND - Nano board 	BUZZER -  Vcc to 8 pins   of Arduino and GND to GND of Arduino and GND of buzzer to I/O of buzzer. 

