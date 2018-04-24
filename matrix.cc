
#include "matrix_class.h"

bool debug = false;
//
// constructors

//*****************************************************************************
//*             class  : matrix ()                                            *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// constructor function for matrix  or vector
// you will need to use a create function afterwards.
//
template < class T >
matrix<T> :: matrix(void)
{
   set_debug_on();
   if(debug) {trace_message(1);}
   
   num_rows = 0; num_cols = 0; mptr = NULL; 
   max_id_len = 80; id = " ";
   
   if(debug) {trace_message(2);}   
   set_debug_on();
   return;   
}

//*****************************************************************************
//*             class  : matrix (nr)                                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// constructor function for vector
// it helps creates the size of the vector too
//
template < class T >
matrix<T> :: matrix(int nr)
{
   set_debug_on();
   if(debug) {trace_message(3);}  

//   mptr=NULL;
   create ("", nr);
   
   if(debug) {trace_message(4);}    
   set_debug_on();
   return;   
}

//*****************************************************************************
//*             class  : matrix (nr,nc)                                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// constructor function for matrix
// it helps creates the size of the matrix too
//
template < class T >
matrix<T> :: matrix(int nr, int nc)
{
   set_debug_on();
   if(debug) {trace_message(5);}
   
//   mptr=NULL;
   create ("", nr, nc);
   // some1 said we shoul add set_value. How does it come in?
   
   if(debug) {trace_message(6);}
   set_debug_on();
   return;   
}

//*****************************************************************************
//*             class  : matrix (id,nc)                                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// constructor function for vector
// it helps store the id/attributes and creates the size of the matrix
//
template < class T >
matrix<T> :: matrix(string id, int nr)
{
   set_debug_on();
   if(debug) {trace_message(7);}
   
//   mptr=NULL;
   create (id, nr);
   
   if(debug) {trace_message(8);}   
   set_debug_on();
   return;   
}

//*****************************************************************************
//*             class  : matrix (id,nr,nc)                                    *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// constructor function for matrix
// it helps store the id/attributes and creates the size of the matrix 
//
template < class T >
matrix<T> :: matrix( string id, int nr, int nc )
{
   set_debug_on();
   if(debug) {trace_message(9);}   
   
//   mptr=NULL;
   create (id, nr, nc);
   // some1 said we shoul add set_value. How does it come in?
   
   if(debug) {trace_message(10);}
   set_debug_on();
   return;   
}


template <class T>
matrix<T> :: matrix( const matrix<T> & a)
{
   set_debug_on();
   if(debug) {trace_message(11);}
   
   if(a.mptr==NULL){error_mess(10);}

   create ( a.id, a.num_rows, a.num_cols);
   for(int j=1; j<=num_rows*num_cols; j++)
      { (*this)(j)= a(j);}
  
   if(debug) {trace_message(12);}
   set_debug_on();
   return;  
}

//
// destructor
//
template < class T >
matrix<T> :: ~matrix(void)
{
   set_debug_on();
   if(debug) {trace_message(13);}
   
   free();
   
   if(debug) {trace_message(14);}
   set_debug_on();
   return;   
}

//
// create and Free Matrices
//

//*****************************************************************************
//*             class  : create                                               *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function creates a vector
//
template < class T >
void matrix <T> :: create( int nr )
{
   set_debug_on();
   if(debug) {trace_message(15);}
   
   if( nr < 0) {error_mess(21); return; }
   if( mptr != NULL) { error_mess(22); return;}
   mptr = new T[nr];
   num_rows = nr; num_cols = 1; ////////////////////Ask Prof Dodds
   
   if(debug) {trace_message(16);}
   set_debug_on();
   return;	
}



template < class T >
void matrix <T> :: create (string s, int nr)
{
   set_debug_on();
   if(debug) {trace_message(17);}
   
   if( nr < 0) {error_mess(21); return; }
   if( mptr != NULL) { error_mess(22); return;}
//   if (s.size()> max_id_len){ max_id_len=s.size();};
   id.reserve(max_id_len);//////////should it be included?	
//   cout <<  s.size()<< "thaT is the size for mat_1\n";/////////remove
   id = s;
   mptr = new T[nr];
   num_rows = nr; num_cols = 1;
   
   if(debug) {trace_message(18);}
   set_debug_on();   
   return;	
}

//*****************************************************************************
//*             class  : create                                               *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
// This is an overloaded create function 
// it creates a 2-D matrix
//
template < class T >
void matrix <T> :: create( int nr, int nc )
{
   set_debug_on();
   if(debug) {trace_message(19);}

   if( nr < 0) {error_mess(1); exit(0); }
   if( nc < 0) {error_mess(5); exit(0); }
   if( mptr != NULL) { error_mess(2); return;}
   
   num_rows = nr; num_cols = nc;
   mptr = new T[nr*nc];
   
   if(debug) {trace_message(20);}
   set_debug_on();
   return;
}


template < class T >
void matrix <T> :: create( string s, int nr, int nc )
{
   set_debug_on();
   if(debug) {trace_message(21);}
   
   if( nr < 0) {error_mess(1); return; }
   if( nc < 0) {error_mess(5); return; }
 //  if( mptr != NULL) { error_mess(2); return;} //////////////////////main.cc caused
///THIS IS 2 lines ARE causing trouble
//   if (s.size()> max_id_len){ max_id_len=s.size();};
  // id.reserve(max_id_len);//////////should it be included?	
   id = s;
   num_rows = nr; num_cols = nc;
   mptr = new T[nr*nc];
   
   if(debug) {trace_message(22);}
   set_debug_on();
   return;
}

//*****************************************************************************
//*             class  : free                                                 *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/15/2018                                      *
//*                                                                           *
//*****************************************************************************
//
//This function frees vector or 2-D matrix
//
template < class T >
void matrix<T> :: free( void )
{
   set_debug_on();
   if(debug) {trace_message(23);}
   
   num_rows = 0; num_cols = 0; id = " ";
   if( mptr != NULL ){ delete[] mptr;}
   mptr = NULL;
   
   if(debug) {trace_message(24);}
   set_debug_on();
   return;  
}

//
// Functions that provide protected access
//

//*****************************************************************************
//*             class : get_num_rows                                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function provides the number of rows 
// of a vector or a 2-D matrix. 
// 
template < class T >
int matrix <T> :: get_num_rows( void)
{
   set_debug_on();
   if(debug) {trace_message(25);}
   
//   if( ! mptr >= NULL) { error_mess(6); return(0);}
//   if(! num_rows  0) { error_mess(6); return(0);}
   
   if(debug) {trace_message(26);}
   set_debug_on();   
   return ( num_rows);      
}

//*****************************************************************************
//*             class : get_num_rows                                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function provides the number of cols 
// a 2-D matrix has. 
// It can also be used to check if the instance is a vector (num_cols=1)
//

template < class T >
int matrix <T> :: get_num_cols( void)
{
   set_debug_on();
   if(debug) {trace_message(27);}

 //  if( mptr == NULL) { error_mess(6); return(0);}
 
   if(debug) {trace_message(28);}   
   set_debug_on();
   return ( num_cols); 
 
}

template < class T >
string matrix <T> :: get_name()
{
   set_debug_on();
   if(debug) {trace_message(29);}

//   if( mptr == NULL) { error_mess(6); return("ERROR!");}
//   if( id == " ") { error_mess(7); return ("ERROR!");}

   if(debug) {trace_message(30);}
   set_debug_on();   
   return(id);	
}

template < class T >
void matrix <T> :: set_name(string s)
{
   set_debug_on();
   if(debug) {trace_message(31);}

 //  if( mptr == NULL) { error_mess(6); return;}// must u always define the size before naming?
//   if (s.size()> max_id_len){ max_id_len=s.size();};
   id.reserve(max_id_len);//////////should it be included?	
   id = s;	
	
   if(debug) {trace_message(32);}
   set_debug_on();
   return;	
}

template < class T >
void matrix <T> :: set_value( T value)
{
   set_debug_on();
   if(debug) {trace_message(33);}	
   
   if( mptr == NULL) { error_mess(6); return;}
   for(int i=1; i<=num_rows; i++)
      {
		 for( int j=1; j<= num_cols; j++)
		    { (*this)(i,j) = value;}			 
	  }
	  
   if(debug) {trace_message(34);}   
   set_debug_on();   
   return;	
}

template < class T >
void matrix <T> :: set_value( int row, T value )
{  
   set_debug_on();
   if(debug) {trace_message(35);}
   
   if ( num_cols > 1){ error_mess(12); return;}
   if( mptr == NULL) { error_mess(26); return;}
   if(row > num_rows) { error_mess(3);return;}
   mptr[row -1] = value;
   
   if(debug) {trace_message(36);}
   set_debug_on();
   return;
}

////////////////////////////////////////////////////////////////////change to *this
template < class T >
void matrix <T> :: set_value( int row, int col, T value )
{
  set_debug_on();
  if(debug) {trace_message(37);}
  
  if( num_cols == 1){ error_mess(14); return;}
  if( mptr == NULL) { error_mess(16); return;} 	
  if(row > num_rows) { error_mess(3);return;}
  if(col > num_cols) { error_mess(4);return;}
  mptr[num_cols*(row-1)+ col-1]= value;

  if(debug) {trace_message(38);}
  set_debug_on();  
  return;
}

template < class T >
T matrix <T> :: get_value( int row)
{
   set_debug_on();
   if(debug) {trace_message(39);}
    
   if( num_cols > 1){ error_mess(13); return(0);}
   if( mptr == NULL) { error_mess(26); return(0);}
   if(row > num_rows) { error_mess(3);return(0);}
   
   if(debug) {trace_message(40);}
   set_debug_on();
   return( mptr[row-1]);	
}

template < class T >
T matrix <T> :: get_value( int row, int col)
{
	set_debug_on();
	if(debug) {trace_message(41);}
	
	if( num_cols == 1){ error_mess(15); return(0);}
	if( mptr == NULL) { error_mess(6); return(0);}
	if(row > num_rows) { error_mess(3);return(0);}
	if( num_cols == 1){ error_mess(11); return(0);}
	if(col > num_cols) { error_mess(4);return(0);}
	
	if(debug) {trace_message(42);}
	set_debug_on();
    return( (*this)(row,col) );	
}




//*****************************************************************************
//*             class : operator ()(i)                                           *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function overloads the () operator
// for indexing of a vector  
// 
template < class T >
T& matrix <T> :: operator () (int row) const
{ 
//   set_debug_on();
//   if(debug) {trace_message(43);}
   
 //   if( mptr == NULL) { error_mess(26); return(0);}//
 //  if(row > num_rows) { error_mess(3); return (0);}//
   
 //    if(debug) {trace_message(44);}
//   set_debug_on();
   return (mptr[row-1]);	
}

//*****************************************************************************
//*             class : operator ()(i,j)                                      *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 4/28/2018                                      *
//*                                                                           *
//*****************************************************************************
//
// This function overloads the () operator
// for indexing a 2-D matrix  
//
template < class T >
T& matrix <T> :: operator() (int row, int col) const
{
//   set_debug_on();
// if(debug) {trace_message(45);}
   
//   if( mptr == NULL) { error_mess(6); return (0);}
//   if(row > num_rows) { error_mess(3);return(0);}
//   if(col > num_cols) { error_mess(4);return(0);}
   
 //if(debug) {trace_message(46);}
 //  set_debug_on();
   return( mptr[num_cols*(row-1)+ col-1] );	
}


template < class T >
matrix<T> matrix<T> :: operator * (matrix <T>& b)
{
   set_debug_on();
   if(debug) {trace_message(47);}
   
   int nrow, ncol; 
   if( mptr == NULL) { error_mess(16); exit(0);}
   if(num_cols != b.num_rows ) {error_mess(19); exit(0);}
   matrix<T> temp;
   temp.multiply (*this,b);
   
   if(debug) {trace_message(48);}
   set_debug_on();
   return temp;   
}

template < class T >
matrix<T> matrix<T> :: operator + (matrix <T>& b)
{
   set_debug_on();
   if(debug) {trace_message(49);}
   
   int nrow, ncol;
   if( mptr == NULL) { error_mess(16); exit(0);}//////////////////
   if( b.mptr == NULL) { error_mess(6); exit(0);}  
   if(num_rows != b.num_rows){ error_mess(29); exit(0);}//Prof Dodds said we could use exit(0)
   if(num_cols != b.num_cols){ error_mess(30); exit(0);}//Prof Dodds said we could use exit(0)
   matrix<T> temp;
   temp.add (*this,b);
   
   if(debug) {trace_message(50);}
   set_debug_on();
   return temp;   
}

template < class T >
matrix<T> matrix<T> :: operator - (matrix <T>& b)
{
   set_debug_on();
   if(debug) {trace_message(51);}
   
   int nrow, ncol;
   if( mptr == NULL) { error_mess(16); exit(0);}
   if( b.mptr == NULL) { error_mess(6); exit(0);}  
   if(num_rows != b.num_rows){ error_mess(29); exit(0);}
   if(num_cols != b.num_cols){ error_mess(30); exit(0);}
   matrix<T> temp;
   temp.subtract (*this,b);
   
   if(debug) {trace_message(52);}
   set_debug_on();
   return temp;   
}

template < class T >
matrix<T>& matrix<T> :: operator = (const matrix <T>& rhs)
{
   set_debug_on();
   if(debug) {trace_message(53);}

   string save_id = rhs.id;
   if( mptr == rhs.mptr) return(*this);
   assert( rhs.num_rows >0);
   create( save_id, rhs.num_rows, rhs.num_cols );
   (*this).copy( rhs);
  
   if(debug) {trace_message(54);}
   set_debug_on();   
   return (*this);
}



template < class T >
void matrix <T> :: copy( const matrix <T>& rhs)
{
   set_debug_on();
   if(debug) {trace_message(55);}
   
   ///remove the (*this)(1)=1;(*this)(2)=1;
   if( mptr == NULL) { error_mess(16); return;}//(*this);}
//   if(num_rows != rhs.num_rows ) {error_mess(27); return;}
//   if(num_cols != rhs.num_cols ) {error_mess(28); return;}   
   for(int j=1; j<= rhs.num_rows*rhs.num_cols; j++)
	 {(*this)(j) = rhs(j);}
   
   if(debug) {trace_message(56);}
   set_debug_on();   
   return;
//   return(*this);	
}

template < class T >
void matrix <T> :: diagonal( T value)
{
   set_debug_on();
   if(debug) {trace_message(57);}
  
   if( mptr == NULL) { error_mess(6); return;}
   if( num_cols ==1){ error_mess(18); return;}
   if( ! num_rows == num_cols){ error_mess(8); return;}
   // check if the matrix has been created
   int i, j; double dzero =0.0;
   for( i=1; i <=num_rows; i++)
      {	 
         for( j=1; j <= num_cols; j++)
		    { (*this)(i,j)=dzero; }
	     (*this)(i,i) = value;
	  } 
	  
   if(debug) {trace_message(58);}
   set_debug_on();   
   return;
}

template < class T >
void matrix <T> :: identity(void)
{
   set_debug_on();
   if(debug) {trace_message(59);}
  
   if( mptr == NULL) { error_mess(6); return;}
   if( num_cols ==1){ error_mess(18); return;}
   if( ! num_rows == num_cols){ error_mess(8); return;}
   // check if the matrix has been created
   int i, j; double dzero =0.0, done=1.0;
   for( i=1; i <=num_rows; i++)
      {	 
         for( j=1; j <= num_cols; j++)
		    { (*this)(i,j)=dzero; }
	     (*this)(i,i) = done;
	  }
	  
   if(debug) {trace_message(60);}
   set_debug_on();   
   return;
}








//*****************************************************
//
//    invert service (method) of matrix class
//
//*****************************************************
//
//
template <class T>
void matrix <T> :: invert( matrix<T>& a, T& det )
{
   set_debug_on();
   if(debug) {trace_message(61);}
	  
   int  k, j, i, nrow, ncol;
//
//   inverts a matrix by gauss-jordan elimination.
//   also computes the determinant. check for singular matrix.
//
//   use of temporary enables non-modification of left-side
//   if matrix is singular.
//
   T zero = static_cast<T> (0.0);
   T one  = static_cast<T> (1.0);
   det  = one;
   nrow = a.num_rows;
   ncol = a.num_cols;
   assert( nrow > 0 && ncol > 0 );
   if(nrow != ncol){ error_mess(33); return;}
   matrix <T> temp( a );
//
   for( k=1; k<=nrow; k++ )
    {
     if( temp(k,k) == zero ) { det = zero; return; }
     det = det * temp(k,k);
     for( j=1; j<=ncol; j++ )
       if( j!=k ) temp(k,j) = temp(k,j) / temp(k,k);
     temp(k,k) = one / temp(k,k);
     for( i=1; i<=nrow; i++ )
       {
         if( i==k ) continue;
         for( j=1; j<=ncol; j++ )
           if( j!=k ) temp(i,j) = temp(i,j) -
                      temp(i,k) * temp(k,j);
         temp(i,k) = -temp(i,k) * temp(k,k);
       }
    }
//
   (*this) = temp;
   
   if(debug) {trace_message(62);}   
   set_debug_on();
   return;
}


/// still needs to work on error messages!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//check existence,...............others 
template < class T >
void matrix <T> :: transpose( matrix <T> & b)
{
   set_debug_on();
   if(debug) {trace_message(63);}
  
 //  if(mptr == NULL) { error_mess(6); return;}
   if( num_cols ==1){ error_mess(18); return;}
// check if the matrix has been created
   int i, j; 
//   if 
   
   for( i=1; i <=b.num_rows; i++)
      {	 
         for( j=1; j <= b.num_cols; j++)
		    { (*this)(i,j)=b(j,i); }
	  } 
   

   if(debug) {trace_message(64);}
   set_debug_on();   
   return;
}






template < class T >
void matrix<T> :: multiply(matrix <T>& a, matrix <T>& b)
{
   set_debug_on();
   if(debug) {trace_message(65);}
   
   int nrow, ncol, nterms, i,j,k;
   T zero = static_cast<T> (0);
   T sum; 
   if( a.mptr == NULL) { error_mess(6); return;}
   if( b.mptr == NULL) { error_mess(6); return;}   
   if(a.num_cols != b.num_rows){ error_mess(19); return;}//Prof Dodds said we could use exit(0)
   free();
   nrow = a.num_rows; ncol = b.num_cols;
   create( " ", nrow, ncol);
   //
   for( i=1; i<=nrow; i++)
      {
	   for(j=1; j<=ncol; j++)
	      {
		   sum = zero;
	       for(k=1; k<=a.num_cols; k++)
		      { sum += a(i,k) * b(k,j);}
		      (*this)(i,j) = sum;
		  }
	  }
	  
   if(debug) {trace_message(66);}   
   set_debug_on();
   return;  
}
   

template < class T >
void matrix<T> :: add(matrix <T>& a, matrix <T>& b)
{
   set_debug_on();
   if(debug) {trace_message(67);}
   
   int nrow, ncol, i,j; 
   
   if( a.mptr == NULL) { error_mess(6); return;}
   if( b.mptr == NULL) { error_mess(6); return;}  
   if(a.num_rows != b.num_rows){ error_mess(29); return;}//Prof Dodds said we could use exit(0)
   if(a.num_cols != b.num_cols){ error_mess(30); return;}//Prof Dodds said we could use exit(0)
   free();
   nrow = a.num_rows; ncol = a.num_cols;
   create( " ", nrow, ncol);
   for( i=1; i<=nrow; i++)
      {
	   for(j=1; j<=ncol; j++)
	      {
			  (*this)(i,j)= a(i,j) + b(i,j);
		  }
	  }
	  
   if(debug) {trace_message(68);}
   set_debug_on();
   return;  
}
   
 
template < class T >
void matrix<T> :: subtract(matrix <T>& a, matrix <T>& b)
{
   set_debug_on();
   if(debug) {trace_message(69);}
   
   int nrow, ncol, i,j; 
   
   if( a.mptr == NULL) { error_mess(6); return;}
   if( b.mptr == NULL) { error_mess(6); return;}  
   if(a.num_rows != b.num_rows){ error_mess(31); return;}//Prof Dodds said we could use exit(0)
   if(a.num_cols != b.num_cols){ error_mess(32); return;}//Prof Dodds said we could use exit(0)
   free();
   nrow = a.num_rows; ncol = a.num_cols;
   create( " ", nrow, ncol);
   for( i=1; i<=nrow; i++)
      {
	   for(j=1; j<=ncol; j++)
	      {
			  (*this)(i,j)= a(i,j) - b(i,j);
		  }
	  }
	  
   if(debug) {trace_message(70);}
   set_debug_on();
   return;  
}
 
 
template < class T >
void matrix<T> :: write_to_file( fstream & file)
 {
   set_debug_on();
   if(debug) {trace_message(71);}
   
   if( num_rows == 0 ) return;
   file.write( reinterpret_cast <char *> (&num_rows), sizeof(int));
   file.write( reinterpret_cast <char *> (&num_cols), sizeof(int));
   file.write( id.c_str(), max_id_len);
   file.write( reinterpret_cast <char *> (&mptr[0]), num_rows*num_cols*sizeof(T));
   
   if(debug) {trace_message(72);}   
   set_debug_on();
   return; 
 }
  
template < class T >
void matrix<T> :: read_from_file( fstream & file)
 {
   set_debug_on();
   if(debug) {trace_message(73);}
   
   file.read( reinterpret_cast <char *> (&num_rows), sizeof(int));
   if(file.eof()) return;
   file.read( reinterpret_cast <char *> (&num_cols), sizeof(int));
   char temp_id[80];
   file.read( temp_id, max_id_len); id = temp_id;
   create( id, num_rows, num_cols );
   file.read( reinterpret_cast <char *> (&mptr[0]), num_rows*num_cols*sizeof(T));

   if(debug) {trace_message(74);}   
   set_debug_on(); 
   return; 
 }   

 
template < class T >
void matrix <T> :: print(void)
{
   set_debug_on();
   if(debug) {trace_message(75);}
  
   cout << "Matrix id:" << id << endl;
   cout << "No rows, columns: " << get_num_rows(); 
   cout <<"  "<< get_num_cols() << endl;
   cout << "Matrix values:\n";
   for( int i=1; i<=num_rows; i++)
      {
	    for(int j=1; j<=num_cols; j++)
           {
	         cout<<setw(13)<<setiosflags(ios::fixed);
		     cout<< setprecision(3)<<(*this)(i,j);
           } 
	    cout << endl;
       }
	   
	if(debug) {trace_message(76);}
    set_debug_on();	
   return;
}

template < class T >
void matrix<T> :: set_debug_on(void) 
{
   debug = true;
   return;	
}
 
 
template < class T >
void matrix<T> :: set_debug_off(void) 
{
   debug = false;
   return;	
}


//***************************************************************************
//
//               matrix class:  equals
//
//***************************************************************************
//
//
template <class T>
bool matrix <T> :: equals( matrix<T>& a )
{
//
// Local variables
//
   set_debug_on();
   if(debug) {trace_message(77);}
   bool use_dequals;
   int i,j;
   double epsilon;
//
   if( a.num_rows != num_rows || a.num_cols != num_cols ) error_mess(35);
//
//     Switch on datatype to detect doubles/floats.  If not, just blindly use ==
//
   if( typeid(T) == typeid(double) )
     {
      use_dequals = false;
      epsilon = (double) DEPSILON;
     }
   else if( typeid(T) == typeid(float) )
     {
      use_dequals = false;
      epsilon = (double) FEPSILON;
     }
   else
     {
      use_dequals = true;
     }
//
//       Now either compare with floating point or with ==
//
   if( use_dequals )
     {
      for (i=1; i<= num_rows; i++)
        for (j=1; j<=num_cols; j++)
          if ( (*this)(i,j) != a.get_value(i,j) ) return false;
     }
   else
     {
      for (i=1; i<=num_rows; i++)
        for (j=1; j<=num_cols; j++)
        if ( (double) fabs((*this)(i,j)-a.get_value(i,j)) > epsilon) return false;
     }
//
   if(debug) {trace_message(78);}
   set_debug_on();
   return true;
}


//***************************************************************************
//
//               matrix class:  nequals
//
//***************************************************************************
//
//
template <class T>
bool matrix <T> :: nequals( matrix<T>& a)
{
   set_debug_on();
   if(debug) {trace_message(79);}
   
   return !( (*this).equals(a) );
}

//***************************************************************************
//
//               matrix class:  operator==
//
//***************************************************************************
//
//
template <class T>
bool matrix<T> :: operator==(matrix<T>&b)
{
   set_debug_on();
   if(debug) {trace_message(80);}
  
   return (*this).equals(b);
}

//***************************************************************************
//
//               matrix class:  operator!=
//
//***************************************************************************
//
//
template <class T>
bool matrix<T> :: operator!=(matrix<T>&b)
{
   set_debug_on();
   if(debug) {trace_message(81);}
   
   return (*this).nequals(b);
}

template class matrix <int>;
template class matrix <float>;
template class matrix <double>;



