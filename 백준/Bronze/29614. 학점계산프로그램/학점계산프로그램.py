grade_dict = {
    "A+": 4.5,
    "A": 4.0,
    "B+": 3.5,
    "B": 3.0,
    "C+": 2.5,
    "C": 2.0,
    "D+": 1.5,
    "D": 1.0,
    "F": 0.0,
}

grade = input() + "@"  # for 순회를 위해 무의미한 @ 추가

subject = []
for i in range(len(grade) - 1):
    if grade[i] == "+":
        continue

    if grade[i + 1] == "+":
        subject.append(grade[i] + "+")
    else:
        subject.append(grade[i])

total = 0
for s in subject:
    total += grade_dict[s]

print(total / len(subject))
