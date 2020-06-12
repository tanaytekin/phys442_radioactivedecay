import math

mean = 0.01193
mean_s = 0.00003

half_life = math.log(2)/mean
half_life_s = math.log(2)/(mean**2)*mean_s

print("half_life : " + str(half_life))
print("half_life_sigma : " + str(half_life_s))
