#pragma once
#ifndef _TESTBENCH_H
#define _TESTBENCH_H
#include"systemc.h"
SC_MODULE(driver)
{
	sc_out<char> d_char; // char generator

	void prc_drive() {
		char arr[27] = "abcdefghijklmnopqrstuvwxyz";
		int i;
		while (1) {
			for (i = 0;i<26;i++) {
				d_char.write(arr[i]);
				wait(2, SC_NS);
				for (int i = 0;i<100000000; i++);// dealy in order to see the output.
			}

		}
	};


	SC_CTOR(driver)
	{
		SC_THREAD(prc_drive);
	}
};

SC_MODULE(monitor)
{
	sc_in<char> m_char;
	sc_in_clk clk;
	void prc_monitor() {
		for (;;){
			wait(0.5, SC_NS);
			cout << "AT " << sc_simulation_time() << " UART output is : " << m_char << endl;
		}
	}
	;

	SC_CTOR(monitor)
	{
		SC_THREAD(prc_monitor);
		sensitive << clk.pos();
	}
};
#endif