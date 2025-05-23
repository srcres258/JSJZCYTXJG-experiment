#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vram64x8.h"

constexpr uint64_t CLK_CYCLES = 10;

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vram64x8 *top = nullptr;

void stepAndDumpWave(uint64_t clkCycles = 1) {
    uint64_t i;

    for (i = 0; i < clkCycles; i++) {
        top->clk = 0;
        top->eval();
        contextp->timeInc(1);
        tfp->dump(contextp->time());

        top->clk = 1;
        top->eval();
        contextp->timeInc(1);
        tfp->dump(contextp->time());
    }
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vram64x8;

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

    top->clk = 0;
    top->en = 0;
    top->we = 0;
    top->addr = 0;
    top->datain = 0;
    stepAndDumpWave(CLK_CYCLES);

    top->we = 1;
    top->en = 1;
    top->addr = 10;
    top->datain = 0b10101010;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 20;
    top->datain = 0b01010101;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 40;
    top->datain = 0b10100101;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 60;
    top->datain = 0b01011010;
    stepAndDumpWave(CLK_CYCLES);

    top->we = 0;
    top->en = 0;
    top->addr = 10;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 20;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 40;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 60;
    stepAndDumpWave(CLK_CYCLES);

    top->en = 1;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 10;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 20;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 40;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 60;
    stepAndDumpWave(CLK_CYCLES);

    top->addr = 0;
    stepAndDumpWave(CLK_CYCLES);

    top->en = 0;
    top->addr = 20;
    stepAndDumpWave(CLK_CYCLES);

    simExit();
    return 0;
}
