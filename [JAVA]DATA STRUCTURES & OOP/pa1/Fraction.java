// Name : Gawun Kim
// CSE223 Spring 2018 by "Nick Macias"
// Date : 20/Apil/2018 
// Program assignment 1
// Description : Simply explaining this program is about one part of calculating system. Mainly, there are these following main functions : add, subtract, multiple, and divide. 
// The base of this calculating is operated by numerator and denominator; this format will be in simplest form by using "reduce" function and
//                       ex) 2/1 -> 2   6/3 -> 2
// "GCF" function. Also, when some number can be expressed by integer from num/denom, the output converted integer format. Also, it can simplify the format of location of sign(-). For example,  5/(-3)  -> - 5/3.
// In case of invalid format, the error would be shown ex) 1/0 -> NaN

class Fraction
{
   private int numerator;		// All this program base is numerator and denominator
   private int denominator;

///////////////////////////////////////////////////Constructors///////////////////////////////////////////////////////////////////////////////////
	public Fraction(int num, int denom) // This is creating new number whose value is num/denom
	{
		numerator = num;
		denominator = denom;
		reduce();		// make the number with the simplest format
	}

	public Fraction(int num)  // This is creating new number whose value is num / 1; it means just integer
	{
		numerator = num;
		denominator = 1;
		reduce();		// make the number with the simplest format
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        public int getNum()		// this takes numerator from some value and return nom
        {
        	return numerator;
        }

        public int getDenom()		// This takes denominator from some value and return denom
        {
        	return denominator;
        }
//////////////////////////////////////////////(Mainly used?? functions)///////////////////////////////////////////////////////////////////////////

// Global direction : /sub(Fraction n)/  c.sub(d)  getDenom/getNum is for 'c'   and   n.getDenom/n.getNum is for 'd'

	public Fraction add(Fraction n)  // This is add 
	{				 
		if(getDenom() == 0)	return new Fraction(1,0); // it will return an undefined fraction back 
		if(n.getDenom() == 0)	return new Fraction(1,0); // it will return an undefined fraction back

	   int denominator = getDenom() * n.getDenom();                                 // This is for...
	   int numerator = ( getNum() * n.getDenom() ) + ( n.getNum() * getDenom() );   // a/b + c/d = (ad+bc)/bd

	   return new Fraction (numerator , denominator);
	}

	public Fraction sub(Fraction n) // This is subtract from some value to other value
	{
		 if(getDenom() == 0)	return new Fraction(1,0); // it will return an undefined fraction back
		 if(n.getDenom() == 0)	return new Fraction(1,0); // it will return an undefined fraction back

  	   int denominator = getDenom() * n.getDenom();
	   int numberator = ( -getDenom() * n.getNum() ) + ( n.getDenom() * getNum() );// a/b-c/d = (ad-bc)/bd

	   return new Fraction (numberator , denominator);
	}

	public Fraction mul(Fraction n) // This is multiple some number with other value
	{
        	if(getDenom() == 0)    return new Fraction(1,0); // it will return an undefined fraction back
        	if(n.getDenom() == 0)  return new Fraction(1,0); // it will return an undefined fraction back

	   int denominator = getDenom() * n.getDenom();        // (a/b)*(c/d) = ac/bd
	   int numerator = getNum() * n.getNum();

	   return new Fraction (numerator , denominator);
	}

	public Fraction div(Fraction n) // This is division
	{
        	if(getDenom() == 0)    return new Fraction(1,0); // it will return an undefined fraction back
        	if(n.getDenom() == 0)  return new Fraction(1,0); // it will return an undefined fraction back

	   int denominator = getDenom() * n.getNum();		// (a/b)/(c/d) = ad/bc
	   int numerator = getNum() * n.getDenom();

	   return new Fraction (numerator , denominator);
	}

	public double toDouble()  // This is returning doulbe -presision floating point number
	{
		if (((double)denominator) == 0)  return Double.NaN;	//returns NaN or undifined if the denominator is 0
	   return(((double)numerator)/((double)denominator));
	
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public String toString()
	{
		if (denominator == 0) // if denom is zero, then it will return NaN
		{
		  return "NaN";
		}

		else if (denominator == 1)	// if denom is just one, then it will return only num and it is just integer
		{
		  return (Integer.toString(numerator));
		}

		else if (denominator < 1) // if denom is negative number, this function is changing the format by multiply -1 in denom and num. 
						// example  4/-3   -> -4/3
		{
		  return (Integer.toString(numerator * -1) + "/" + (Integer.toString(denominator * -1)));
		}

		else{				// it is just regular format 
	  	  return (Integer.toString(numerator) + "/" + Integer.toString(denominator)); 
		}
	}
	
	private void reduce()  // This funtion make the value with the simplest format
	{
		int GCF = GCF(numerator, denominator);
		if(GCF == 0) return;
	
		this.numerator = numerator/GCF;
		this.denominator = denominator/GCF;
	}
	private int GCF(int num, int denom)   // This is for "reduce" function and the key to make the simplest value format
	{
		if (denom == 0) return num;	//it will keep doing until (num%denom) or denom is zero
	         return GCF(denom, num%denom);  // it is recursive and it will keep operating and make the simplest one.	
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
