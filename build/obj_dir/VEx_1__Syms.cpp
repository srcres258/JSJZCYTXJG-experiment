// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VEx_1__pch.h"
#include "VEx_1.h"
#include "VEx_1___024root.h"

// FUNCTIONS
VEx_1__Syms::~VEx_1__Syms()
{
}

VEx_1__Syms::VEx_1__Syms(VerilatedContext* contextp, const char* namep, VEx_1* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(25);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
