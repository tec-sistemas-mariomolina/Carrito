
#include <iostream>
#include <Windows.h>
#include <NuiApi.h> 
#include<iostream>
#include "SerialClass.h"
#include<stdlib.h>
using namespace std;

int main()

{
	int MaxV=5;
	int PWM=255;
	int  nPWM;
	float D;
	int indice=0;
	char lectura[50] = "\0";
	char start[]="start";
	char A;
	Serial* Puerto = new Serial("\\COM5");
	
	int n = NULL;
	if(Puerto->IsConnected())
		 {
		
			Puerto->WriteData(start, sizeof(start));
		  }
      

   NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
   NUI_SKELETON_FRAME ourframe;
    
   while (1)
   { 
	   NuiSkeletonGetNextFrame(0, &ourframe);
    
     for (int i = 0; i < 6; i++)
	 {
		 if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
			 indice=i; 
		}	
	 }
	 
       if (ourframe.SkeletonData != NULL && ourframe.SkeletonData[indice].eTrackingState == NUI_SKELETON_TRACKED)
	   {
         cout << "Y:" <<ourframe.SkeletonData[indice].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y << endl;
		 SetConsoleTitle("Control Led Arduino - Visual Studio C++ 2017");
		 cout << "Z:" <<ourframe.SkeletonData[indice].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z << endl;

		 D = ourframe.SkeletonData[indice].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z;
		 if(D>1.3){
		 nPWM=(PWM*(D)/MaxV)+20;
		 
		 if(nPWM <= 0){
			 nPWM = 0;
			 A = NULL;
		 }else{
			 if(nPWM > 255){
				nPWM = 255;
			 }
			 A = (char)nPWM;
		 }
		 }else{
			nPWM = 0;
		 }
		 

		 cout<< "NUEVO PWM  = "<<nPWM<<endl;
		 cout<< "VALOR DE DISTANCIA "<<D<<endl;
		 
		 
		 cout<<"INT : "<<(int)A<<" CHAR: "<<A<<endl;

		 if(Puerto->IsConnected())
		 {
			cout<<"Enviando el valor --> : "<<(unsigned int)A<<endl;
			if(nPWM == 0)
				A = NULL;
			Puerto->WriteData(&A, sizeof(char));
		  }
	   }
	   else{
		   
		   char E= NULL;
		   Puerto->WriteData(&E, sizeof(char));
	   }
         n = Puerto->ReadData(&A, 1);
        if (n > 0)
        {
			lectura[n +1] = '\0'; 
            cout << "Recibido: " << n<<"-->"<<A << endl;
            cout << "-------------------" << endl;
		}
		
     system("cls");
   }
  
   }

