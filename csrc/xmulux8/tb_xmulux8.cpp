#include <verilated.h>
#include <nvboard.h>

#include "Vxmulux8.h"

static Vxmulux8 *top = nullptr;

void nvboard_bind_all_pins(Vxmulux8 *top);

int main() {
    top = new Vxmulux8;

    nvboard_bind_all_pins(top);
    nvboard_init();

    while (true) {
        nvboard_update();
        top->eval();
    }

    delete top;

    return 0;
}
