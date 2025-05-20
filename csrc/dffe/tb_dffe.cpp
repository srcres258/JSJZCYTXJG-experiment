#include <verilated.h>
#include <nvboard.h>

#include "Vdffe.h"

static Vdffe *top = nullptr;

void nvboard_bind_all_pins(Vdffe *top);

static void singleCycle() {
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();
}

int main() {
    top = new Vdffe;

    nvboard_bind_all_pins(top);
    nvboard_init();

    while (true) {
        nvboard_update();
        singleCycle();
    }
    
    delete top;

    return 0;
}
