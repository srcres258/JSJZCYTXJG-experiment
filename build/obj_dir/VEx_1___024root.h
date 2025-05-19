// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VEx_1.h for the primary calling header

#ifndef VERILATED_VEX_1___024ROOT_H_
#define VERILATED_VEX_1___024ROOT_H_  // guard

#include "verilated.h"


class VEx_1__Syms;

class alignas(VL_CACHE_LINE_BYTES) VEx_1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    VL_IN(sw,23,0);
    VL_OUT(led,23,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VEx_1__Syms* const vlSymsp;

    // CONSTRUCTORS
    VEx_1___024root(VEx_1__Syms* symsp, const char* v__name);
    ~VEx_1___024root();
    VL_UNCOPYABLE(VEx_1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
