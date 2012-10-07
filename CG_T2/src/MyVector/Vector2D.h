#ifndef __Vector2D___H___
#define __Vector2D___H___

template<unsigned int n>
class Vector
{
public:
   Vector()
   {
      for( int i = 0; i < n; i ++)
      {
         _vet[i] = 0;     
      }
   }
   
   Vector& operator+=(const Vector& o)
   {
      for( int i = 0; i < n; i ++)
      {
         _vet[i] += o._vet[i];     
      }
      return *this;
   }
   /*
   Matriz& operator+(const Matriz& o)
   {
      for( int i = 0; i < nc+nl; i ++)
      {
         _vet[i] += o._vet[i];     
      }
      return this;
   }

   Matriz& operator-=(const Matriz& o)
   {
      for( int i = 0; i < nc+nl; i ++)
      {
         _vet[i] -= o._vet[i];     
      }
      return *this;
   }

   Matriz operator-(const Matriz& o)
   {
      for( int i = 0; i < nc+nl; i ++)
      {
         _vet[i] -= o._vet[i];     
      }
      return this;
   }

   //////////////////////////////////
   Matriz& operator*=(const double& o)
   {
      for( int i = 0; i < nc+nl; i ++)
      {
         _vet[i] *= o;     
      }
      return *this;
   }

   Matriz operator*(const double& o)
   {
      for( int i = 0; i < nc+nl; i ++)
      {
         _vet[i] *= o;     
      }
      return this;
   }

   Matriz& operator=(const Matriz& o)
   {
      for( int i = 0; i < nc+nl; i ++)
      {
         _vet[i] -= o._vet[i];     
      }
      return *this;
   }

   const double& operator()(unsigned x, unsigned y) const
   {
      return _vet[x*nl + y];
   }

   double& operator()(unsigned  x, unsigned  y)
   {
      return _vet[x*nl + y];
   }
   */
   /*template<unsigned m, unsigned n, unsigned p>
   Matriz<m,n> operator*(const Matriz<m,p>& A, const Matriz<p,n>& B)
   {
      Matriz<m,n> ret;
      return ret;
   }
   */


private:
   double _vet[n];
};

#endif