#include<stdlib.h>
//how this works: turn on windows firewall and set ip to auto
//change ip and address name depending on PC
int main(){
    system("netsh advfirewall set allprofiles state on"); // win firewall back on
    system("netsh interface ipv4 delete address \"Ethernet\" addr=10.10.10.3"); //deletes old address
    //right here should connect to other again (if not = issue)
    system("netsh interface ipv4 set address name=\"Ethernet\" source=dhcp");
    system("netsh interface ipv4 set address name=\"Ethernet\" dhcp");
    return 0;
}
