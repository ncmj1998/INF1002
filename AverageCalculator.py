import sys

a = sys.argv[1]
b = sys.argv[2]
c = sys.argv[3]

if a.isdigit() and b.isdigit() and c.isdigit():
    avg = (float(a) + float(b) + float(c)) / 3
    print(f"Average:{avg:.2f}")
else:
    print("Your input is invalid!")