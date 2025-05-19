// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VEx_1__pch.h"

//============================================================
// Constructors

VEx_1::VEx_1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VEx_1__Syms(contextp(), _vcname__, this)}
    , sw{vlSymsp->TOP.sw}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VEx_1::VEx_1(const char* _vcname__)
    : VEx_1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VEx_1::~VEx_1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VEx_1___024root___eval_debug_assertions(VEx_1___024root* vlSelf);
#endif  // VL_DEBUG
void VEx_1___024root___eval_static(VEx_1___024root* vlSelf);
void VEx_1___024root___eval_initial(VEx_1___024root* vlSelf);
void VEx_1___024root___eval_settle(VEx_1___024root* vlSelf);
void VEx_1___024root___eval(VEx_1___024root* vlSelf);

void VEx_1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VEx_1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VEx_1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VEx_1___024root___eval_static(&(vlSymsp->TOP));
        VEx_1___024root___eval_initial(&(vlSymsp->TOP));
        VEx_1___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VEx_1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VEx_1::eventsPending() { return false; }

uint64_t VEx_1::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VEx_1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VEx_1___024root___eval_final(VEx_1___024root* vlSelf);

VL_ATTR_COLD void VEx_1::final() {
    VEx_1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VEx_1::hierName() const { return vlSymsp->name(); }
const char* VEx_1::modelName() const { return "VEx_1"; }
unsigned VEx_1::threads() const { return 1; }
void VEx_1::prepareClone() const { contextp()->prepareClone(); }
void VEx_1::atClone() const {
    contextp()->threadPoolpOnClone();
}
