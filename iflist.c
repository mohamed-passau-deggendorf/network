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
	inet_ntop(AF_INET, &( (struct sockaddr_in *)ifa->ifa_ifu.ifu_broadaddr)->sin_addr, brks, sizeof(brks));


	printf("%s %x %s %s  %02x:%02x:%02x:%02x:%02x:%02x (%d) \n",
		ifa->ifa_name, ifa->ifa_flags,
		inet_ntop(AF_INET, &( (struct sockaddr_in *)ifa->ifa_addr)->sin_addr, ip, sizeof(ip)),
		inet_ntop(AF_INET, &( (struct sockaddr_in *)ifa->ifa_netmask)->sin_addr, mask, sizeof(mask)),
		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5] );	

		close(mac_fd);


	


}






}
