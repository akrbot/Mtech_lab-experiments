#include<stdio.h>
int main(){
    int fighter,bomber,bmbrs_to_snd;
    int total_pilots = 204-10;
    scanf("%d %d",&fighter,&bomber);
    //if no: of fighter less than or equal to 12 or bomers less than 0 cant sent any bmbers
    if (fighter<=12 || bomber <= 0){
        bmbrs_to_snd = 0;
    }
    //fighter > 12
    else{
        //10 fighter should stay back remainig is available
        int avl_fighter = fighter - 10;
        //for every bomber 3 fighter accompanied 
        bmbrs_to_snd = avl_fighter/3;
        // if bmb to send is more thn availble bmbers only available bmbers can be sent
        if (bmbrs_to_snd > bomber){
            bmbrs_to_snd = bomber;
        }
        //if fighter + bmbrs that can br sent greater than available piolts
        if (bmbrs_to_snd*3 + bmbrs_to_snd>total_pilots){
            bmbrs_to_snd = total_pilots/4;
        }
        
        
    }
    printf("%d",bmbrs_to_snd);
    return 0;
}