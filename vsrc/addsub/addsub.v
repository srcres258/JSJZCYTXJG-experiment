`timescale 1ns/1ps

module addsub #(
    parameter WIDTH = 8     // 指定数据宽度参数，缺省值是8
) (
    input [WIDTH-1:0] a,    // 被操作数（有符号数原码，最高位为符号位），位宽由参数WIDTH决定
    input [WIDTH-1:0] b,    // 操作数（有符号数原码，最高位为符号位），位宽由参数WIDTH决定
    input sub,              // 当为1时进行减法操作，否则进行加法操作
    output [WIDTH-1:0] sum, // 结果
    output cf,              // 进位标志
    output ovf,             // 溢出标志
    output sf,              // 符号标志
    output zf               // 零标志
);
    // 原码转补码的函数
    function [WIDTH-1:0] orig_to_comp;
        input [WIDTH-1:0] orig;
        reg [WIDTH-2:0] mag;
        begin
            mag = orig[WIDTH-2:0];
            if (mag == 0) begin
                orig_to_comp = 0;
            end
            else if (orig[WIDTH-1]) begin
                orig_to_comp = { 1'b1, (~mag) + 1'b1 };
            end
            else begin
                orig_to_comp = orig;
            end
        end
    endfunction

    // 补码转原码的函数
    function [WIDTH-1:0] comp_to_orig;
        input [WIDTH-1:0] comp;
        reg [WIDTH-2:0] mag;
        begin
            if (comp == 0) begin
                comp_to_orig = 0;
            end
            else if (comp[WIDTH-1]) begin
                mag = comp[WIDTH-2:0];
                mag = ~mag + 1'b1;
                comp_to_orig = { 1'b1, mag };
            end
            else begin
                comp_to_orig = comp;
            end
        end
    endfunction

    wire [WIDTH-1:0] a_comp, b_comp;
    wire [WIDTH-1:0] b_comp_sub;
    wire [WIDTH:0] temp_sum;
    wire [WIDTH-1:0] sum_comp, sum_orig;

    assign a_comp = orig_to_comp(a);
    assign b_comp = orig_to_comp(b);
    assign b_comp_sub = sub ? ~b_comp + 1'b1 : b_comp;
    assign temp_sum = a_comp + b_comp_sub;
    assign sum_comp = temp_sum[WIDTH-1:0];
    assign sum_orig = comp_to_orig(sum_comp);

    assign sum = sum_orig;
    assign cf = sub ? ~temp_sum[WIDTH] : temp_sum[WIDTH];
    assign ovf = a_comp[WIDTH-1] == b_comp_sub[WIDTH-1] &&
        sum_comp[WIDTH-1] != a_comp[WIDTH-1];
    assign sf = sum_orig[WIDTH-1];
    assign zf = sum_orig == 0;
endmodule

module addsub_sim (
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum,
    output cf,
    output ovf,
    output sf,
    output zf
);
    addsub #(32) U(a, b, sub, sum, cf, ovf, sf, zf);
endmodule
