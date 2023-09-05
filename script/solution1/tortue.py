import turtle

def tourne_gauche(angle):
    turtle.left(angle)

def tourne_droite(angle):
    turtle.right(angle)

def avance(distance):
    turtle.forward(distance)

def recule(distance):
    turtle.backward(distance)

input_file = "turtle"

turtle.speed(5)  # Vitesse de dessin
turtle.shape("turtle")  # Changer la forme du curseur

with open(input_file, "r") as file:
    instructions = file.readlines()

for instruction in instructions:
    instruction = instruction.strip()
    parts = instruction.split()
    
    if len(parts) >= 2:
        action = parts[0]

        if action == "Tourne":
            angle = int(parts[-2])
            if "gauche" in instruction:
                tourne_gauche(angle)
            elif "droite" in instruction:
                tourne_droite(angle)
        elif action == "Avance":
            distance = int(parts[1])
            avance(distance)
        elif action == "Recule":
            distance = int(parts[1])
            recule(distance)

turtle.done()  # Termine le dessin

