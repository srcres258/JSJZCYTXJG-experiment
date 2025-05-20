`timescale 1ns/1ps

// 有符号数乘法器
module mul #(
    parameter WIDTH = 8
) (
    input [WIDTH-1:0] a,        // 被乘数（有符号数补码）
    input [WIDTH-1:0] b,        // 乘数（有符号数补码）
    output reg [WIDTH*2-1:0] c  // 乘积（有符号数补码，若乘积结果位数比c的位数小则符号扩展到与c的位数相同）
);
    always @(*) begin
        c = $signed(a) * $signed(b);
    end
endmodule

module mul_sim (
    input [31:0] a,
    input [31:0] b,
    output [63:0] c
);
    mul #(.WIDTH(32)) u(a, b, c);
endmodule
