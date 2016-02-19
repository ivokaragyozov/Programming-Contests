n = int(input())

dig1 = int(n / 10000)
dig2 = int(n / 1000 % 10)
dig3 = int(n / 100 % 10)
dig4 = int(n / 10 % 10)
dig5 = int(n % 10)

n1 = dig1 * 10000 + dig3 * 1000 + dig5 * 100 + dig4 * 10 + dig2;
n1 = n1 * n1 * n1 * n1 * n1

n1 = str(n1 % 100000)

while(len(n1) != 5):
	n1 = '0' + n1

print(n1)