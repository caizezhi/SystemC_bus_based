#pragma once
#ifndef _UART_H
#define _UART_H
#include"systemc.h"
SC_MODULE(UART)
{
	sc_in<char> char_in;
	sc_out<char> char_out;

	void prc_UART() {
		char_out = char_in;
	};

	SC_CTOR(UART)
	{
		SC_METHOD(prc_UART);
		sensitive << char_in;
	}

};
#endif