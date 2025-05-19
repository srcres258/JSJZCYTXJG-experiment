`timescale 1ns/1ps

module andgate #(
    parameter Port_Num = 2, // 指定缺省的输入是2个输入端口
    parameter WIDTH = 8     // 指定数据宽度参数，缺省值是8
) (
    input [(WIDTH-1):0] a,
    input [(WIDTH-1):0] b,
    input [(WIDTH-1):0] c,
    input [(WIDTH-1):0] d,
    input [(WIDTH-1):0] e,
    input [(WIDTH-1):0] f,
    input [(WIDTH-1):0] g,
    input [(WIDTH-1):0] h,
    output [(WIDTH-1):0] q
);
    assign q = a & b & c & d & e & f & g & h;
endmodule

module andgate_sim(
    input a,
    input b,
    input c,
    input d,
    input e,
    input f,
    input g,
    input h,
    output q
);
    andgate #(8, 1) u(.a(a), .b(b), .c(c), .d(d),
        .e(e), .f(f), .g(g), .h(h), .q(q));
endmodule
