
  
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
    //ls only dir
    /*
   DIR *dr;
   struct dirent *en;
   dr = opendir("/home/sabrina-kichukova");
   if (dr == NULL) {
       perror("error:");
       return EXIT_FAILURE;
   }
   while ((en = readdir(dr)) != NULL) {
       if (en->d_type == DT_DIR && en->d_name[0] != '.'){
         printf("%s\n", en->d_name);
       }
   }
   closedir(dr);
*/
// only fails without hidden files
/*
   DIR *dr;
   struct dirent *en;
   dr = opendir("/home/sabrina-kichukova");
   if (dr == NULL) {
       perror("error:");
       return EXIT_FAILURE;
   }
   while ((en = readdir(dr)) != NULL) {
       if (en->d_type == DT_REG && en->d_name[0] != '.'){
         printf("%s\n", en->d_name);
       }
   }
   closedir(dr);
*/
//with hiden files
DIR *dr;
   struct dirent *en;
   dr = opendir("/home/sabrina-kichukova");
   if (dr == NULL) {
       perror("error:");
       return EXIT_FAILURE;
   }
   while ((en = readdir(dr)) != NULL) {
       if (en->d_type == DT_REG && en->d_name[0]){
         printf("%s\n", en->d_name);
       }
   }
   closedir(dr);

   return EXIT_SUCCESS;
}
