// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEx_1.h for the primary calling header

#include "VEx_1__pch.h"
#include "VEx_1__Syms.h"
#include "VEx_1___024root.h"

void VEx_1___024root___ctor_var_reset(VEx_1___024root* vlSelf);

VEx_1___024root::VEx_1___024root(VEx_1__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VEx_1___024root___ctor_var_reset(this);
}

void VEx_1___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VEx_1___024root::~VEx_1___024root() {
}
