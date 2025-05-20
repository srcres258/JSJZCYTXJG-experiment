/* verilator lint_off WIDTHEXPAND */

`timescale 1ns/1ps

// 无符号数乘法器
module mulu #(
    parameter WIDTH = 8
) (
    input [WIDTH-1:0] a,        // 被乘数
    input [WIDTH-1:0] b,        // 乘数
    output reg [WIDTH*2-1:0] c  // 乘积
);
    integer i;

    always @(a or b) begin
        c = 0;
        for (i = 0; i < WIDTH; i = i + 1) begin
            if (b[i]) begin
                c = c + (a << i);
            end
        end
    end
endmodule

module mulu_sim (
    input [31:0] a,
    input [31:0] b,
    output [63:0] c
);
    mulu #(.WIDTH(32)) u(a, b, c);
endmodule
