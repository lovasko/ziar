#include <math.h>

#include "vector.h"

void
vector_init(vector* v, float x, float y, float z)
{
  v->vc_x = x;
  v->vc_y = y;
  v->vc_z = z;
}

void
vector_repeat(vector* v, float xyz)
{
  v->vc_x = xyz;
  v->vc_y = xyz;
  v->vc_z = xyz;
}

void
vector_copy(vector* dst, vector* src)
{
  dst->vc_x = src->vc_x;
  dst->vc_y = src->vc_y;
  dst->vc_z = src->vc_z;
}

void
vector_add(vector* v, vector* u)
{
  v->vc_x += u->vc_x;
  v->vc_y += u->vc_y;
  v->vc_z += u->vc_z;
}

void
vector_sub(vector* v, vector* u)
{
  v->vc_x -= u->vc_x;
  v->vc_y -= u->vc_y;
  v->vc_z -= u->vc_z;
}

void
vector_mul(vector* v, float s)
{
  v->vc_x *= s;
  v->vc_y *= s;
  v->vc_z *= s;
}

void
vector_norm(vector* v)
{
  float f;

  f = 1.0f
    / sqrtf(v->vc_x * v->vc_x
          + v->vc_y * v->vc_y
          + v->vc_z * v->vc_z);

  v->vc_x *= f;
  v->vc_y *= f;
  v->vc_z *= f;
}

void
vector_dot(vector* v, vector* u, float* d)
{
  *d = v->vc_x * u->vc_x
     + v->vc_y * u->vc_y
     + v->vc_z * u->vc_z;
}

void
vector_cross(vector* v, vector* u, vector* c)
{
  c->vc_x = v->vc_y * u->vc_z - v->vc_z * u->vc_y;
  c->vc_y = v->vc_z * u->vc_x - v->vc_x * u->vc_z;
  c->vc_z = v->vc_x * u->vc_y - v->vc_y * u->vc_x;
}