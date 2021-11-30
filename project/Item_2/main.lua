require 'sum'

function main()
    result = sum(10, 20)
    print('Sum result: ' .. tostring(result))

    
    result = summation(10, 20, 30)
    print('Summation result: ' .. tostring(result))

    return 1
end

main()