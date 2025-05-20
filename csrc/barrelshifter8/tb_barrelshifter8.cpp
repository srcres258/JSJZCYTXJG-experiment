#include <verilated.h>
#include <verilated_fst_c.h>

#include "Vbarrelshifter8.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Vbarrelshifter8 *top = nullptr;

void stepAndDumpWave(uint64_t timeInc = 1) {
    top->eval();
    contextp->timeInc(timeInc);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Vbarrelshifter8;

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

    top->d = 0b00000000;
    top->s = 0b000;
    top->t = 0b00;
    stepAndDumpWave();

    top->d = 0x87;      // 原始数据
    stepAndDumpWave();

    top->s = 0b100;     // 移动4位
    stepAndDumpWave();

    top->t = 0b10;      // 左移
    stepAndDumpWave(2);

    top->t = 0b00;      // 逻辑右移
    stepAndDumpWave(2);

    top->t = 0b01;      // 算术右移
    stepAndDumpWave(2);

    simExit();
    return 0;
}
