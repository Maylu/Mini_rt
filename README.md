# Mini_rt

This project has been created as part of the 42 curriculum by gcamara and rhmontei.

## Description

### Definition

Le ray tracing est une technique de calcul de la lumiere par ordinateur, qui est utilise pour le rendu d'image de synthese par ordinateur. cette technique simule le parcours de la lumiere de l'oeil a la source lumineuse. 

Cette technique consiste pour chaque pixel a l'ecran, on genere un lancer de rayon depuis la camera dans la scene 3D. ces rayons vont generer des points d'impacts

a partir de ces points d'impacts d'autres rayons seront lances pour determine sa luminosite, sa couleur, sa reflexion etc..

### Point Impact

Le point d'impact est le point precis, ou le rayon rencontre la surface de l'objet

Le rayon est defini par l'origine et une dirrection, on la trouve sous grace a cette formule mathematique

P(t) = O+t*D

O : le point d'origine du rayon (vecteur 3D).
D : le vecteur direction normalisé (vecteur 3D).
t : la distance parcourue le long du rayon (t > 0).

Pour trouver le point d'impact, on doit trouver t dans l'algorithme des objects geometriques, qui sera reinjecter dans cette formule.

### Shapes

Dans ce projet nous avons trois formes geometriques

Sphere
une sphere est un objet qui a la meme distance est definie par cette equation

P - C = r

P : equation du rayon
R : la distance du rayon de la sphere
C  : centre de la sphere

on remplace P par l'equation du rayon, et on obtient une equation du second degre qui permet de determiner t avec le discriminant Delta qui indique si le rayon touche la sphere

Plane
Le plan est defini par un point et un vecteur N perpendiculaire au plan et orthogonal a N

P - P0

on remplace P par l'equation du rayon et on obtient une equation du second degre qui permet de determiner t avec un doc product avec la distance et la normale 

P = Point appartenant au plan

Cylinder
il s'agit de la distance entre un point et l'axe du cylindre doit etre egale au rayon r

(Px - Cx) + (Pz - Cz) = R

c'est identique a la sphere mais en ignonrant la composante 



### Camera

### Raytracer

### Pixel Treatments

## Instructions

`make`
`./minirt Scene/multi_shapes.rt`

With bonus

`make bonus`
`./minirt Scene/multi_shapes.rt`

## Resources

- 3D Computer Graphics Primer: Ray-Tracing as an Example :
https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing//implementing-the-raytracing-algorithm.html

- Essence of linear algebra :
https://youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab&si=HBm_BWmkXBNAmAvA

- LEMAIRE Benoît, Développement d'un Raytracer, 2002. 
https://www.alrj.org/docs/3D/raytracer/

- Guidebook Minirt :
https://42-cursus.gitbook.io/guide/4-rank-04/minirt/understand-minirt

- Articles Medium :
https://medium.com/@iremoztimur/building-a-minirt-42-project-part-1-ae7a00aebdb9
https://m4nnb3ll.medium.com/minirt-mini-ray-tracer-a-42-the-network-graphical-project-d909bef10025
https://medium.com/@mansurimohamad92/the-mathematics-behind-the-minirt-42-project-a-comprehensive-exploration-213e149c85d8

- Implementing the Raytracing Algorithm :
https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing//implementing-the-raytracing-algorithm.html

- Determining plane intersection with a ray :
https://math.stackexchange.com/questions/4402134/determining-plane-intersection-with-a-ray?utm_source=perplexity

- BUCK James, The Ray Tracer Challenge: A Test-Driven Guide to Your First 3D Renderer, 2019, The Pragmatic Programmers.
http://raytracerchallenge.com/