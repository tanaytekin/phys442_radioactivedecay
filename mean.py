import csv,math
slopes = []
slopes_err = []

with open('data/slopes.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    for row in reader:
        slopes.append(float(row[0]))
        slopes_err.append(float(row[1]))


print(slopes)
print(slopes_err)

m_u = 0
m_d = 0
me = 0
for i in range (0,12):
    me = me + slopes[i]
    m_u = m_u + slopes[i]/(slopes_err[i]*slopes_err[i])
    m_d = m_d + 1/(slopes_err[i]*slopes_err[i])

mean = m_u/m_d
mean_err = math.sqrt(1/m_d)

print("Slope : " + str(mean))
print("Slope_sigma : " + str(mean_err))

