# projet_mutation_aliens
### Hugo Guiraud et Aymée Bonvarlet
A remettre avant le 24 décembre 2020
## Appréhension du sujet 

On va créer un programme donnant la possibilité à une population de connaître le meilleur individu après X générations. Ainsi définir un fitness adapter en fonction des gènes qui nous intéresserons. 
On classera après chaque génération par ordre croissant les individus obtenues. 
Ainsi l'individu ayant obtenu le fitness le plus bas ne sera pas utilisé pour créer la prochaine génération. A contrario l'individu ayant obtenu le meilleur fitness sera quant à lui, utilisé deux fois pour la prochaine génération afin de compenser ce dernier. 

Chaque génération comporte 7 individus non genré puisque se sont des aliens capables d'adapter leur sexe.

Chaque gène pourra muter avec la propabilité de 25%.

gène 1 : allèle schtroumpf récessif (+) (être bleu c'est cool)
gène 2 : taille tantacules (+) (+ nbre de ventouse?)
gène 3 : allèle strabisme récessif (-) (être trop différent c'est chiant)

-> tenir compte de l'environnement ext
-> selection naturelle

étape 1 : appréhender TSP et Labyrinthe, commenter les éléments dont nous nous resservirons afin d'utiliser la même méthode.
étape 2 : créer un fichier BOUML afin de bien définir nos fonctions.
étape 3 :  programmer le code avec un gène sur Qt
étape 4 :  incorporer les autres gènes au projet Qt
étape 5 : graphique si temps

