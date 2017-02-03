# Arduino-Remote-Serial-Commander
Use a PC to control a remote Arduino using Radio or Serial cable.

Construct the Master and Slave units, an Arduino UNO or Nano could be used, upload the sketches. Note that the Slave unit uses Arduino pins D0 and D1 for Serial communication, this is to allow the maximum number of pins for Control purpose. Load the Slave sketch, then connect pins 0 and 1. The Master unit used Software Serial on pins D2 and D3.

Serial devices can be HC05/06 Bluetooth, in this case a Bluetooth Dongle or, if available, the Bluetooth on the PC can be used for the master (instead of the Arduino Master). Alternativly one unit could have an HC05 set as a Master and the other unit could have a HC06 as a Slave.

HC-12 433mHz radio units can be used for longer rage (up to 1km?), one on the Master and one on the Slave. These units need no library to work.

Finally, the Master and Slave can be connected with a three core cable (Tx to Rx and Rx to Tx and Gnd to Gnd). Obviously only one Serial Device can be used at a time!

Once the units have been constructed plug the Master into the USB socket of your PC (for this initial test use hard wired Serial port to connect the Master and Slave). Supply power to the Slave unit and run the PC program. Once the main screen shows click on the Serial Port Radio Button, then click on the Baud rate drop down box and select 9600. Click on the COM Port box and select the port used by the Master Arduino. The two units should quickly connect and the state of the Digital and Analog pins on the Remote will be shown, to change a Digital OUTPUT state click on the button.

The Beacon button will flash the LED connected to pin 13 on the remote Arduino once every 2 seconds all the time it is in contact with the Master. It will stop flashing if contact is lost, resuming once contact is made again.

For a full description see my blog at https://rydepier.wordpress.com/2017/02/02/controlling-a-remote-arduino-using-a-pc/
