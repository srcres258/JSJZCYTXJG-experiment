#include <verilated.h>
#include <verilated_fst_c.h>
#include "VEx_1.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static VEx_1 *top = nullptr;

void stepAndDumpWave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new VEx_1;

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
    uint32_t sw;

    simInit();

    for (sw = 0; sw < 1 << 24 - 1; sw++) {
        top->sw = sw;
        stepAndDumpWave();
    }

    simExit();
    return 0;
}
