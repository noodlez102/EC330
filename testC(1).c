#include <stdio.h>
// SOLUTION FILE

main()
{
  int var_int;                    // 2

  unsigned char uchar1, uchar2;   // 3
  signed char schar1, schar2;

  int x, y;                       // 4

  char i;                         // 5
  char shift_char;

  int a[10] = {0,10,20,30,40,50,60,70,80,90};    // 6

  int b[10], c[10];               // 7
  int *ip, *ip2;
  int j, k;

  char AString[] = "HAL";           // 8

  // 1 -- change "World" to your name
  printf("\n\n PART 1 ---------\n");

  printf("\n Hello Arthur! \n");

  // 2 -- find sizes of the other C datatypes
  printf("\n\n PART 2 ----------\n");

  printf("\n size of data type int = %d ", sizeof(var_int));
  printf("\n size of data type unsigned char = %d ", sizeof(uchar1));
  printf("\n size of data type signed char = %d ", sizeof(schar1));
  printf("\n size of data type char = %d ", sizeof(i));

  // 3 -- explore signed versus unsigned datatypes and their interactions
  printf("\n\n PART 3 ----------\n");

  uchar1 = 0xFF;
  uchar2 = 0xFE;
  schar1 = 0xFF;
  schar2 = 0xFE;

  printf("\n uchar1 = %d ", uchar1);
  printf("\n schar1 = %d ", schar1);
  printf("\n They have different outputs even though they have the same set value is because they are different data types.");
  if(uchar1>uchar2){
    printf("\n uchar1 is bigger at %d",uchar1);
  }else{
    printf("\n uchar2 is bigger at %d",uchar2);
  }
  if(schar1>schar2){
    printf("\n schar1 is bigger at %d",schar1);
  }else{
    printf("\n schar2 is bigger at %d",schar2);
  }

  if(uchar1>schar2){
    printf("\n uchar1 is bigger at %d",uchar1);
  }else{
    printf("\n schar2 is bigger at %d",schar2);
  }
  printf("\n schar1 + schar2 is  %d",schar2+schar1);
  printf("\n uchar1 + uchar2 is  %d",uchar1+uchar2);



  // 4 -- Booleans
  printf("\n\n PART 4 ----------\n");

  x = 1; y = 2;
  int truevar = x&&y;
  int falsevar = x&y;//this shows the difference between & and &&
  printf("\n boolean value for true is %d",truevar);
  printf("\n boolean value for true is %d",falsevar);
  printf("\n size of a boolean false is %d",sizeof(falsevar));
  printf("\n ~1 is %d",~x);
  printf("\n !1 is %d",!x);


  




  // 5 -- shifts
  printf("\n\n PART 5 ----------\n");

  shift_char = 15;
  i = 7;

  printf("\n shift_char << %d = %d", i, shift_char << i);
  printf("\n shift_char >> %d = %d", i, shift_char >> i);
  printf("\n it gets multiplied by 2 each time you increase the increment by 1. This makes sense because if you ad one 0 to the left side of the value in 4 bit it is basically like having the number again ");
  //ion get this shit ngl it literaly is just increasing it by 2 for every char shift
  // HINT: If you cannot observe any "interesting" results using the above statement,
  // try assigning the shifted value to a different variable and then printing the new 
  // variable.


  // 6 -- pointer basics
  printf("\n\n PART 6 ----------\n");

  ip = a;
  printf("\nstart %d %d %d %d %d %d %d \n",
	 a[0], *(ip), *(ip+1), *ip++, *ip, *(ip+3), *(ip-1));//did it and it worked and did the 2nd part
  printf("\nstart again %d ", a[1]);
  printf("%d ", *(ip));
  printf("%d ", *(ip+1));
  printf("%d ", *ip++);
  printf("%d ", *ip);
  printf("%d ", *(ip+3));
  printf("%d ", *(ip-1));
  printf("\n this is the size of an integer pointer type %d", sizeof(ip));
  printf("\n this is the value of an integer pointer %x", ip);
  printf("\n this is the value of an integer pointer %x", ip+1);
  printf("\n The reason the difference between ip and ip+1 isn't just a value of 1 is because since the addresses in in hex, so the +1 is actually 4");









  // 7 -- programming with pointers
  printf("\n\n PART 7 ----------\n");

  int index_for_loop= sizeof(a)/4;
  int index_smaller=index_for_loop-1;
  for(int i = 0; i< index_for_loop; i++){
    b[i]=a[index_smaller];
    index_smaller--;
  }
  printf("\n this is with conventional indicies \n");

  for(int loop = 0; loop < 10; loop++)
      printf("%d ", b[loop]);

  ip = a+ index_for_loop -1;
  ip2= c;
  for(int i = 0; i< index_for_loop; i++){
      *ip2 =*ip;
      *ip--;
      *ip2++;
    }
  printf("\n this is with pointers \n");
  for(int loop = 0; loop < 10; loop++)
      printf("%d ", c[loop]);



  // 8 -- strings
  printf("\n\n PART 8 ----------\n");

  printf("\n %s \n", AString);

  int AStringsize = sizeof(AString)-1;
  for(int loop = 0; loop < AStringsize+1; loop++)
      printf("%d ", AString[loop]);

  printf("\n the value after the last character is 0 because that's the stop character that says the string is done\n");
  for(int loop = 0; loop < AStringsize; loop++)
    AString[loop]= AString[loop]+1;
  for(int loop = 0; loop < AStringsize+1; loop++)
    printf("%c", AString[loop]);
  
  AString[3]= AString[3]+60;
  printf("\n");
  for(int loop = 0; loop < AStringsize+1; loop++)
    printf("%c", AString[loop]);
  printf("\n It prints the character < because that is the character associated with ascii 60");

  // 9 -- address calculation
  printf("\n\n PART 9 ----------\n");
  for (k = 0; k < 10; k++){
    b[k] = a[k];         // direct reference to array element
    printf("%p",a);
  }
  ip = a;
  ip2 = b;
  printf("\n");
  for (k = 0; k < 10; k++){
    *ip2++ = *ip++;
    printf("%p",ip);
   }  // indirect reference to array element

  //10 -- 2d arrays
  printf("\n\n PART 10 ----------\n");

  int array2d[10][10] ={{0}};
  array2d[9][9] = 1;

  printf("empty 2d array non-transposed\n");
  for(int i =0; i<10;i++){
    for(int j=0; j<10;j++){
      printf("%d ", array2d[i][j]);
    }
    printf("\n");
  }
  printf("Transposed array with 1 at 10 10\n");
  
  for(int i =9; i>0;i--){
    for(int j=9; j>=0;j--){
      printf("%d ", array2d[i][j]);
    }
    printf("\n");
  }

  // all done
  printf("\n\n ALL DONE\n");
}
