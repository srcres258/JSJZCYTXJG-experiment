module mux2x1verilog (
    input a,
    input b,
    input s,
    output c
);
    wire a1, b1, sel;

    assign sel = ~s;
    assign a1 = a & sel;
    assign b1 = s & b;
    assign c = a1 | b1;
endmodule
