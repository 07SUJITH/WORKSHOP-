#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
f

int main(void){
	char *path ,path1[10];
	struct stat *nfile;
	nfile= (struct stat *)malloc(sizeof(struct stat));
	printf("Enter the name of the file : ");
	scanf("%s",path1);
	stat(path1,nfile);
	
	printf("user id: %d \n",nfile->st_uid);
	printf("bloch_size :%ld \n",nfile->st_blksize);
	printf("last acsess time : %ld \n",nfile->st_atime);
	printf("last modification :%ld \n",nfile->st_atime);
	printf("production mode :%d \n",nfile->st_mode);
	printf("size of the file : %ld \n",nfile->st_size);
	printf("number of links :%ld \n",nfile->st_nlink);
	
}
