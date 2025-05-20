/* verilator lint_off WIDTHEXPAND */

`timescale 1ns/1ps

module muxnto1 #(
    parameter Sel_Width = 4,    // 选择端s的位宽
    parameter WIDTH = 8         // 数据位宽
) (
    input [WIDTH-1:0] a0,
    input [WIDTH-1:0] a1,
    input [WIDTH-1:0] a2,
    input [WIDTH-1:0] a3,
    input [WIDTH-1:0] a4,
    input [WIDTH-1:0] a5,
    input [WIDTH-1:0] a6,
    input [WIDTH-1:0] a7,
    input [WIDTH-1:0] a8,
    input [WIDTH-1:0] a9,
    input [WIDTH-1:0] a10,
    input [WIDTH-1:0] a11,
    input [WIDTH-1:0] a12,
    input [WIDTH-1:0] a13,
    input [WIDTH-1:0] a14,
    input [WIDTH-1:0] a15,
    input [Sel_Width-1:0] s,
    output reg [WIDTH-1:0] q
);
    always @(*) begin
        case (s)
            0: q = a0;
            1: q = a1;
            2: q = a2;
            3: q = a3;
            4: q = a4;
            5: q = a5;
            6: q = a6;
            7: q = a7;
            8: q = a8;
            9: q = a9;
            10: q = a10;
            11: q = a11;
            12: q = a12;
            13: q = a13;
            14: q = a14;
            15: q = a15;
            default: q = 0;
        endcase
    end
endmodule

module muxnto1_sim (
    input [7:0] a0,
    input [7:0] a1,
    input [7:0] a2,
    input [7:0] a3,
    input [7:0] a4,
    input [7:0] a5,
    input [7:0] a6,
    input [7:0] a7,
    input [2:0] s,
    output [7:0] q
);
    muxnto1 #(3, 8) u(.a0(a0), .a1(a1), .a2(a2), .a3(a3),
        .a4(a4), .a5(a5), .a6(a6), .a7(a7), .a8(0), .a9(0),
        .a10(0), .a11(0), .a12(0), .a13(0), .a14(0), .a15(0),
        .s(s), .q(q));
endmodule
