#pragma once
#ifndef _FILTER_H
#define _FILTER_H
#include"systemc.h"
SC_MODULE(filter)
{
	sc_in<char> char_in;
	sc_out<char> char_out;

	void prc_filter() {
		char_out = '#';
		if (char_in == 's' || char_in == 'y' || char_in == 't' || char_in == 'e' || char_in == 'm' || char_in == 'c')
			char_out = char_in;
	};

	SC_CTOR(filter)
	{
		SC_METHOD(prc_filter);
		sensitive << char_in;
	}

};
#endif