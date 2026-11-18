try:
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))

    result = a / b

except (ValueError, ZeroDivisionError) as e:
    print("Error:", e)

else:
    print("Result:", result)

finally:
    print("Program completed")