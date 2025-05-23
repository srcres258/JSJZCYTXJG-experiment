/* verilator lint_off WIDTHEXPAND */

`timescale 1ns/1ps

// 无符号数乘法器（IP核）
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

// 8位无符号数乘法器
module xmulux8 (
    input [7:0] in,
    input a_apply,
    input b_apply,
    output reg [15:0] out
);
    reg [7:0] a, b;

    mulu #(.WIDTH(8)) u(a, b, out);

    initial begin
        a = 0;
        b = 0;
    end

    always @(posedge a_apply) begin
        a = in;
    end

    always @(posedge b_apply) begin
        b = in;
    end
endmodule
