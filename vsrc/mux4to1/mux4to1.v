module mux4to1 (
    input [3:0] a0,
    input [3:0] a1,
    input [3:0] a2,
    input [3:0] a3,
    input [1:0] s,
    output reg [3:0] y
);
    always @(a0 or a1 or a2 or a3 or s) begin
        case (s)
            2'b00: y = a0;
            2'b01: y = a1;
            2'b10: y = a2;
            2'b11: y = a3;
            default: y = 4'd0;
        endcase
    end
endmodule
