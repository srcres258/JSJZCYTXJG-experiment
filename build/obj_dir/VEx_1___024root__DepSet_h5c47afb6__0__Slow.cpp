// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEx_1.h for the primary calling header

#include "VEx_1__pch.h"
#include "VEx_1__Syms.h"
#include "VEx_1___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__stl(VEx_1___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VEx_1___024root___eval_triggers__stl(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_triggers__stl\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VEx_1___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
