#pragma once
#ifndef _CHANGE_CASE_H
#define _CHANGE_CASE_H
#include"systemc.h"
SC_MODULE(change_case)
{
	sc_in<char> char_in;
	sc_out<char> char_out;

	void prc_change_case() {
		char_out = (char)toupper(char_in);
	};

	SC_CTOR(change_case)
	{
		SC_METHOD(prc_change_case);
		sensitive << char_in;
	}

};
#endif