#include <stdio.h>
#include <stdlib.h>

unsigned int my_random (unsigned int, unsigned int);

unsigned int my_random (unsigned int min, unsigned int max)
{
  /* Take care, max isn't reached ! */
  unsigned int my_rand,yoda;
  FILE *random_device;
  
  //Opening the /dev/random device.
  random_device=fopen( "/dev/urandom" , "r");
  
  //Reading an int.
  fgets((char *)&my_rand , sizeof(unsigned int), random_device);
  yoda = my_rand << 16;
  fgets((char *)&my_rand , sizeof(unsigned int), random_device);
  yoda = min + ((yoda + my_rand) % (max-min));
  
  //Closing the device.
  fclose(random_device);
  
  
  return (yoda);
}
