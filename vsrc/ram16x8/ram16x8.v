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
