`timescale 1ns/1ps

// 8位运算逻辑单元
module alu8_verilog (
    input signed [7:0] a,
    input signed [7:0] b,
    input [3:0] op,
    output reg signed [7:0] res,
    output reg cf,              // 进位标志
    output reg ovf,             // 溢出标志
    output sf,                  // 符号标志
    output zf                   // 零标志
);
    wire signed [7:0] minus_b;
    wire signed [8:0] sum_ext, sum_minus_ext;

    assign sum_ext = { a[7], a } + { b[7], b };
    assign sum_minus_ext = { a[7], a } + { minus_b[7], minus_b };
    assign minus_b = ~b + 1;
    assign sf = res[7];
    assign zf = res == 0;

    always @(a or b or op) begin
        casez (op)
            4'b00?0: begin  // 加法
                cf = sum_ext[8];
                res = sum_ext[7:0];
                ovf = (a[7] & b[7] & ~res[7]) | (~a[7] & ~b[7] & res[7]);
            end
            4'b00?1: begin  // 减法
                cf = sum_minus_ext[8];
                res = sum_minus_ext[7:0];
                if (&b) begin
                    ovf = 1;
                end
                else begin
                    ovf = (a[7] & minus_b[7] & ~res[7]) | (~a[7] & ~minus_b[7] & res[7]);
                end
            end
            4'b0100: begin  // 与
                res = a & b;
                cf = 0;
                ovf = 0;
            end
            4'b0101: begin  // 或
                res = a | b;
                cf = 0;
                ovf = 0;
            end
            4'b0110: begin  // 非
                res = ~a;
                cf = 0;
                ovf = 0;
            end
            4'b0111: begin  // 异或
                res = a ^ b;
                cf = 0;
                ovf = 0;
            end
            4'b1?00: begin  // 逻辑右移
                res = a >> b[2:0];
                cf = 0;
                ovf = 0;
            end
            4'b1?01: begin  // 算术右移
                res = a >>> b[2:0];
                cf = 0;
                ovf = 0;
            end
            4'b1?1?: begin  // 逻辑左移
                res = a << b[2:0];
                cf = 0;
                ovf = 0;
            end
            default: begin
                res = 0;
                cf = 0;
                ovf = 0;
            end
        endcase
    end
endmodule
