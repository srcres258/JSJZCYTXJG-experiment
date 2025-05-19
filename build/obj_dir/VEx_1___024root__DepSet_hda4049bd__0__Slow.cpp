// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEx_1.h for the primary calling header

#include "VEx_1__pch.h"
#include "VEx_1___024root.h"

VL_ATTR_COLD void VEx_1___024root___eval_static(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_static\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VEx_1___024root___eval_initial(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_initial\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VEx_1___024root___eval_final(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_final\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__stl(VEx_1___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VEx_1___024root___eval_phase__stl(VEx_1___024root* vlSelf);

VL_ATTR_COLD void VEx_1___024root___eval_settle(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_settle\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VEx_1___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/srcres/Coding/Learn/JSJZCYTXJG-experiment/vsrc/Ex_1/Ex_1.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VEx_1___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__stl(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___dump_triggers__stl\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VEx_1___024root___ico_sequent__TOP__0(VEx_1___024root* vlSelf);

VL_ATTR_COLD void VEx_1___024root___eval_stl(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_stl\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VEx_1___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VEx_1___024root___eval_triggers__stl(VEx_1___024root* vlSelf);

VL_ATTR_COLD bool VEx_1___024root___eval_phase__stl(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_phase__stl\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VEx_1___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VEx_1___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__ico(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___dump_triggers__ico\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__act(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___dump_triggers__act\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__nba(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___dump_triggers__nba\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VEx_1___024root___ctor_var_reset(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___ctor_var_reset\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->sw = VL_RAND_RESET_I(24);
    vlSelf->led = VL_RAND_RESET_I(24);
}
