`timescale 1ns/1ps

// 16x2 RAM
module ram16x2 (
    input clk,
    input we,
    input en,
    input [3:0] addr,
    input [1:0] datain,
    output reg [1:0] dataout
);
    reg [1:0] data [15:0];

    integer i;

    initial begin
        for (i = 0; i < 16; i = i + 1) begin
            data[i] = 2'b00;
        end
        dataout = 2'b00;
    end

    always @(posedge clk) begin
        if (en) begin
            if (we) begin
                data[addr] = datain;
            end
            dataout = data[addr];
        end
    end
endmodule

// 16x8 RAM，由4个16x2 RAM组成
module ram16x8 (
    input clk,
    input we,
    input en,
    input [3:0] addr,
    input [7:0] datain,
    output [7:0] dataout
);
    ram16x2 r0(
        .clk(clk),
        .we(we),
        .en(en),
        .addr(addr),
        .datain(datain[1:0]),
        .dataout(dataout[1:0])
    );

    ram16x2 r1(
        .clk(clk),
        .we(we),
        .en(en),
        .addr(addr),
        .datain(datain[3:2]),
        .dataout(dataout[3:2])
    );
    
    ram16x2 r2(
        .clk(clk),
        .we(we),
        .en(en),
        .addr(addr),
        .datain(datain[5:4]),
        .dataout(dataout[5:4])
    );
    
    ram16x2 r3(
        .clk(clk),
        .we(we),
        .en(en),
        .addr(addr),
        .datain(datain[7:6]),
        .dataout(dataout[7:6])
    );
endmodule

// 2-4译码器
module decode24 (
    input [1:0] x,
    output reg [3:0] y
);
    always @(x) begin
        case (x)
            2'd0: begin
                y <= 4'b0001;
            end
            2'd1: begin
                y <= 4'b0010;
            end
            2'd2: begin
                y <= 4'b0100;
            end
            2'd3: begin
                y <= 4'b1000;
            end
            default: begin
                y <= 4'b0000;
            end
        endcase
    end
endmodule

// 64x8 RAM，由4个16x8 RAM使用字扩展技术组成
module ram64x8 (
    input clk,              // 时钟信号
    input en,               // 使能信号
    input we,               // 写使能信号
    input [5:0] addr,       // 地址信号
    input [7:0] datain,     // 数据输入信号
    output [7:0] dataout    // 数据输出信号
);
    wire [3:0] sel, en_sel;
    wire [7:0] dataouts [3:0];

    decode24 decode(
        .x(addr[5:4]),
        .y(sel)
    );

    assign en_sel = {4{en}} & sel;

    ram16x8 ram0(
        .clk(clk),
        .en(en_sel[0]),
        .we(we),
        .addr(addr[3:0]),
        .datain(datain),
        .dataout(dataouts[0])
    );

    ram16x8 ram1(
        .clk(clk),
        .en(en_sel[1]),
        .we(we),
        .addr(addr[3:0]),
        .datain(datain),
        .dataout(dataouts[1])
    );

    ram16x8 ram2(
        .clk(clk),
        .en(en_sel[2]),
        .we(we),
        .addr(addr[3:0]),
        .datain(datain),
        .dataout(dataouts[2])
    );

    ram16x8 ram3(
        .clk(clk),
        .en(en_sel[3]),
        .we(we),
        .addr(addr[3:0]),
        .datain(datain),
        .dataout(dataouts[3])
    );

    assign dataout = dataouts[0] & {8{en_sel[0]}} |
        dataouts[1] & {8{en_sel[1]}} |
        dataouts[2] & {8{en_sel[2]}} |
        dataouts[3] & {8{en_sel[3]}};
endmodule
