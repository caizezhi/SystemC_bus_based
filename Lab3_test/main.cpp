#include"change_case.h"
#include"UART.h"
#include"testbench.h"
#include"m_bus.h"
#include"filter.h"
#include"arbiter.h"
int sc_main(int argc, char* argv[]) {
	sc_signal<char> i1, i2, i3;
	sc_signal<char>d1, o1, o2, o3, o4;
	sc_signal<bool>sr;
	sc_signal<bool>clk;
	change_case cc("cc");
	filter ft("ft");
	m_bus mb("mb");
	driver dr("dr");
	monitor mon("mon");
	UART ur("ur");
	arbiter ar("ar");
	dr.d_char(d1);
	cc.char_in(d1);
	cc.char_out(o1);
	ft.char_in(d1);
	ft.char_out(o2);
	ar.selector(sr);
	ar.clk(clk);
	mb.char_in1(o1);
	mb.char_in2(o2);
	mb.char_out(o3);
	mb.selector(sr);
	ur.char_in(o3);
	ur.char_out(o4);
	mon.clk(clk);
	mon.m_char(o4);
	sc_start();
	return 0;
}