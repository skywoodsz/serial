#include <iostream>
#include "pc2mcu.h"
using namespace std;
int main()
{
	myserial::myserial serial;
	if (!serial.init())
	{
		cout << "error! the serial's init is bad " << endl;
		return -1;
	}
	serial.send_data(1000, 2000);
	return 0;
}