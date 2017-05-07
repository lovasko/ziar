#include "obj/plane.h"

void
plane_intersect(plane* p, ray* r, float* t)
{
  vector ori;
  float angle;

  *t = 0.0f;
  vector_dot(&angle, &p->pl_nor, &r->ry_dir);

  if (angle == 0.0f)
    return;

  vector_copy(&ori, &r->ry_ori);
  vector_sub(&ori,  &p->pl_pos);
  vector_dot(t, &ori,  &p->pl_nor);

  *t *= -1.0f/angle;
}

void
plane_normal(plane* s, vector* p, vector* n)
{
  (void)p;
  vector_copy(n, &s->pl_nor);
}
