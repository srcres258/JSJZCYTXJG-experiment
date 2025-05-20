/* verilator lint_off WIDTHEXPAND */

`timescale 1ns/1ps

// 加减法器IP核
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
    wire [WIDTH:0] sum_extended;
    wire [WIDTH-1:0] b_mux;
    wire cin;

    assign b_mux = sub ? ~b : b;
    assign cin = sub;

    // 计算总和及扩展进位
    assign sum_extended = a + b_mux + cin;

    // 计算结果
    assign sum = sum_extended[WIDTH-1:0];

    // 进位标志：减法时取反进位
    assign cf = sub ? ~sum_extended[WIDTH] : sum_extended[WIDTH];

    // 溢出标志：根据加减法选择不同条件
    assign ovf = sub ? (a[WIDTH-1] != b[WIDTH-1] && sum[WIDTH-1] != a[WIDTH-1]) :
        (a[WIDTH-1] == b[WIDTH-1] && sum[WIDTH-1] != a[WIDTH-1]);

    // 符号标志：结果的最高位
    assign sf = sum[WIDTH-1];

    // 零标志：结果是否为0
    assign zf = sum == 0;
endmodule

// 8位加减法器
module addsub8 (
    input [7:0] a,
    input [7:0] b,
    input sub,
    output [7:0] sum,
    output cf,
    output ovf,
    output sf,
    output zf
);
    addsub #(.WIDTH(8)) addsub_inst(a, b, sub, sum, cf, ovf, sf, zf);
endmodule
