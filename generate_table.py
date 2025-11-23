import random

# Configuration
rows = 500
cols = 500
output_file = "input.txt"

with open(output_file, "w") as f:
    # 1. Write the header
    f.write(f"{rows} {cols}\n")
    
    # 2. Generate and write the rows
    for _ in range(rows):
        # Generate one row of random numbers between 0.01 and 0.99
        row_values = [f"{random.randint(1, 99) / 100:.2f}" for _ in range(cols)]
        # Join them with spaces and write to file
        f.write(" ".join(row_values) + "\n")

print(f"Success! Created {output_file}")