#include<stdlib.h>
//how it works: turn off windows firewall, and set a static ip
//change ip and address name depending on PC
int main(){
    system("netsh advfirewall set allprofiles state off"); //win firewall gone
    system("netsh interface ipv4 set address name=\"Ethernet\" static 10.10.10.3 255.0.0.0");
    return 0;
}
