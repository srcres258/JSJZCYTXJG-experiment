`timescale 1ns/1ps

module divu #(
    parameter WIDTH = 8
) (
    input [WIDTH-1:0] a,        // 被除数
    input [WIDTH/2-1:0] b,      // 除数
    input clk,                  // 时钟信号
    input start,                // 开始信号，该信号为高电平时启动除法操作
    input resetn,               // 复位信号，该信号为高电平时恢复除法器到初始状态
    output [WIDTH-1:0] q,       // 商
    output [WIDTH/2-1:0] r,     // 余数
    output reg busy             // 忙信号，当为高电平时表示正在进行除法运算，为低电平时表示空闲
);
    reg [WIDTH-1:0] q_reg;              // 商寄存器
    reg [WIDTH/2:0] r_reg;              // 余数寄存器（包含符号位）
    reg [$clog2(WIDTH+1)-1:0] count;    // 迭代计数器

    wire [WIDTH/2:0] b_ext;             // 除数扩展符号位

    wire [WIDTH/2:0] shifted_r;         // 移位后的余数

    assign b_ext = { 1'b0, b };
    assign shifted_r = (r_reg << 1) | {{WIDTH/2 {1'b0}}, q_reg[WIDTH-1]};

    reg [WIDTH/2:0] new_r;              // 新余数
    reg [WIDTH-1:0] updated_q;          // 新商

    always @(*) begin
        new_r = r_reg[WIDTH/2] ? shifted_r + b_ext : shifted_r - b_ext;
    end

    always @(*) begin
        updated_q = q_reg << 1;
        updated_q[0] = ~new_r[WIDTH/2];
    end

    always @(posedge clk or negedge resetn) begin
        if (resetn) begin
            busy <= 0;
            q_reg <= 0;
            r_reg <= 0;
            count <= 0;
        end
        else begin
            if (busy) begin
                if (count < WIDTH) begin
                    r_reg <= new_r;
                    q_reg <= updated_q;
                    count <= count + 1;
                end
                else begin
                    // 调整最终余数
                    if (r_reg[WIDTH/2]) begin
                        r_reg <= r_reg + b_ext;
                    end
                    busy <= 0;
                end
            end
            else begin
                if (start) begin
                    busy <= 1;
                    q_reg <= a;
                    r_reg <= 0;
                    count <= 0;
                end
            end
        end
    end

    // 输出结果
    assign q = q_reg;
    assign r = r_reg[WIDTH/2-1:0];
endmodule

module divu_sim (
    input [31:0] a,
    input [15:0] b,
    input clk,
    input start,
    input resetn,
    output [31:0] q,
    output [15:0] r,
    output busy
);
    divu #(.WIDTH(32)) u(a, b, clk, start, resetn, q, r, busy);
endmodule
