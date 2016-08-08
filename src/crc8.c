#include <stdio.h>

/*
 * calculate a CRC8 
 */
 
int main(int argc, char* argv[])
{
     int i, j;
     const unsigned char generator = 0x07;
     int crc_size = 8;
     const unsigned char* bytes = (const unsigned char*)argv[1];
     unsigned char crc = 0; /* start with 0 so first byte can be 'xored' in */
     if (argc < 2)
     {
         printf("error\n");
         return -1;
     }

     for(j=0; bytes[j] != '\0'; ++j)
     {
         crc ^= bytes[j]; /* XOR-in the next input byte */

         for (i = 0; i < 8; i++)
         {
             if ((crc >> (crc_size - 1)) != 0)
             {
                 crc = (unsigned char)((crc << 1) ^ generator);
             }
             else
             {
                 crc <<= 1;
             }
         }
     }
     printf("%02X\n", crc);
     return 0;
}
