#include <stdio.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>


int main(int argc,char*argv[]) {

struct ifaddrs *ifaddr, *ifa;
getifaddrs(&ifaddr);
for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)   if (ifa->ifa_addr->sa_family == AF_INET) {

 
	 char ip[INET_ADDRSTRLEN];
	char mask[INET_ADDRSTRLEN];
	char brks[INET_ADDRSTRLEN];
	int mac_fd = socket(AF_INET, SOCK_DGRAM, 0); 
	struct ifreq ifr;
        strncpy(ifr.ifr_name, ifa->ifa_name, IFNAMSIZ-1);
	ioctl(mac_fd, SIOCGIFHWADDR, &ifr);
	unsigned char *mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
	ioctl(mac_fd, SIOCGIFHWADDR, &ifr);
	char arp_hw[256];
	void* threading_hw[1004];

	threading_hw[ARPHRD_ETHER] = &&ether_threading;
	threading_hw[ARPHRD_IEEE80211] = &&iee81211_threading;
	threading_hw[ARPHRD_LOOPBACK] = &&loopback_threading;

	goto *(threading_hw[ifr.ifr_hwaddr.sa_family]);
	ether_threading : strcpy(arp_hw,"Ethernet"); goto end_threading;
	iee81211_threading :  strcpy(arp_hw,"Wireless"); goto end_threading;
	loopback_threading :   strcpy(arp_hw,"Loopback"); end_threading: ;

	inet_ntop(AF_INET, &( (struct sockaddr_in *)ifa->ifa_ifu.ifu_broadaddr)->sin_addr, brks, sizeof(brks));


	printf("%s %x %s %s  %02x:%02x:%02x:%02x:%02x:%02x %s  \n",
		ifa->ifa_name, ifa->ifa_flags,
		inet_ntop(AF_INET, &( (struct sockaddr_in *)ifa->ifa_addr)->sin_addr, ip, sizeof(ip)),
		inet_ntop(AF_INET, &( (struct sockaddr_in *)ifa->ifa_netmask)->sin_addr, mask, sizeof(mask)),
		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5] , arp_hw );	

		close(mac_fd);


	


}






}
