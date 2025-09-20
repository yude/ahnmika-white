math.randomseed(os.time())

local count = 0

while true do
    local ok, err = pcall(function()
        local colors = math.random(100, 1000)
        print(string.format("白って%d色あんねん", colors))
        count = count + 1
    end)

    if not ok then
        print(string.format("\n%d 人のアンミカ", count))
        break
    end
end
