#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vmul_sim.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vmul_sim *top = nullptr;

void stepAndDumpWave(uint64_t timeInc = 1) {
    top->eval();
    contextp->timeInc(timeInc);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vmul_sim;

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

    top->a = 9;
    top->b = 12;
    stepAndDumpWave();

    top->a = 0xFFFFFFFE;    // -2
    stepAndDumpWave();

    top->b = 0xFFFFFFFE;    // -2
    stepAndDumpWave();

    simExit();
    return 0;
}
