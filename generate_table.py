import random

rows = 100
cols = 100
output_file = "input100.txt"

with open(output_file, "w") as f:
    f.write(f"{rows} {cols}\n")
    
    for _ in range(rows):
        # Generate one row of random numbers between 0.01 and 0.99
        row_values = [f"{random.randint(1, 99) / 100:.2f}" for _ in range(cols)]
        # Join them with spaces and write to file
        f.write(" ".join(row_values) + "\n")

print(f"Success! Created {output_file}")