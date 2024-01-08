total = 0
with open("c.txt") as fichier:
    liste_calcul = fichier.read()
    total = eval(liste_calcul)
with open("v.txt","w") as fichier:
    fichier.write(str(total))
