#pragma once
#ifndef _ARBITER_H
#define _ARBITER_H
#include<systemc.h>
SC_MODULE(arbiter) {
	sc_in_clk clk;
	sc_out<bool> selector;
	void prc_arbiter() {
		int counter = 1;
		int i;
		cin >> i;
		for (;;) {
			if (counter % i == 0) {
				for (int m = 0;m < i;m++) {
					selector = 1;
					wait(1, SC_NS);
					selector = 0;
					wait(1, SC_NS);
					counter++;
				}
			}
			else {
				selector = 0;
				wait(1,SC_NS);
				selector = 1;
				wait(1, SC_NS);
				counter++;
			}
		}
	};
	SC_CTOR(arbiter) {
		SC_THREAD(prc_arbiter);
		sensitive << clk.pos();
	}
};
#endif