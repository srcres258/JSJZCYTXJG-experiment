#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vandgate_sim.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vandgate_sim *top = nullptr;

void stepAndDumpWave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vandgate_sim;

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
    top->b = 0;
    top->c = 1;
    top->d = 1;
    top->e = 1;
    top->f = 1;
    top->g = 1;
    top->h = 1;
    stepAndDumpWave();

    top->a = 1;
    stepAndDumpWave();
    
    top->a = 0;
    top->b = 1;
    stepAndDumpWave();

    top->a = 1;
    stepAndDumpWave();

    simExit();
    return 0;
}
