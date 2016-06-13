//
//  main.c
//  thread
//
//  Created by Devin Liu on 16/6/13.
//  Copyright © 2016年 DanielLiu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <windows.h>
//#include <iostream>

int  piao = 100;
pthread_mutex_t mut;

void* tprocess1(void* args){
     int a = 0;
          while(1){
                 pthread_mutex_lock(&mut);
                if(piao>0){
                      //Sleep(1);
                      piao--;
                       printf("窗口1----------------还剩%d张票\n",piao);
                  }else{
                          a = 1;
                          }
                  pthread_mutex_unlock(&mut);
                 if(a == 1) {
                        break;
        }
    }
    return NULL;
}

          //return(NULL);
void* tprocess2(void* args){
         int a = 0;
          while(1){
                  pthread_mutex_lock(&mut);
                   if(piao>0){
                        //Sleep(1);
                       piao--;
                    printf("窗口2----------------还剩%d张票\n",piao);
                       }else{
                          a = 1;
                          }
                  pthread_mutex_unlock(&mut);
                   if(a == 1) {
                       break;
                      }
    }

   return NULL;
}

int main(){
      pthread_mutex_init(&mut,NULL);
      pthread_t t1;
      pthread_t t2;

 
     pthread_create(&t1,NULL,tprocess1,NULL);
     pthread_create(&t2,NULL,tprocess2,NULL);
    //Sleep(5000);
      return 0;
}
