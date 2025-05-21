#include <verilated.h>
#include <verilated_fst_c.h>

#include "Valu8_verilog.h"

VerilatedContext *contextp = nullptr;
VerilatedFstC *tfp = nullptr;

static Valu8_verilog *top = nullptr;

void stepAndDumpWave(uint64_t timeInc = 1) {
    top->eval();
    contextp->timeInc(timeInc);
    tfp->dump(contextp->time());
}

void simInit() {
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC;
    top = new Valu8_verilog;

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
    top->op = 0b0000;   // 加法
    stepAndDumpWave();

    top->op = 0b0001;   // 减法
    stepAndDumpWave();

    top->a = 0x7F;
    top->b = 0x2;
    top->op = 0b0000;
    stepAndDumpWave();

    top->a = 0xFF;
    top->b = 0x2;
    top->op = 0b0000;
    stepAndDumpWave();

    top->a = 0x16;
    top->b = 0x17;
    top->op = 0b0001;
    stepAndDumpWave();

    top->a = 0xF0;
    top->b = 0x0F;
    top->op = 0b0100;   // 与
    stepAndDumpWave();

    top->a = 0xF0;
    top->b = 0x0F;
    top->op = 0b0101;   // 或
    stepAndDumpWave();

    top->a = 0xF0;
    top->b = 0x0F;
    top->op = 0b0110;   // 非
    stepAndDumpWave();

    top->a = 0xFF;
    top->b = 0xFF;
    top->op = 0b0111;   // 异或
    stepAndDumpWave();

    top->a = 0xFF;
    top->b = 0x03;
    top->op = 0b1000;   // 逻辑右移
    stepAndDumpWave();

    top->a = 0xFF;
    top->b = 0x03;
    top->op = 0b1001;   // 算术右移
    stepAndDumpWave();

    top->a = 0xFF;
    top->b = 0x03;
    top->op = 0b1010;   // 左移
    stepAndDumpWave();

    simExit();
    return 0;
}
