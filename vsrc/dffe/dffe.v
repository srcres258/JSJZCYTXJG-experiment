module dffe (
    input clk,
    input clrn, // 清零端
    input wen,  // 数据端
    input d,
    output reg q
);
    initial begin
        q = 0;
    end

    always @(posedge clk) begin
        if (clrn && ~wen) begin
            q = d;
        end
    end
endmodule
