# 🐣 S1 | Prog: Workshop

## Vert

![image](./images/logo.png) ➡️ ![image](./output/vert.png)


## Echange

![image](./images/logo.png) ➡️ ![image](./output/echange.png)

## Negatif

![image](./images/logo.png) ➡️ ![image](./output/negatif.png)

## Degrade

![image](./output/degrade.png)

## Miroir

![image](./images/logo.png) ➡️ ![image](./output/miroir.png)

## Bruit

![image](./images/logo.png) ➡️ ![image](./output/bruit.png)

## Rotation

![image](./images/logo.png) ➡️ ![image](./output/rotation.png)


## RGB Split

![image](./images/logo.png) ➡️ ![image](./output/rgb_split.png)

## Luminosite

![image](./images/photo.jpg) ➡️ ![image](./output/luminosite.png)

## Disque

![image](./output/disque.png)


## Cercle

![image](./output/cercle.png)

## Glich

![image](./images/logo.png) ➡️ ![image](./output/glitch.png)

## Contraste

![image](./images/photo_faible_contraste.jpg) ➡️ ![image](./output/contraste.png)

### Explication

On parcours tous les pixels pour trouver le pixel le plus sombre et le plus clair.
Ensuite on parcours à nouveau tous les pixels, et on applique une transformation sur chaque couleur dans la "nouvelle échelle" de luminosité.



## Convolution

![image](./images/logo.png) ➡️ ![image](./output/convolution.png)


### Explication

On choisit une taille de kernel, qui va représenter l'intensité du flou.
Pour chaque pixel, on parcours les pixels autour de lui, et pour chaque couleur on fait la moyenne des pixels autour. Ici j'ai fait une version simplifié dans laquelle tous les pixels ont le même poids.
