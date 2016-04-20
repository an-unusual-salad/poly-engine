#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <linux/if.h>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <linux/socket.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/if_ether.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>

int setup_interface(char *device)
{
  int fd;
  struct ifreq ifr;
  int s;

  fd=socket(AF_INET, SOCK_PACKET, htons(ETH_P_ALL));
  if(fd < 0)
  {
    perror("cant get SOCK_PACKET socket");
    exit(0);
  }

  strcpy(ifr.ifr_name, device);
  s=ioctl(fd, SIOCGIFFLAGS, &ifr);
  if(s < 0)
  {
    close(fd);
    perror("cant get flags");
    exit(0);
  }

  ifr.ifr_flags |= IFF_PROMISC;
  s=ioctl(fd, SIOCSIFFLAGS, &ifr);
  if(s < 0) perror("cant set promiscuous mode");
  return fd;
}

int main(int argc, char *argv[])
{
  int sock;
  int port_dest=0;
  char paquet[4096];
  struct tcphdr *tcp;
  struct iphdr *ip;
  unsigned char *data;
  int i=0,j=0;
  int datasize;

  ip=(struct iphdr *)(paquet + sizeof(struct ethhdr));
  tcp=(struct tcphdr *)(paquet + sizeof(struct ethhdr) 
			       + sizeof(struct iphdr));
  data=(unsigned char *)(paquet+sizeof(struct ethhdr)+sizeof(struct iphdr)
			       +sizeof(struct tcphdr)+12);

  sock = setup_interface(argv[1]);
  

  while(1)
  { 
    read(sock,(char *)&paquet, 4096);
    port_dest=ntohs(tcp->dest);

    if (port_dest==25) 
    {
      datasize = ntohs(ip->tot_len) -sizeof(struct iphdr)
	                            -sizeof(struct tcphdr)-12;
      if (datasize>0)
      {
	for (j=0;j<datasize;j++)
	{
	  fprintf(stderr,"%c",data[j]);
	}
      }
    }

  }

  close(sock);
}
