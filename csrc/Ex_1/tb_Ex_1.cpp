#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VEx_1.h"

VerilatedContext *contextp = nullptr;
VerilatedVcdC *tfp = nullptr;

static VEx_1 *top = nullptr;

void stepAndDumpWave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedVcdC;
    top = new VEx_1;

    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("dump.vcd");
}

void simExit() {
    stepAndDumpWave();
    tfp->close();

    delete top;
    delete tfp;
    delete contextp;
}

int main() {
    simInit();


}
