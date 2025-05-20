#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vmux2x1verilog.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vmux2x1verilog *top = nullptr;

void stepAndDumpWave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vmux2x1verilog;

    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("dump.fst");
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

    top->a = 0;
    top->b = 1;
    top->s = 0;
    stepAndDumpWave();

    top->s = 1;
    stepAndDumpWave();

    simExit();
    return 0;
}
