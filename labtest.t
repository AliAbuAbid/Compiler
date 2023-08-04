function f3(arg-> a1:real):real
{
   var  b1:real;
   b1=2.89;
   if(b1!=a1) 
         b1=a1*2;
   else 
         b1=a1/3;
    return b1;
}


function main() :void
{
   var y: real;
   var x:real;
   x=3.07;
   while(x <88) 
   {
        y = f3( x);
        x = x +15.88;
   }
}
