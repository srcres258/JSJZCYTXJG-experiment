`timescale 1ns/1ps

module Ex_1 (
    input [23:0] sw,
    output [23:0] led
);
    assign led = sw;
endmodule
