// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEx_1.h for the primary calling header

#include "VEx_1__pch.h"
#include "VEx_1___024root.h"

void VEx_1___024root___ico_sequent__TOP__0(VEx_1___024root* vlSelf);

void VEx_1___024root___eval_ico(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_ico\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VEx_1___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VEx_1___024root___ico_sequent__TOP__0(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___ico_sequent__TOP__0\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.led = vlSelfRef.sw;
}

void VEx_1___024root___eval_triggers__ico(VEx_1___024root* vlSelf);

bool VEx_1___024root___eval_phase__ico(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_phase__ico\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VEx_1___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VEx_1___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VEx_1___024root___eval_act(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_act\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VEx_1___024root___eval_nba(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_nba\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VEx_1___024root___eval_triggers__act(VEx_1___024root* vlSelf);

bool VEx_1___024root___eval_phase__act(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_phase__act\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VEx_1___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VEx_1___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VEx_1___024root___eval_phase__nba(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_phase__nba\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VEx_1___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__ico(VEx_1___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__nba(VEx_1___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VEx_1___024root___dump_triggers__act(VEx_1___024root* vlSelf);
#endif  // VL_DEBUG

void VEx_1___024root___eval(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VEx_1___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/srcres/Coding/Learn/JSJZCYTXJG-experiment/vsrc/Ex_1/Ex_1.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VEx_1___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VEx_1___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/srcres/Coding/Learn/JSJZCYTXJG-experiment/vsrc/Ex_1/Ex_1.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VEx_1___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/srcres/Coding/Learn/JSJZCYTXJG-experiment/vsrc/Ex_1/Ex_1.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VEx_1___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VEx_1___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VEx_1___024root___eval_debug_assertions(VEx_1___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEx_1___024root___eval_debug_assertions\n"); );
    VEx_1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.sw & 0xff000000U)))) {
        Verilated::overWidthError("sw");}
}
#endif  // VL_DEBUG
