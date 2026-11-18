import os
import importlib

def load_plugins(directory):
    plugins = []

    for file in os.listdir(directory):
        if file.endswith(".py") and file != "__init__.py":
            module = importlib.import_module("extensions." + file[:-3])

            for obj in vars(module).values():
                if isinstance(obj, type) and hasattr(obj, "transform"):
                    plugins.append(obj())

    return plugins


text = input("Enter text: ")

plugins = load_plugins("extensions")

for p in plugins:
    text = p.transform(text)

print("Result:", text)