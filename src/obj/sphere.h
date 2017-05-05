#ifndef ZIAR_OBJ_SPHERE_H
#define ZIAR_OBJ_SPHERE_H

#include "geom/vector.h"
#include "geom/ray.h"

typedef struct sphere {
  vector sp_pos; /** Sphere position. */
  float  sp_rad; /** Sphere radius.   */
} sphere;

/* Ray/sphere intersection. */
void sphere_intersect(sphere* s, ray* r, float* t);
void sphere_normal(sphere* s, vector* p, vector* n);

#endif
