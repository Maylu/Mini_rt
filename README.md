# Mini_rt

This project has been created as part of the 42 curriculum by gcamara and rhmontei.

## Description

### Definition

Ray tracing is a computer-based technique for calculating light, used in computer-generated imagery (CGI) rendering. This technique simulates the path of light between the camera and light sources in a 3D scene.
For each pixel on the screen, a ray is generated from the camera and cast into the 3D scene. These rays generate impact points when they encounter objects.
From these points of impact, additional rays can be cast to determine various properties of the image, such as brightness, color, reflections, shadows, and so on.


### Point Impact

The point of impact is the precise point where the ray intersects the surface of an object.

A ray is defined by an origin and a direction. Its position along the ray can be calculated using the following mathematical formula:

**P(t) = O + t × D**

* **O**: the origin of the ray (3D vector).
* **D**: the normalized direction vector (3D vector).
* **t**: the distance traveled along the ray (**t > 0**).

To find the point of impact, the value of **t** must be determined using the intersection algorithm with geometric objects. This value of **t** is then substituted back into the formula to calculate the exact coordinates of the point of impact.


### Shapes

In this project, we have three geometric shapes: the sphere, the plane, and the cylinder.

#### Sphere

A sphere is an object in which every point on its surface is located at the same distance from its center. This distance is called the radius R.
It is defined by the equation:

**‖P - C‖² = R²**

P: a point on the surface of the sphere.
C: the center of the sphere.
R: the radius of the sphere.

We then substitute P into the equation for the radius:

**P(t) = O + t × D**

This yields a quadratic equation that allows us to determine the value(s) of t. The discriminant Δ tells us whether the radius intersects the sphere and determines the number of points of intersection.

#### Plane

A plane is defined by a point P₀ lying on the plane and a vector N normal to the plane, that is, perpendicular to it.
The equation of the plane can be expressed as:

**(P - P₀) · N = 0**

P: a point on the surface of the plane.
N: the normal of the plane.
R: the origin of the plane.

We then substitute P with the equation of the ray:

**P(t) = O + t × D**

This yields an equation that allows us to determine t from the dot product between the direction of the ray and the normal to the plane.
If the ray is parallel to the plane, there is no intersection (except in the case where the ray lies within the plane).

#### Cylinder

A cylinder is defined by the distance between a point P and the axis of the cylinder, which must be equal to its radius R.

For a cylinder aligned with the Y-axis, the calculation can be performed in the XZ plane, ignoring the Y-component.

The equation then becomes:

**(Pₓ - Cₓ)² + (P𝓏 - C𝓏)² = R²**

P: a point on the radius.
C: the center of the cylinder.
R: the radius of the cylinder.

The principle is similar to that of a sphere, but the calculation is performed on a 2D circle. Therefore, the Y-component is ignored during the calculation.

By substituting P with the equation of the radius, we again obtain a quadratic equation. The discriminant Δ then allows us to determine the number of intersections between the radius and the cylinder.

#### Interpretation of the discriminant

Δ < 0: The ray does not touch the object.
Δ = 0: The ray touches the object at a single point.
Δ > 0: The ray intersects the object at two points.


### Camera

In a ray tracer, the camera works differently from a real camera. Instead of receiving light from the scene, it shoots rays from its viewpoint, through a virtual screen, to determine what each ray hits in the scene.

The camera is defined by:

* **O**: the camera’s origin.
* **A virtual screen**: a grid of pixels located at a fixed distance in front of the camera in the 3D world.
* **A three-axis coordinate system**: **X, Y, and Z**, used to define the camera’s orientation.

For each pixel with coordinates **(x, y)**, we calculate its position on the virtual screen. We start from the center of the screen, then shift by **x** along vector **U** and by **y** along vector **V**.

We can then calculate the pixel’s position on the screen using the formula:

**P(x, y) = C + x × U + y × V**

* **C**: the center of the virtual screen.
* **U**: the vector representing the horizontal axis of the screen.
* **V**: the vector representing the vertical axis of the screen.

We then calculate the direction of the ray going from the camera to the point **P(x, y)** on the screen:

**D = P(x, y) - O**

This vector **D** represents the direction of the ray. It is then used in the object intersection equations to determine the value of **t** and thus the point of impact of the ray in the scene.

### Pixel Treatments

une fois qu'on a trouve le point d'impact, le calcul de la couleur du pixel combine la couelur defini de l'objet et la lumiere qui recoit
nous pouvons determiner 
la couleur
la lumiere
la normale
la speculaire
l'ombre

Nous nous sommes bases sur le modele lambertian qui est compose de la diffuse et de la speculaire en tenant compte des ombres

Couleur et lumiere

l'object a une couleur et une source de couleur, on deffini un vecteur L qui va vers qui v vers le point d'impact P et une normale N qui est perpendiculaire au point d'mpact P


Diffuse

Le lambert est un ecairage de base, plus une surface fait face a a lumiere pus ee est ecairee, si la lumierer frappe de blais c'est pus sombre

L = max(O, N * L)
si N * L= 1 la lumiere frappe a 90 degre donc pein ecairage
si N * L <= 0 aucun eclairage ne touche la surface

Ombre Porte

Avant d'ajouter a couleur au pixe on verifie si il y a un obstacle entre le point dimpact et la umiere
On lance un rayon d'ombre, si le rayon touche une autre forme avant d'atteindre a lumiere le point est a 'ombre et donc on mutiplie par a valeur ambiante

La Speculaire

Le speculaire ajoute le reflet brillant a la surface, dependant de la position de la camera
Pour cela on utilise la formule de phong
spec = max(O, R*V)
plus le rayon refechi va directement dans 'oeil plus a tache est brillante

Pour finir on assenbe le tout dans la couleur finale

C = Ambiant + Ombre * (couleur_obj * couleur_lum * L) + (couleur_lum *spec)


## Instructions

`make`
`./minirt Scene/multi_shapes.rt`

With bonus

`make bonus`
`./minirt Scene/Bonus/multi_shapes.rt`

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