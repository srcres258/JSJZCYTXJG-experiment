#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vdivu_sim.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vdivu_sim *top = nullptr;

void stepAndDumpWave(uint64_t timeInc = 1) {
    top->clk = 0;
    top->eval();
    contextp->timeInc(timeInc);
    tfp->dump(contextp->time());

    top->clk = 1;
    top->eval();
    contextp->timeInc(timeInc);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vdivu_sim;

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

    top->a = 16;
    top->b = 4;
    top->clk = 0;
    top->start = 0;
    top->resetn = 0;
    stepAndDumpWave();

    top->start = 1;
    stepAndDumpWave();

    top->start = 0;
    for (i = 0; i < 20; i++) {
        stepAndDumpWave();
    }

    top->resetn = 1;
    stepAndDumpWave();

    top->resetn = 0;
    stepAndDumpWave();

    top->a = 18;
    top->b = 5;
    stepAndDumpWave();

    top->start = 1;
    stepAndDumpWave();

    top->start = 0;
    for (i = 0; i < 70; i++) {
        stepAndDumpWave();
    }

    simExit();
    return 0;
}
