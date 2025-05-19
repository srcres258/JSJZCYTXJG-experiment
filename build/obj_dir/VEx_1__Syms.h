// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VEX_1__SYMS_H_
#define VERILATED_VEX_1__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VEx_1.h"

// INCLUDE MODULE CLASSES
#include "VEx_1___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VEx_1__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VEx_1* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VEx_1___024root                TOP;

    // CONSTRUCTORS
    VEx_1__Syms(VerilatedContext* contextp, const char* namep, VEx_1* modelp);
    ~VEx_1__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
