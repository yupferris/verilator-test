#include "../obj_dir/VConvert.h"

#include <iostream>
using namespace std;

int main()
{
    VConvert top;

    // Reset
    top.rst = top.clk = 0;
    top.eval();
    top.rst = 1;

    for (int time = 0; time < 10 && !Verilated::gotFinish(); time++)
    {
        // Rising edge
        top.clk = 1;
        top.eval();

        // Falling edge
        top.clk = 0;
        top.eval();

        cout << "out: " << top.out << endl;
    }
    top.final();

    return 0;
}
