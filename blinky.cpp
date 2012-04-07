#include "blinky.h"

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

char g_buff[32];

void setup() {
	g_command.mod = MOD_ROTATE;
	g_command.cmd = CMD_HEART;

	Serial.begin(9600);
	LedCube::init();

	Effect1.setspeed(150);
	Effect1.setmod(g_command.mod);
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
		g_command.buf = g_buff+3;
	}
}


void loop() {
	fetchdata();

	switch(g_command.cmd){
	case CMD_TEXT:
		Effect1.drawstring(g_command.buf,g_command.len);
		break;
	case CMD_HEART:
		Effect1.heartbeat();
		break;
	case CMD_SMILE:
		Effect1.smiley();
		break;
	case CMD_BUBBLES:
		Effect1.bubbles();
		break;
	case CMD_BOUNCE:
		Effect1.bounce();
		break;
	case CMD_INFINITE:
		Effect1.infinitesquare();
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
