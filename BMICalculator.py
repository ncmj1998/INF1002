import sys

type = sys.argv[1]
height = sys.argv[2]
weight = sys.argv[3]

#checking that both height input and weight input contains only digit so we can convert them to float for calculation
try:
    height = float(height)
    weight = float(weight)
    bmi = 0
    category = ""
    if type == "metric":
        bmi = weight / (height**2)
    elif type == "imperial":
        bmi = 703 * weight  / (height**2)
    else:
        print("Your input is invalid")
        exit()
    if bmi <= 16 :
        category = "Severe Thinness"
    elif bmi <= 17 :
        category = "Moderate Thinness"
    elif bmi <= 18.5:
        category = "Mild Thinness"
    elif bmi <= 25:
        category = "Normal"
    elif bmi <= 30:
        category = "Overweight"
    elif bmi <= 35:
        category = "Obese Class I"
    elif bmi <= 40:
        category = "Obese Class II"
    else:
        category = "Obese Class III"
    print(f"{bmi:.2f}\t {category}")

except ValueError:
    print("Your input is invalid")

