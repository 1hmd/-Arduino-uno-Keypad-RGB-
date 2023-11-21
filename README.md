# -Arduino-uno-Keypad-RGB-
It is coded for an Arduino board with a keypad that controls RGB LED lights and has a spam mode feature that changes LED colors repeatedly when a key is held down. It includes a Keypad library and defines variables for the keypad layout and pinouts, as well as functions for controlling the LED lights. An array is used to track which key is holding to determine the LED color, and the code checks for key presses and toggles spam mode.
It is important to note that this code is not perfect and can be improved. 

NOTE: You need both ``key.cpp`` and ``key.h``


Den här är lite svårare, men var noggrann så går det:
sudo apt install libcurses-perl <Tryck Enter>
cd /tmp <Tryck Enter>
wget http://search.cpan.org/CPAN/authors/id/K/KB/KBAUCOM/
Term-Animation-2.4.tar.gz  <--Allt på en rad från wget  <Tryck Enter>
tar -zxvf Term-Animation-2.4.tar.gz <Tryck Enter>
cd Term-Animation-2.4/ <Tryck Enter>
sudo apt install make <Tryck Enter>
perl Makefile.PL &&  make && make test <Tryck Enter>
sudo make install <Tryck Enter>

cd /tmp <Tryck Enter>
wget http://www.robobunny.com/projects/asciiquarium/asciiquarium.tar.gz <Tryck Enter>
tar -zxvf asciiquarium.tar.gz <Tryck Enter>
cd asciiquarium_1.1/ <Tryck Enter>
sudo cp asciiquarium /usr/local/bin <Tryck Enter>
sudo chmod 0755 /usr/local/bin/asciiquarium <Tryck Enter>
Har du lyckats komma så här långt? Grattis!
Testa nu asciiquarium och njut av synen ;)
<Screenshot here>
