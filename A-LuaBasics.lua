print("ahoj jak se mas?")

--Variables

local hi = "CC jak se mas?"
local number = 2

print(hi)
print (number)

--Functions
local function ahojky ()

    print("Cauky ty kamarade")
    
end

ahojky()



--Math
local a = 1
local b = 2
local answer = a + b
print(answer)

print(1+2)

local x = 1
local y = 2

print(x+y)


--Text inmputs
print("What is your name? \n")
--local name = io.read();
--print("Ahoj "..name.."!")



--If statements
local first = 6
local second = 9

if first == second then
    print("Correct!")
else
    print("Bohuzel to mas spatne kamo")
end


--Kalkulacka dane
print("--------------------------------")
print("KALKULACKA")
print("Zadejte hodnotu zbozi")
local price = io.read();
print ("Zadejte kurz dane (%)")
local dan = io.read();

local finalPrice = price + (price/100)*dan
print("Vase finalni cena produktu je "..finalPrice)