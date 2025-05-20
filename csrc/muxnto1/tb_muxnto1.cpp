#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vmuxnto1_sim.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vmuxnto1_sim *top = nullptr;

void stepAndDumpWave() {
    top->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vmuxnto1_sim;

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

    top->a0 = 0b00000000;
    top->a1 = 0b00010001;
    top->a2 = 0b00100010;
    top->a3 = 0b00110011;
    top->a4 = 0b01000100;
    top->a5 = 0b01010101;
    top->a6 = 0b01100110;
    top->a7 = 0b01110111;
    top->s = 0b000;
    stepAndDumpWave();

    top->s = 0b001;
    stepAndDumpWave();

    top->s = 0b010;
    stepAndDumpWave();

    top->s = 0b011;
    stepAndDumpWave();

    top->s = 0b100;
    stepAndDumpWave();

    top->s = 0b101;
    stepAndDumpWave();

    top->s = 0b110;
    stepAndDumpWave();

    top->s = 0b111;
    stepAndDumpWave();

    simExit();
    return 0;
}
