#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vshifter32.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vshifter32 *top = nullptr;

void stepAndDumpWave(uint64_t timeInc = 1) {
    top->eval();
    contextp->timeInc(timeInc);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vshifter32;

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

    top->d = 0x00000000;
    top->s = 0b00000;
    top->t = 0b00;
    stepAndDumpWave();

    top->d = 0x87654321;
    stepAndDumpWave();

    top->s = 0b00100;
    stepAndDumpWave();

    top->t = 0b10;
    stepAndDumpWave(2);

    top->t = 0b00;
    stepAndDumpWave(2);

    top->t = 0b01;
    stepAndDumpWave(2);

    simExit();
    return 0;
}
