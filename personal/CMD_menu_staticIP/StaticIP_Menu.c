#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void activateIP(int digit){
    char command[100];
    sprintf(command, "netsh interface ipv4 set address name=\"Ethernet\" static 10.10.10.%d 255.0.0.0", digit);
    system("netsh advfirewall set allprofiles state off"); //win firewall gone
    system(command);
}

void deactivateIP(int digit2){
    char command2[100];
    sprintf(command2, "netsh interface ipv4 delete address \"Ethernet\" addr=10.10.10.%d", digit2);
    system("netsh advfirewall set allprofiles state on"); // win firewall back on
    system(command2); //deletes old address
    //right here should connect to other again (if not = issue)
    system("netsh interface ipv4 set address name=\"Ethernet\" source=dhcp");
    system("netsh interface ipv4 set address name=\"Ethernet\" dhcp");
}


int main(int argc, char const *argv[]){
    system("cls");
    printf("\n NOTICE: This Code needs to be run with Admin rights and also is only made for Windows\n");
    printf("\n Choose last digit of IP: ");
    int digit = 0;
    scanf("%d", &digit);

    int loop = 0;
    while(loop==0){
        system("cls");
        printf("\n----\n [1] Activate StaticIP\n [2] Deactivate StaticIP\n [else] Quit\n\n: ");
        int choiche = 0;
        scanf("%d", &choiche);

        if(choiche==1){ //activate
            activateIP(digit);
        }else if(choiche==2){ //deactivate
            deactivateIP(digit);
        }else{
            loop = 1;
        }
    }
    return 0;
}