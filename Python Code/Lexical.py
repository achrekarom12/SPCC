import re

keywords = ["if", "do", "while","for","else", "int",
    "float", "double", "include"]
operators = "+-*/%="
with open("Python Code/demo.txt", "r") as file:
    for line in file:
        words = re.findall("[a-zA-Z0-9_]+|[+\-*/%=]", line)
        for word in words:
            if word in operators:
                print(word, "is operator")
            elif word in keywords:
                print(word, "is keyword")
            else:
                print(word, "is an identifier")