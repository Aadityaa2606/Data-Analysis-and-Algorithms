import random

n = int(input("Enter the number of elements: "))
fp = open("random_" + str(n) + ".txt", "w")
fp.write(str(3 * n) + " ")
for i in range(1, 3 * n):
    x = random.random()
    fp.write(str(int(x * n)) + " ")

fp.close()
print("%d random numbers generated in file random_%d.txt" % (3 * n, n))
