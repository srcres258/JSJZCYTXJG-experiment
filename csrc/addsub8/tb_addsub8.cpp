#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vaddsub8.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vaddsub8 *top = nullptr;

void stepAndDumpWave(uint64_t timeInc = 1) {
    top->eval();
    contextp->timeInc(timeInc);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vaddsub8;

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

    top->a = 0x16;
    top->b = 0x12;
    top->sub = 0;
    stepAndDumpWave();

    top->sub = 1;
    stepAndDumpWave();

    top->a = 0x7F;
    top->b = 0x2;
    top->sub = 0;
    stepAndDumpWave();

    top->a = 0xFF;
    top->b = 0x2;
    top->sub = 0;
    stepAndDumpWave();

    top->a = 0x16;
    top->b = 0x17;
    top->sub = 1;
    stepAndDumpWave();

    top->a = 0xFE;
    top->b = 0xFF;
    top->sub = 1;
    stepAndDumpWave();

    simExit();
    return 0;
}
