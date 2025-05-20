#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vmux4to1.h"

constexpr int TOTAL_STEPS = 1000;

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vmux4to1 *top = nullptr;

void stepAndDumpWave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vmux4to1;

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
    int i;

    simInit();

    top->a0 = 0b0001;
    top->a1 = 0b0010;
    top->a2 = 0b0011;
    top->a3 = 0b0100;
    top->s = 0b00;
    stepAndDumpWave();

    for (i = 0; i < TOTAL_STEPS; i++) {
        top->s = (top->s + 1) % (1 << 2);
        stepAndDumpWave();
    }

    simExit();
    return 0;
}
