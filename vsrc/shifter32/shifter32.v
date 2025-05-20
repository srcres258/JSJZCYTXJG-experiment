`timescale 1ns/1ps

// 32位桶形移位器
module shifter32 (
    input [31:0] d,
    input [4:0] s,      // 移动位数
    input [1:0] t,      // 1X -- 左移  00 -- 逻辑右移  01 -- 算术右移
    output reg [31:0] q
);
    always @(*) begin
        case (t)
            2'b00: begin
                // 逻辑右移
                q[31:0] = d >> s;
            end
            2'b01: begin
                // 算术右移
                q[31:0] = $signed(d) >>> s;
            end
            default: begin
                // 左移
                q[31:0] = d << s;
            end
        endcase
    end
endmodule
