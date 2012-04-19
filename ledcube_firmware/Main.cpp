/*
===========================================================================

ledcube_firm GPL Source Code
Copyright (C) 2012 Tino Göhlert, cmdrkeen.net.

This file is part of the ledcube_firm Source Code.

ledcube_firm is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ledcube_firm Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ledcube_firm Source Code.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#include "Main.h"

enum command_e{
	CMD_TEXT    	= 0xF0,
	CMD_HEART   	= 0xF1,
	CMD_SMILE   	= 0xF2,
	CMD_BUBBLES 	= 0xF3,
	CMD_BOUNCE  	= 0xF4,
	CMD_INFINITE 	= 0xF5,
	CMD_DEBUG 		= 0xF6
};

struct command_s{
	byte   cmd;
	byte   mod;
	byte   len;
	char*  buf;
}g_command;
char g_buff[64];

byte bt_state = 0xF0,bt_val = 0, bt_save = 0;

void proc_vars()
{
    bt_val = digitalRead(A1);
    if(bt_save != bt_val && bt_val == LOW){
    	if(bt_state == 0xF6) bt_state = 0xF0;
    	else bt_state++;

    	g_command.cmd = bt_state;
    }

    bt_save = bt_val;
}

void setup() {
	g_command.mod = MOD_SLIDE;
	g_command.cmd = CMD_TEXT;

	Serial.begin(9600);
	Serial.write("LED CUBE rev. 1\r\n");
	analogReference(DEFAULT);

	pinMode(A1, INPUT);

	LedCube::init();

	Effect1.setspeed(120);
	Effect1.setmod(g_command.mod);

	g_command.buf = g_buff+3;

	strcpy(g_command.buf,"RALPH");
	g_command.len = strlen(g_command.buf);
}


void fetchdata()
{

	int i = 0;
	for(;Serial.available() > 0 && i<32;i++) {
		g_buff[i] = Serial.read();
	}

	if(i>1){
		g_command.cmd = g_buff[0];
		g_command.mod = g_buff[1];
		g_command.len = g_buff[2];
		strcpy(g_command.buf,g_buff+3);
	}

	proc_vars();

}


void loop() {
	fetchdata();

	switch(g_command.cmd){
	case CMD_TEXT:
		Effect1.drawstring(g_command.buf,g_command.len);
		break;
	case CMD_HEART:
		Effect1.music();
		break;
	case CMD_SMILE:
		Effect1.smiley();
		break;
	case CMD_BUBBLES:
		Effect1.bubbles();
		break;
	case CMD_BOUNCE:
		Effect1.infinitesquare();
		break;
	case CMD_INFINITE:
		Effect1.bounce();
		break;
	case CMD_DEBUG:
		if(g_command.mod == MOD_DBG_COORD)
			Effect1.debug((byte)g_command.buf[0],
						  (byte)g_command.buf[1],
						  (byte)g_command.buf[2]);
		else if(g_command.mod == MOD_DBG_NUMBER)
			Effect1.debug((byte)g_command.buf[0],(byte)g_command.buf[0]);
		break;
	}

}
